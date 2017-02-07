/*****************************************
 ***Problema: Prime Cuts
 ***ID: 406
 ***Juez: UVA
 ***Tipo: Number Theory, Sieve, Primes
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include<iostream>
#include<stdio.h>
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <numeric>
#include <utility>
#include <deque>
#include <stack>
#include <bitset>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <queue>
#include <limits>
#include <fstream>
using namespace std;
#define MAX 1001

int prime[MAX];

void sieve(){
   int i,k;
   for(i = 1; i <= MAX; ++i){
      prime[i]=1;
   }
   for(i=2;i*i<=MAX;i++){
      if(prime[i]==1){
        for(k=2;k*i<=MAX;k++){
            prime[k*i]=0;
        }
      }
   }
}

int main(){
    sieve();
    int a,c,i,id,cant;

    while(scanf("%d %d",&a,&c)==2){
        int primes[a];
        id=0;
        printf("%d %d:",a,c);
        for(i=1;i<=a;i++){if(prime[i]==1){primes[id++]=i;}}

        (id%2==0)?c*=2: c=c*2-1;
         if(c>id)c=id;
         cant=(id-c)/2;
         if(cant<0)cant=0;

        for(int i=cant;i<cant+c;++i)
            printf(" %d", primes[i]);
        printf("\n\n");
    }
    return 0;
}

