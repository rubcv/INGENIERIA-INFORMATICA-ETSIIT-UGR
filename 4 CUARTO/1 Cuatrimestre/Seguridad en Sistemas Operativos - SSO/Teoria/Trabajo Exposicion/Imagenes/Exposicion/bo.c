#include <stdio.h>
#include <string.h>

void func(char* arg){
	
	char nombre[32];
	
	strcpy(nombre, arg);
}

int main(int argc, char** argv){

	func(argv[1]);

}


