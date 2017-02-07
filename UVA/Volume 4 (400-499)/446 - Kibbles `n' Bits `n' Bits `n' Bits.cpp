/*****************************************
 ***Problema: Kibbles `n' Bits `n' Bits `n' Bits
 ***ID: 401
 ***Juez: UVA
 ***Tipo: Number Theory, Base conversion
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include<iostream>
#include<stdio.h>
#include<sstream>
using namespace std;

///DE A-F A ENTERO
int valor(char n){
   int j,i;
   for(i='A',j=10;i<='F' && j<=15;i++,j++){
      if(n==i)break;
   }
   return j;
}

///DE ENTERO a A-F
char valor2(int n){
   int i,j;
   for(i=10,j='A';i<=15 && j<='F';i++,j++){
      if(n==i)break;
   }
   return (char)j;
}

int pow(int a,int b){
   int r=1;
   for(int i=0;i<b;i++){
       r*=a;
   }
   return r;
}

int base(string n,int b){
    int i,idx=0,aux;
    int r=0;

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

string toString(int n){
    string s;
    ostringstream buffer;
    buffer<<n;
    s= buffer.str();
    return s;
}

string base2(int n,int b){
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

string completar(string n){
   string s="";
   for(int i=0;i<13-n.length();i++){
       s="0"+s;
   }
   return s+=n;
}


int main(){
    int n,resp,num1,num2;
    string n1,s,n2;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        cin>>n1>>s>>n2;
        num1=base(n1,16);
        resp=num1;
        n1=base2(num1,2);
        n1=completar(n1);
        num2=base(n2,16);
        if(s.compare("+")==0)resp+=num2;
        else resp-=num2;
        n2=base2(num2,2);
        n2=completar(n2);
        cout<<n1<<" "<<s<<" "<<n2<<" = "<<resp<<endl;
    }
    return 0;
}
