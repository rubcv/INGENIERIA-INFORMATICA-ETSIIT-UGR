/* 
 * fflush example code
 * http://code-reference.com/c/stdio.h/fflush 
 */
 
#include <stdio.h> /* including standard library */
//#include <windows.h> /* uncomment this for Windows */
 #include <iostream>
#define MAX 80
int main( void )
{
  FILE *filestream = fopen("test.txt", "rt+");
  char buffer[MAX];
  if (filestream)
  {
    fputs("write this in a file", filestream);
    fflush(filestream); /* uncomment this function to see what's happend */
    fgets(buffer, MAX, filestream);
    puts(buffer);
    fclose(filestream);
  }
  
  
  system ("pause");
  return 0;
}
