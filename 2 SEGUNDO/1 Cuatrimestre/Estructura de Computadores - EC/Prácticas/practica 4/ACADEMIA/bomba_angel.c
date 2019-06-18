#include <stdio.h>	// para printf()
#include <stdlib.h>	// para exit()
#include <string.h>	// para strncmp()/strlen()
#include <sys/time.h>	// para gettimeofday(), struct timeval

char password[]="UmpaLumpa\n";
int  passcode  = 1993;

void boom(){
	printf("***************\n");
	printf("*** BOOM!!! ***\n");
	printf("***************\n");
	exit(-1);
}

void defused(){
	printf("·························\n");
	printf("··· bomba desactivada ···\n");
	printf("·························\n");
	exit(0);
}

//rot13
char* rot(char *p)
{
    size_t i;
    char c;
	

    for (i = 0; p[i] != '\0'; ++i) {
        switch (p[i]) {
            case 'A' ... 'Z':
                c = 'A'; //Escoge el abecedario de mayúsculas.
                break;
            case 'a' ... 'z':
                c = 'a'; //Escoge el abecedario de minúsculas.
                break;
            default:
                continue;
        }

        /*  p[i] - c               : Consigue indice en el abecedario.  Ej: A->0,  Z->25, N->13
         *  p[i] - c + 13          : Mueve el indice 13 posiciones.     Ej: A->13, Z->38, N->26
         * (p[i] - c + 13) % 26    : Rota las posiciones.               Ej: A->13, Z->12, N->0
         * (p[i] - c + 13) % 26 + c: Convierte el indice al abecedario. Ej: A->N,  Z->M,  N->A
         */

        c = (p[i] - c + 13) % 26 + c;
        p[i] = c;
    }

    return p;
}



int main(){
#define SIZE 100
	char passw[SIZE];
	char passw1[SIZE];
	int pasv;
	int control=0;
#define TLIM 60
	struct timeval tv1,tv2;	// gettimeofday() secs-usecs

	gettimeofday(&tv1,NULL);
	rot(password);//Le hacemos la encriptacion a la contrasenia original
	printf("Introduce la contraseña: ");
	fgets(passw,SIZE,stdin);	
	rot(passw);//Le hacemos la encriptacion artesanal ROT13 a la cadena del ususario;
	
	if (strncmp(passw,password,strlen(password)))
		boom();

	gettimeofday(&tv2,NULL);
	if (tv2.tv_sec - tv1.tv_sec > TLIM)
		boom();

	printf("Introduce el código: ");
	scanf("%i",&pasv);
		
	//trampa
	pasv = pasv ^ 1;//Lo ponemos a $0 una de las variables 
	//(El truco es hacerle el or entre la variable y $0 (cero) para que salga el valor que buscamos)

	if (pasv!=passcode) boom();
		gettimeofday(&tv1,NULL);

	if (tv1.tv_sec - tv2.tv_sec > TLIM)
		boom();
		
	if(control==0)//Troleo padre	
		defused();
}

