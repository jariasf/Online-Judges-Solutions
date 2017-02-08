/*****************************************
 ***Problema: Skew Binary
 ***ID: 575
 ***Juez: UVA
 ***Tipo: Ad Hoc
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include<iostream>
#include<stdio.h>
using namespace std;

int main(){
    string s;
    int i;
    long long e,resp;
    while(cin>>s){
        if(s[0]=='0')break;
        e=1;
        resp=0;
        for(i=s.length()-1;i>=0;i--){
            resp+=(s[i]-'0')*((1<<e) - 1);
            e++;
        }
        cout<<resp<<endl;
    }
    return 0;
}

