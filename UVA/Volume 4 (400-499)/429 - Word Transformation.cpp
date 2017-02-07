/*****************************************
 ***Problema: Word Transformation
 ***ID: 429
 ***Juez: UVA
 ***Tipo: Graph Theory, BFS, strings
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include<iostream>
#include<stdio.h>
#include<map>
#include<vector>
#include<queue>
#include<sstream>
using namespace std;
#define MAX 201
#define INF 9999999
int ady[MAX][MAX];
int V;
void init(){
    for(int i=0;i<=V;i++){
         for(int j=0;j<=V;j++){
                 ady[i][j]=INF;
         }
        ady[i][i]=0;
    }
}

void floyd(){
    for(int k=0;k<V;k++){
        for(int i=0;i<V;i++){
             for(int j=0;j<V;j++){
                    int t=ady[i][k]+ady[k][j];
                    if(t<ady[i][j]){
                       ady[i][j]=t;
                    }
             }
        }
    }
}

int main(){
    int casos,index;
    scanf("%d",&casos);
    string s,s2,s1;
    char C;
    for(int x=0;x<casos;x++){
        if(x!=0){putchar('\n');}
        vector<string> dictionary;
        map<string,int> mp;
        index=0;
        while(cin>>s && s!="*"){
            dictionary.push_back(s);
            mp[s]=index++;
        }
        V=index;
        init();
        ///Formo grafo conenctando palabras con un caracter de diferencia
        int n=dictionary.size();
        for(int i=0;i<n;i++){
            s=dictionary[i];
                for(int k=i+1;k<n;k++){
                    s2=dictionary[k];
                    if(s2.length()!=s.length())continue;
                    int diferencia=0;
                    for(int q=0;q<s2.length();q++){
                        if(s[q]!=s2[q])diferencia++;
                        if(diferencia>1)break;
                    }
                    //si se diferencia en un caracter hago el enlace
                    if(diferencia==1){
                       ady[mp[s]][mp[s2]]=1;
                       ady[mp[s2]][mp[s]]=1;
                    }
            }

        }
        floyd();
        cin.get();
        while(getline(cin,s1)){
            if(s1.length()==0)break;
            stringstream ss(s1);
            ss>>s>>s2;
            if(ady[mp[s]][mp[s2]]==INF)cout<<s<<" "<<s2<<" 0"<<endl;
            else cout<<s<<" "<<s2<<" "<<ady[mp[s]][mp[s2]]<<endl;
        }
    }
    return 0;
}
