/*****************************************
 ***Problema: The Collatz Sequence
 ***ID: 694
 ***Juez: UVA
 ***Tipo: Ad hoc, simulation
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include<iostream>
#include<stdio.h>
using namespace std;

int main(){
    long long  a,b,i;
    int cont,caso=1;
    while(cin>>a>>b && a>=0 && b>=0){
        cont=1;
        i=a;
        while(i!=1){
            if(i%2==0){i=i/2;}
            else {i=3*i+1;}
            if(i>b)break;
            cont++;
        }
        cout<<"Case "<<caso++<<": A = "<<a<<", limit = "<<b<<", number of terms = "<<cont<<"\n";
    }

    return 0;
}
