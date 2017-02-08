/*****************************************
 ***Problema: Prime Factors
 ***ID: 583
 ***Juez: UVA
 ***Tipo: Number Theory
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include<math.h>
#include<time.h>
#include<sstream>
#include<string>
using namespace std;

vector<int> factorization(int n){
    vector<int> factores;
    int i;
    for(i=2;i<=n/i;i++){
      while(n%i==0){
          factores.push_back(i);
          n=n/i;
      }
    }
    if(n>1){factores.push_back(n);}
    return factores;
}

int main(){
    int n,aux,i;
    vector<int> factores;
    while(cin>>n){
        if(n<INT_MIN || n>INT_MAX || n==1 || n==-1 || n==0){break;}
        cout<<n<<" = ";
        if(n<0){
            cout<<"-1 x ";
            aux=n*(-1);
        }
        else{aux=n;}
        factores=factorization(aux);
        for(i=0;i<factores.size();i++){
            cout<<factores.at(i);
            if(i!=factores.size()-1){
              cout<<" x ";
            }
        }
        cout<<endl;
    }
    return 0;
}
