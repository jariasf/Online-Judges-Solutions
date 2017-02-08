/*****************************************
 ***Problema: Basically Speaking
 ***ID: 389
 ***Juez: UVA
 ***Tipo: Number Theory, Base conversion
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

///DIVISIONES SUCESIVAS
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
    string n,resp,str;
    long long bi,bf,d;
    while(cin>>n>>bi>>bf){
        d=base(n,bi);
        str="";
        if(d==-1)cout<<"ERROR"<<endl;
        else{
             resp=base2(d,bf);
             if(resp.length()>7) resp="ERROR";
             for(int i=0;i<7-resp.length();i++){
                 str+=" ";
             }
             str+=resp;
             cout<<str<<endl;
        }
    }
    return 0;
}
