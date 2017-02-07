/*****************************************
 ***Problema: Word Index
 ***ID: 417
 ***Juez: UVA
 ***Tipo: Ad hoc, brute force
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include<iostream>
#include<stdio.h>
#include<map>
using namespace std;

map<string,int> mp;

void solve(){
    string s;
    int num=1;
    for(int i='a';i<='z';i++){
        s="";
        s+=(char)i;
        mp[s]=num++;
    }

    for(int i='a';i<='z';i++){

       for(int j=i+1;j<='z';j++){
           s="";
           s+=(char)i;
           s+=(char)j;
           mp[s]=num++;
       }
    }


    for(int i='a';i<='z';i++){

       for(int j=i+1;j<='z';j++){

           for(int k=j+1;k<='z';k++){
               s="";
               s+=(char)i;
               s+=(char)j;
               s+=(char)k;
               mp[s]=num++;
           }
       }
    }


    for(int i='a';i<='z';i++){

       for(int j=i+1;j<='z';j++){

           for(int k=j+1;k<='z';k++){

               for(int q=k+1;q<='z';q++){
                   s="";
                   s+=(char)i;
                   s+=(char)j;
                   s+=(char)k;
                   s+=(char)q;
                   mp[s]=num++;
               }
           }
       }
    }

    for(int i='a';i<='v';i++){

       for(int j=i+1;j<='z';j++){

           for(int k=j+1;k<='z';k++){

               for(int q=k+1;q<='z';q++){

                   for(int w=q+1;w<='z';w++){
                       s="";
                       s+=(char)i;
                       s+=(char)j;
                       s+=(char)k;
                       s+=(char)q;
                       s+=(char)w;
                       mp[s]=num++;
                   }
               }
           }
       }
    }

}


int main(){

    solve();
    string s;
    while(cin>>s){
        cout<<mp[s]<<endl;
    }

    return 0;
}

