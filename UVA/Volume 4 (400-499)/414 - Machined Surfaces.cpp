/*****************************************
 ***Problema: Machined Surfaces
 ***ID: 414
 ***Juez: UVA
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include<iostream>
#include<stdio.h>
using namespace std;

int main(){
    int n,maxi,resp;
    string s;
    while(scanf("%d",&n) && n!=0){

        int a[n];
        memset(a,0,sizeof(a));
        maxi=0;
        resp=0;
        cin.get();
        for(int j=0;j<n;j++){
            getline(cin,s);
            for(int i=0;i<s.length();i++){
                if(s[i]=='X'){a[j]++;}
            }
            maxi=max(maxi,a[j]);
        }
        for(int i=0;i<n;i++){
            resp+=maxi-a[i];
        }
        printf("%d\n",resp);
    }

    return 0;
}
