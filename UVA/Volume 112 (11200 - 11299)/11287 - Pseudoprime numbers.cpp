/*****************************************
 ***Problema: Pseudoprime Numbers
 ***ID: 11287
 ***Juez: UVA
 ***Tipo: Number Theory, Big Mod, Primes
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>

long long cuadrado(long long n,long long m){return n%m*n%m;}

long long bigmod(long long b, long long p, long long m){
    if(p == 0 ) return 1LL;
    if( p & 1LL){
       return (b%m * bigmod(b , p-1 , m))%m;
    }
    return cuadrado(bigmod(b,p/2,m),m)%m;
}

bool isPrime(long long n){
    for(int i = 2; i*i < n;i++ ){
       if(n%i==0)return false;
    }
    return true;
}


int main(){
    long long p,b;
    while(scanf("%lld %lld",&p,&b)){
        if(p == 0 && b ==0)break;
        if( isPrime(p) )printf("no\n");
        else{
           if(bigmod(b,p,p) == b)printf("yes\n");
           else printf("no\n");
        }
    }

    return 0;
}
