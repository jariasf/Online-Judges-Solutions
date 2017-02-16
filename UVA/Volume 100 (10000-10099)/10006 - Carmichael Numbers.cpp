/*****************************************
 ***Problema: Carmichael Numbers
 ***ID: 10006
 ***Juez: UVA
 ***Tipo: Number theory, pseudoprimes, math
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include<stdio.h>
#define MAX 255
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

int main(){
    int n,i,factores[MAX],idx,aux;
    sieve();
    while(scanf("%d",&n)&& n!=0){
        idx=0;
        aux=n;

        for(i=2;i*i<=n;i++){
            while(n%i==0 && prime[i]==1){
                 factores[idx++]=i;
                 n/=i;
            }
        }
        if(n>1) {factores[idx++]=n;}
        ///KORSELT: numero/factor[i] - 1 % factor[i]-1 ==0
        int cont=0;
        for(i=0;i<idx;i++){
            if(i>0 && factores[i]==factores[i-1])break;
            if(((aux/factores[i])-1)%(factores[i]-1)==0)cont++;

        }

        if(cont==idx && cont>=3){
            printf("The number %d is a Carmichael number.\n",aux);
            }
        else printf("%d is normal.\n",aux);
    }
    return 0;
}
