/*****************************************
 ***Problema: Goldbach's Conjecture (II)
 ***ID: 686
 ***Juez: UVA
 ***Tipo: Number Theory, sieve
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include<iostream>
#include<stdio.h>
using namespace std;
#define MAX 35000
bool primes[MAX];
void sieve(){
   primes[0]=false;
   for(int i=1;i<MAX;i++) primes[i]=true;
   for(int i=2;i*i<=MAX;i++){
      if(primes[i]){
         for(int j=i;j*i<=MAX;j++){
             primes[j*i]=false;
         }
      }
   }

}

int main(){
    int n,i,j,resp;
    sieve();
    while(scanf("%d",&n) && n!=0){
        resp=0;
        for(i=2;i<=n/2;i++){
           if(!primes[i])continue;
           if(primes[i] && primes[n-i]){resp++;}
        }
        printf("%d\n",resp);

    }

    return 0;
}
