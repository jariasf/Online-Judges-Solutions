/*****************************************
 ***Problema: Shipping Routes
 ***ID: 383
 ***Juez: UVA
 ***Tipo: Graph Theory, BFS, Shortest path
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include<iostream>
#include<stdio.h>
#include<queue>
#include<map>
using namespace std;
#define MAX 40
int ady[MAX][MAX];
int visitado[MAX];
int V;

struct Estado{
    int x;
    int d;
    Estado(int x1,int d1):x(x1),d(d1){}
};
int bfs(int ini,int fin){
    Estado inicial(ini,0);
    queue<Estado> Q;
    Q.push(inicial);
    memset(visitado,false,sizeof(visitado));
    while(!Q.empty()){
        Estado actual=Q.front();Q.pop();
        if(actual.x==fin){return actual.d;}

        visitado[actual.x]=true;
        for(int i=0;i<V;i++){
            if(ady[actual.x][i]==1 && !visitado[i]){
              Estado vecino(i,actual.d+1);
              Q.push(vecino);
            }
        }

    }
    return -1;

}

int main(){
    int casos,A,R,costo;
    string s,s2,s1;
    scanf("%d",&casos);
    printf("SHIPPING ROUTES OUTPUT\n");
    for(int i=1;i<=casos;i++){
        putchar('\n');
        printf("DATA SET  %d\n\n",i);
        scanf("%d %d %d",&V,&A,&R);
        map<string,int> mp;
        for(int j=0;j<V;j++){
            cin>>s;
            mp[s]=j;
        }

        for(int i=0;i<=V;i++){
           for(int j=0;j<=V;j++)ady[i][j]=0;
        }

        while(A--){
           cin>>s1>>s2;
           ady[mp[s1]][mp[s2]]=1;
           ady[mp[s2]][mp[s1]]=1;
        }

        while(R--){
           cin>>costo>>s1>>s2;
           int time=bfs(mp[s1],mp[s2]);
           if(time==-1){
               printf("NO SHIPMENT POSSIBLE\n");
           }
           else printf("$%d\n",time*costo*100);
        }

    }
    printf("\nEND OF OUTPUT\n");

    return 0;
}
