#include <string.h>
#include <stdlib.h>

void func(char * arg){
	
	char nombre[32];
	strcpy(nombre, arg);
}


int main(int argc, char** argv){

	if(argc != 2){
		exit(0);
	}
		
	func(argv[1]);

}




