/*****************************************
 ***Problema: Rotating Sentences
 ***ID: 490
 ***Juez: UVA
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include<iostream>
#include<stdio.h>
using namespace std;

int main(){
  char a[101][103];
  int i,j,k=0,n,l,max=0;

  while(gets(a[k])) k++;

    for(i=0;i<k;i++)
    {
       l = strlen(a[i]);
       if(l>max)max = l;
       for(j = l;j<100; j++ )   a[i][j] = ' ';
    }

    for(i = 0; i<max; i++ )
    {
       for(j = k-1; j>=0; j-- ) printf("%c",a[j][i]);

      printf("\n");
    }
    return 0;
}
