/*****************************************
 ***Problema: Newspaper
 ***ID: 11332
 ***Juez: UVA
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include<iostream>
#include<stdio.h>
#include<map>
#include<string>
#include<sstream>
using namespace std;

int main(){
    int casos,car,val,lines;
    long long cents;
    char c;
    string s;
    scanf("%d",&casos);
    while(casos--){
        map<char,int> mp;
        scanf("%d",&car);
        while(car--){
            cin>>c>>val;
            mp[c]=val;
        }
        scanf("%d",&lines);
        cents=0;
        cin.get();
        while(lines--){
            getline(cin,s);
            s+=" ";
            stringstream ss(s);

            while(ss>>s){
               for(int i=0;i<s.length();i++){
                  if(mp.find(s[i])!=mp.end()){
                     cents+=mp[s[i]];
                  }
               }
            }

        }
        printf("%.2lf$\n",cents/100.0);
    }
    return 0;
}
