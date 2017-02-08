/*****************************************
 ***Problema: Combinations
 ***ID: 369
 ***Juez: UVA
 ***Tipo: Number theory, Binomial theorem.
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include<iostream>
#include<stdio.h>
using namespace std;

long long Binomial(long n,long m){
    long long resp;
    resp=1;
    if(m>n/2)m=n-m;

    for(int i=0;i<m;i++){
       resp*=n--;
       resp/=i+1;
    }
    return resp;
}

int main(){
    long n,m;
    while(cin>>n>>m){
       if(n==0 && m==0)break;
       cout<<n<<" things taken "<<m<<" at a time is "<<Binomial(n,m)<<" exactly."<<endl;
    }
    return 0;
}

