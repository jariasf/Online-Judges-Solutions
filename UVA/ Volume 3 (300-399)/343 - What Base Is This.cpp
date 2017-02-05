/*****************************************
 ***Problema: What Base Is This?
 ***ID: 343
 ***Juez: UVA
 ***Tipo: Number Theory
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include<iostream>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string>
using namespace std;

int valor(char n){
   int j,i;
   for(i='A',j=10;i<='Z' && j<=36;i++,j++){
      if(n==i)break;
   }
   return j;
}

int pow(int a,int b){
   int r=1;
   for(int i=0;i<b;i++){
       r*=a;
   }
   return r;
}
int base(string n,int b){
    int i,idx=0;
    int r=0,aux;

    for(i=n.length()-1;i>=0;i--){
        if(isdigit(n[i])){
            aux=n[i]-'0';
        }
        else{
            aux=valor(n[i]);
        }
        if(aux>=b)return -1;

        r+=(aux*(int)pow(b,idx));

        idx++;
    }
    return r;
}

int main(){
    int i,j;
    string x,y;
    int bx,by;
    while(cin>>x>>y){
        for(i=2;i<=36;i++){
           bx=base(x,i);
           if(bx==-1)continue;
           for(j=2;j<=36;j++){
              by=base(y,j);
              if(by==-1)continue;
              if(bx==by)break;
           }
           if(bx==by)break;
        }
        if(i==37 || j==37) cout<<x<<" is not equal to "<<y<<" in any base 2..36\n";
        else cout<<x<<" (base "<<i<<") = "<<y<<" (base "<<j<<")\n";
    }

    return 0;
}
