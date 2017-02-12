/*********************************************
 ***Problema: Jumping Champion
 ***ID: 914
 ***Juez: UVA
 ***Tipo: Number theory, sieve, linear search
 ***Autor: Jhosimar George Arias Figueroa
 *********************************************/

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
#include <list>
#include <sstream>
#include <iostream>
#include <iomanip>

using namespace std;
#define MAX 1000007
int prime[MAX];

int primos[MAX];
int tam;
///sieve
void sieve(){
   prime[0]=prime[1]=0;
   for(int i = 2; i < MAX; ++i){
      prime[i]=1;
   }

   for(int i=2;i*i<MAX;i++){
      if(prime[i]==1){
        for(int k=2;k*i<MAX;k++){
            prime[k*i]=0;
        }
      }
   }
   int k=0;
   for(int i=2;i<MAX;i++){
       if(prime[i])primos[k++]=i;
   }
   tam=k;
}

int main(){
    sieve();
    int casos,L,U,num,cont,dif,idx;

    scanf("%d",&casos);
    while(casos--){
        scanf("%d %d",&L,&U);
        int ini;
        cont=0;
        ///linear search
        for(ini=0;ini<tam;ini++){
            if(primos[ini]>=L){
               break;
            }
        }

        int diff[1004];
        for(int i=ini;i<tam;i++){
            if(primos[i]>U)break;
            cont++;
            if(i<tam-1 && primos[i+1]<=U)diff[primos[i+1]-primos[i]]++;
        }
        int max=0;
        for(int i=0;i<1004;i++){
            if(diff[i]>max){max=diff[i];num=i;}
        }

        bool b=false;

        for(int i=0;i<1004;i++){
            if(i!=num && diff[i]==max){b=true;break;}
        }

        if(cont<2 || b)printf("No jumping champion\n");
        else printf("The jumping champion is %d\n",num);

    }
    return 0;
}
