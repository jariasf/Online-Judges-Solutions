/*****************************************
 ***Problema: What's Cryptanalysis?
 ***ID: 10008
 ***Juez: UVA
 ***Tipo: Ad hoc, sorting
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;

bool f(pair<int,char> p1, pair<int,char> p2){
    if(p1.first<p2.first)return true;
    if(p1.first==p2.first)return p1.second>p2.second;
    return false;
}

int main(){
    int casos;
    scanf("%d",&casos);
    string s;
    cin.get();
    int a[26]={0};
    vector<pair<int,char> > v;
    while(casos--){
       getline(cin,s);
       for(int i=0;i<s.length();i++){
           if(isalpha(s[i])){a[tolower(s[i])-'a']++;}
       }
    }

    for(int i=0;i<26;i++){
       if(a[i]!=0)v.push_back(make_pair(a[i],(char)(i+'a')));
    }
    sort(v.begin(),v.end(),f);
    for(int i=v.size()-1;i>=0;i--){
       cout<<(char)toupper(v[i].second)<<" "<<v[i].first<<endl;
    }
    return 0;
}
