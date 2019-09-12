/* *************************************************************************
File:				solvenet.c
Author:			Xavier Molero
Date:				November, 1999
Revision:   December, 2001
Revision2:  November, 2012 (UGR, UCO: any visit ratios -> Central Server Model not assumed)

Solves mono-class networks of queues, open and closed.
Parameters of the program: see command line

The code is not optimized: priority has been given to clarity.

The program does not make any error checking.

************************************************************************* */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define OPEN   0
#define CLOSED 1

#define Kmax 20

void Structures_initialization(void);
void Input_arguments(int argc, char *argv[]);
void Output_results(void);
void Validation_input_parameters(int, char* argv[]);

void Analysis_open_networks(void);
void Analysis_closed_networks(void);
void Analysis_asymptotic_limits(void);

long Network_type;

double V[Kmax];  /* Visit ration.                */
double S[Kmax];  /* Service time.                */
double D[Kmax];  /* Service demand.              */
double U[Kmax];  /* Utilization.                 */
double R[Kmax];  /* Response time.               */
double N[Kmax];  /* #jobs in the service station.*/
double Q[Kmax];  /* Waiting jobs                 */
double X[Kmax];  /* Throughput.                  */
double W[Kmax];  /* Waiting time.                */

double R0;       /* System responde time (R0).    		*/
double X0;       /* System throughtput (X0).      		*/
double N0;       /* Number of jobs in the system (N0) */

double Rm;       /* Minimum system response time. 		*/
double Xm;       /* Maximum system thoughput.     		*/

double Z;        /* Think time (closed interactive network).                   		*/

long K;          /* Number of service stations. 			*/
long NT;         /* Total number of jobs/users/terminals in a closed network      */

long   B[Kmax];  /* Bootleneck devices.            								*/
long   imax;     /* Index of the first bottleneck device found.   */
double Umax;     /* Maximum utilization.          								*/
long   Na;       /* Saturation theoretical point value (ceiling). */
double Na_float; /* Saturation theoretical point value.      			*/
int basic_output; 	 /* if =1 basic output: to be used by another program to extract multiple data from multiple executions */

/* Main Program */

int main(int argc, char *argv[])
{
    Structures_initialization();
	Input_arguments(argc,argv);
    switch (Network_type)
    {
        case OPEN:  Analysis_open_networks();
                      break;
        case CLOSED: Analysis_closed_networks();
                      break;
    }
    Analysis_asymptotic_limits();
    Output_results();
    return(0);
}


/* ************************************************************************* */

void Structures_initialization()
{
    long int i;

    Rm = 0.0;
    R0 = 0.0;
    X0 = 0.0;
    Xm = 0.0;
    N0 = 0.0;

    for (i=0;i<=Kmax;i++)
    {
        V[i] = 0.0;
        S[i] = 0.0;
        D[i] = 0.0;
        U[i] = 0.0;
        R[i] = 0.0;
        N[i] = 0.0;
        Q[i] = 0.0;
        X[i] = 0.0;
        B[i] = 0L;
    }
	basic_output=0;
}



void Input_arguments(int argc, char *argv[])
{

    long int i;

    Validation_input_parameters(argc,argv);

    if (atol(argv[1])==0) Network_type = OPEN;
    if (atol(argv[1])==1) Network_type = CLOSED;

    if (Network_type==CLOSED)
    {
        NT   = atol(argv[2]);
        Z    = atof(argv[3]);
        K    = atol(argv[4]);
        for (i=1;i<=K;i++)
        {
            S[i] = atof(argv[2*i+3]);
            V[i] = atof(argv[2*i+4]);
        }
		if (argc>2*K+4+1) basic_output=1; //more parameters than needed -> basic output
    }

    if (Network_type==OPEN)
    {
        X0   = atof(argv[2]);
        K    = atol(argv[3]);
        for (i=1;i<=K;i++)
        {
            S[i] = atof(argv[2*i+2]);
            V[i] = atof(argv[2*i+3]);
        }
		if (argc>2*K+3+1) basic_output=1; //more parameters than needed -> basic output
    }

}


void Validation_input_parameters(int argc, char *argv[])
{
    if ( (argc==1) ||
       ((atol(argv[1])!=0) && (atol(argv[1])!=1))  )

    {
        printf("\nANALISYS OF SIMPLE QUEUEING NETWORKS");
        printf("\nby Xavier Molero. Version 2.0");
        printf("\n************************************");
        printf("\nSolver for simple queueing networks");
        printf("\n");
        printf("\nUsage: solvenet");
        printf("\nUsage: solvenet [0|1] [lambda0| NT Z] K S1 V1...SK VK");
        printf("\n\tWith no parameters, shows this message");
        printf("\n\tnetwork: 0 (open) and 1 (closed)");
        printf("\n\tlambda0: arrival rate = throughput (equilibrium assumed)(only for open networks)");
        printf("\n\tNT:      total number of terminals/users/jobs in the network (only for closed networks)");
        printf("\n\tZ:       think time (only interactive closed networks)");
        printf("\n\tK:       number of service stations");
        printf("\n\tSi:      service time of device i");
        printf("\n\tVi:      ratio visit of device i");
        printf("\n");
        exit(0);
    }
}



void Analysis_open_networks()
{
    long int i;

    for (i=1;i<=K;i++)
    {
        D[i] = V[i] * S[i];
        U[i] = X0   * D[i];
        X[i] = X0   * V[i];
        R[i] = S[i] / (1.0 - U[i]);
        N[i] = U[i] / (1.0 - U[i]);
        Q[i] = N[i] - U[i];
        W[i] = R[i] - S[i];
    }

    for (i=1;i<=K;i++)
    {
        R0 = R0 + (R[i] * V[i]);
        N0 = N0 + N[i];
        Rm = Rm + D[i];
    }
}

void Analysis_closed_networks()
{
    long int n;
    long int i;

    for (i=1;i<=K;i++)
    {
        D[i] = S[i] * V[i];
        Rm = Rm + D[i];
    }

    for (n=1;n<=NT;n++)
    {
        for (i=1;i<=K;i++) R[i] = S[i] * (1.0 + N[i]);
        R0 = 0.0;
        for (i=1;i<=K;i++) R0 = R0 + (R[i] * V[i]);
        X0 = n / (Z + R0);
        N0 = X0 * R0;
        for (i=1;i<=K;i++)
        {
            N[i] = X0 * V[i] * R[i];
            X[i] = X0 * V[i];
            U[i] = X0 * V[i] * S[i];
            Q[i] = N[i] - U[i];
            W[i] = R[i] - S[i];
        }
    }

}

void Analysis_asymptotic_limits()
{
    long int i;

    Umax = 0.0;
    for (i=1;i<=K;i++)
     if (U[i]>=Umax)
     {
        Umax = U[i];
        imax = i;
     }

    for (i=1;i<=K;i++)
     if (U[i]==Umax) B[i] = 1;

    Xm = 1.0/D[imax];

    //if (Network_type==CLOSED) Na = (long) ceil((Rm+Z)/D[imax]);
    if (Network_type==CLOSED) Na_float = (Rm+Z)/D[imax];
}


void Output_results()
{
    long int i;
	if (basic_output==1)
	{
	  printf("\n%d\t%10.4f\t%10.4f\t%10.4f",(int)NT, N0, R0, X0);
	  return;
	}
    printf("\nANALISYS OF SIMPLE QUEUEING NETWORKS");
    printf("\nby Xavier Molero. Version 1.0");
    printf("\n************************************");
    printf("\n\n");


    if (Network_type==OPEN)
    {
        printf("\nQUEUEING NETWORK: OPEN");
        printf("\nOpen Queueing Network Analysis Algorithm");
    }
    if (Network_type==CLOSED)
    {
        printf("\nQUEUEING NETWORK: CLOSED");
        printf("\nMean Value Analysis Algorithm");
    }
    printf("\n");

    printf("\n*******************************************************************");
    printf("\n*   NAME   *    Ui    *    Ni    *    Ri    *    Xi    *    Wi    *");
    printf("\n*******************************************************************");
    printf("\n*          *          *          *          *          *          *");
    for (i=1;i<=K;i++)
    {
    	printf("\n* DEV%2d    *%10.4f*%10.4f*%10.4f*%10.4f*%10.4f*",(int)i,U[i],N[i],R[i],X[i],W[i]);
    	printf("\n*          *          *          *          *          *          *");
    }
    printf("\n*******************************************************************");
    printf("\n");

    printf("\n********************************************************");
    printf("\n*   NAME   *    Vi    *     Si   *    Di    *    Qi    *");
    printf("\n********************************************************");
    printf("\n*          *          *          *          *          *");
    for (i=1;i<=K;i++)
    {
    	printf("\n* DEV%2d    *%10.4f*%10.4f*%10.4f*%10.4f*",(int)i,V[i],S[i],D[i],Q[i]);
    	printf("\n*          *          *          *          *          *");
    }
    printf("\n********************************************************");
    printf("\n");

    printf("\n*******************************************");
    printf("\n*         SYSTEM VARIABLES                *");
    printf("\n*******************************************");
    printf("\n*                              *          *");
    printf("\n* #JOBS IN THE SYSTEM (N0)     *%10.4f*",N0);
    if (Network_type==CLOSED)
    {
    	printf("\n* #INTERACTIVE USERS (NZ)      *%10.4f*",(double)NT-N0);
    	printf("\n* #JOBS IN THE NETWORK (NT)    *%10ld*",NT);
    	printf("\n* SATURATION POINT (N*)        *%10.4f*",Na_float);
    }
    printf("\n*                              *          *");
    printf("\n* RESPONSE TIME (R0)           *%10.4f*",R0);
    printf("\n* MINIMUM RESPONSE TIME        *%10.4f*",Rm);
    printf("\n*                              *          *");
    printf("\n* THROUGHPUT (X0)              *%10.4f*",X0);
    printf("\n* MAXIMUM THROUGHPUT           *%10.4f*",Xm);
    printf("\n*                              *          *");
    printf("\n*******************************************");
    printf("\n");


    printf("\n****************************************");
    printf("\n*         ASIMPTOTIC BOUNDS            *");
    printf("\n****************************************");
    printf("\n*                                      *");
    if (Network_type==OPEN)
    {
    	printf("\n* R0_min =  %10.4f                 *",Rm);
    	printf("\n* X0_max =  %10.4f                 *",Xm);
    }
    if (Network_type==CLOSED)
    {
    	printf("\n* R0  <=   max {%5.2f, %5.2f*NT-%5.2f} *",Rm,D[imax],Z);
    	printf("\n* X0  >=   min {NT/%5.2f, %5.2f}       *",Rm+Z,Xm);
    }
    printf("\n*                                      *");
    printf("\n****************************************");
    printf("\n");

}
