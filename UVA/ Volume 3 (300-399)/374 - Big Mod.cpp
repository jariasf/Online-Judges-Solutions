/*****************************************
 ***Problema: Big Mod
 ***ID: 311
 ***Juez: UVA
 ***Tipo: Math
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include<iostream>
#include<stdio.h>
using namespace std;

long cuadrado(long n){return n*n;}
long bigmod(long b,long p,long m){
    if(p==0)
       return 1;
    else if(p%2==0)
       return cuadrado(bigmod(b,p/2,m))%m;
    else
       return ((b%m)*bigmod(b,p-1,m))%m;
}

int main(){
    long long b,p,m;
    while(scanf("%lu %lu %lu",&b,&p,&m) ==3){
         cout<<bigmod(b,p,m)<<endl;
    }
    return 0;
}
