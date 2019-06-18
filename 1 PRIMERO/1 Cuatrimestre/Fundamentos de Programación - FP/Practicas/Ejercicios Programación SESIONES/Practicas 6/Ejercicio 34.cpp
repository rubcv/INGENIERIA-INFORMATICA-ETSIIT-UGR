#include <iostream>
#include<stdio.h>

int main()
{

int n,m,facn,facm,facnm,i,com;
 printf("\nIntroduce n y m:");
 scanf("%d%d",&n,&m);
//Factorial de n
 facn=1;
for (i=2;i<=n;i++)
 facn=facn*i;
//Factorial de m
 facm=1;
for (i=2;i<=m;i++)
 facm=facm*i;
//Factorial de n-m
 facnm=1;
for (i=2;i<=n-m;i++)
 facnm=facnm*i;
//Numero combinatorio
 com=facn/(facm*facnm);
 printf("\n(%d,%d)=%d",n,m,com);
 
 system ("pause");
}
