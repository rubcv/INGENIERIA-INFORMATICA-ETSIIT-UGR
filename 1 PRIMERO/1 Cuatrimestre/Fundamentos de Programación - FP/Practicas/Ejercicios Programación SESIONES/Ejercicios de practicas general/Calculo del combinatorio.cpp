//calcula el numero combinatorio
//n sobre m
#include <iostream>
#include<stdio.h>

int main()
{
//fn factorial de n
//fm factorial de m
//fnm factorial de n-m
//c numero combinatorio
int n,m,fn,fm,fnm,i,c;
 printf("\nIntroduce n y m:");
 scanf("%d%d",&n,&m);
//calculo del factorial de n
 fn=1;
for (i=2;i<=n;i++)
 fn=fn*i;
//calculo del factorial de m
 fm=1;
for (i=2;i<=m;i++)
 fm=fm*i;
//calculo del factorial de n-m
 fnm=1;
for (i=2;i<=n-m;i++)
 fnm=fnm*i;
//calculo del numero combinatorio
 c=fn/fm/fnm;
 printf("\n(%d,%d)=%d",n,m,c);
 
 system ("pause");
}
