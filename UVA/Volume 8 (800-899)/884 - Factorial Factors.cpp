/*****************************************
 ***Problema: Factorial Factors
 ***ID: 884
 ***Juez: UVA
 ***Tipo: Number Theory, sieve(modified)
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include<iostream>
#include<stdio.h>
using namespace std;
#define MAX 1000001
int tabla[MAX];
int aux[MAX];
void solve(){
    tabla[1]=aux[1]=0;
    tabla[2]=aux[2]=1;
    int i,j,n,tmp;
    for(i=3;i<MAX;i++){
       n=i;
       tmp=1;
       for(j=2;j*j<=n;j++){
          if(n%j==0){
             tmp=j;
             break;
          }
       }
       if(tmp==1)aux[i]=1;
       else{
          aux[i]=aux[tmp]+aux[n/tmp];
       }
       tabla[i]=tabla[i-1]+aux[i];
    }
}

int main(){
    solve();
    int n;
    while(scanf("%d",&n)!=EOF){
         printf("%d\n",tabla[n]);
    }
}
