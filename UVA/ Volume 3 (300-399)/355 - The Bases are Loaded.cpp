/*****************************************
 ***Problema: The Bases are Loaded
 ***ID: 355
 ***Juez: UVA
 ***Tipo: Number Theory
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include<iostream>
#include<stdio.h>
#include<string>
#include<sstream>
using namespace std;

int valor(char n){
   int j,i;
   for(i='A',j=10;i<='F' && j<=15;i++,j++){
      if(n==i)break;
   }
   return j;
}

char valor2(int n){
   int i,j;
   for(i=10,j='A';i<=15 && j<='F';i++,j++){
      if(n==i)break;
   }
   return (char)j;
}

long long pow(long long a,long long b){
   long long r=1;
   for(int i=0;i<b;i++){
       r*=a;
   }
   return r;
}

long long base(string n,int b){
    int i,idx=0,aux;
    long long r=0;

    for(i=n.length()-1;i>=0;i--){
        if(isdigit(n[i])){
            aux=n[i]-'0';
        }
        else{
            aux=valor(n[i]);
        }
        if(aux>=b)return -1;
        r+=(aux*pow(b,idx));
        idx++;
    }
    return r;
}

string toString(long long n){
    string s;
    ostringstream buffer;
    buffer<<n;
    s= buffer.str();
    return s;
}
string base2(long long n,long long b){
    string str="";
    int aux;
    if(n==0)return "0";
    while(n>=1){
        aux=n%b;

        if(aux>9 && aux<16){str=valor2(aux)+str;}
        else {str=toString(aux)+str;}
        n/=b;
    }
    return str;
}

int main(){
    string n;
    long long bi,bf,d,resp;
    while(cin>>bi>>bf>>n){
        d=base(n,bi);

        if(d==-1)cout<<n<<" is an illegal base "<<bi<<" number"<<endl;
        else{
           if(bf==10)cout<<n<<" base "<<bi<<" = "<<d<<" base "<<bf<<endl;
           else{
             cout<<n<<" base "<<bi<<" = "<<base2(d,bf)<<" base "<<bf<<endl;
           }
        }
    }
    return 0;
}
