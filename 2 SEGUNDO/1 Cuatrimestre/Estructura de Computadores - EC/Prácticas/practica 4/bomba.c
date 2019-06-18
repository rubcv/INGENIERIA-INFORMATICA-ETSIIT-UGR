#include <stdio.h>	// para printf()
#include <stdlib.h>	// para exit()
#include <string.h>	// para strncmp()/strlen()
#include <sys/time.h>	// para gettimeofday(), struct timeval

#define SIZE 5
#define TLIM 60

char password[] = "hpnd\n";
int  passcode  = 78910;

void boom(){
	printf("***************\n");
	printf("*** BOOM!!! ***\n");
	printf("***************\n");
	exit(-1);
}

void defused(){
	printf("*************************\n");
	printf("*** bomba desactivada ***\n");
	printf("*************************\n");
	exit(0);
}


int comparechar(char* una, char* otra){
	for(int i = 0; i < SIZE; i++){
		if(una[i] != otra[i]){
			return 0;
		}
	}
	return 1;
}


int main(){
	char pass[SIZE];
	char orig [SIZE];
	int  pasv;
	struct timeval tv1,tv2;	// gettimeofday() secs-usecs

	gettimeofday(&tv1,NULL);

	printf("Introduce la contraseña: ");
	fgets(pass,SIZE,stdin);

	for(int i = 0; i < SIZE -1; i++){
		pass[i] = (char)(pass[i] + i);
	}

	if (comparechar(pass, password))
	    boom();

	gettimeofday(&tv2,NULL);
	if (tv2.tv_sec - tv1.tv_sec > TLIM)
	    boom();

	printf("Introduce el código: ");
		scanf("%i",&pasv);

	if (pasv != passcode) boom();

	gettimeofday(&tv1,NULL);
	if (tv1.tv_sec - tv2.tv_sec > TLIM)
	    boom();

	defused();

}
