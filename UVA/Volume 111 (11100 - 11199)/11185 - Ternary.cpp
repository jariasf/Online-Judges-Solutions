/*****************************************
 ***Problema: Ternary
 ***ID: 11185
 ***Juez: UVA
 ***Tipo: Number Base Conversion
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include<iostream>
#include<stdio.h>
#include<sstream>
using namespace std;

string toString(long long n){
    string s;
    stringstream buffer;
    buffer<<n;
    buffer>>s;
    return s;
}

string base3(long long n,long long b){
    string str="";
    int aux;
    if(n==0)return "0";
    while(n>=1){
        aux=n%b;
        str=toString(aux)+str;
        n/=b;
    }
    return str;
}

int main(){
    long long n;
    while(1){
        cin>>n;
        if(n<0)break;
        cout<<base3(n,3)<<endl;
    }

    return 0;
}
