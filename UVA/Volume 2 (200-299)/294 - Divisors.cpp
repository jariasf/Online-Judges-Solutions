/*****************************************
 ***Problema: Divisors
 ***ID: 294
 ***Juez: UVA
 ***Tipo: Number theory, sieve, primes.
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include<iostream>
#include<stdio.h>
using namespace std;

#define MAX 31630

int prime[MAX];

void sieve(){
   for(int i = 2; i <= MAX; ++i){
      prime[i]=1;
   }

   for(int i=2;i*i<=MAX;i++){
      if(prime[i]==1){
        for(int k=2;k*i<=MAX;k++){
            prime[k*i]=0;
        }
      }
   }
}

long getDivisors(long  n){
    int factores[MAX],id=0;
    for(int i=0;i<MAX;i++){
        factores[i]=0;
    }
    long resp=1;
    for(int i=2;i*i<=n;i++){
        while(n%i==0 && prime[i]==1){
             factores[id]++;
             n/=i;
        }
        if(factores[id]!=0)id++;
    }
    if(n>1) resp*=2;

    factores[id]=0;
    for(int i=0;i<=id;i++){
        if(factores[i]!=0)
         resp*=(factores[i]+1);
    }
    return resp;
}

int main(){
    int n,cont,max;
    long l,u,i,j,k,q,resp;
    sieve();
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%ld %ld",&l,&u);
        max=0;
        for(j=l;j<=u;j++){

            k=getDivisors(j);
            if(k>max){max=k;resp=j;}
        }
        printf("Between %ld and %ld, %ld has a maximum of %ld divisors.\n",l,u,resp,max);
    }
    return 0;
}
