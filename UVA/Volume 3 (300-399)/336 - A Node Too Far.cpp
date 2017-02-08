/*****************************************
 ***Problema: A Node Too Far
 ***ID: 336
 ***Juez: UVA
 ***Tipo: Graph theory, bfs, floyd warshall
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
#include<map>
#include<set>
using namespace std;
#define MAX 55
int ady[MAX][MAX];

struct Estado{
    int x;
    int d;
    Estado(int x1,int d1):x(x1),d(d1){};
};

int bfs(int x,int dist,int tamano){
    Estado inicial (x,0);
    queue<Estado> cola;
    cola.push(inicial);
    bool visitado[MAX];
    memset(visitado,false,sizeof(visitado));
    int cantidad=0;
    set<int> resp;
    visitado[x]=true;
    while(!cola.empty()){
        Estado actual=cola.front();
        cola.pop();

        if(actual.d<=dist){
            resp.insert(actual.x);
        }

        for(int j=0;j<MAX;j++){
            if(ady[actual.x][j]==1 && !visitado[j]){
               Estado ady(j,actual.d+1);
               visitado[j]=true;
               cola.push(ady);
            }
        }
    }
    return resp.size();
}

int main(){
    int cant,i,j,orig,dest,k,dist,nvisit,casos=1;

    while(scanf("%d",&cant) && cant!=0){
        k=1;
        map<int,int> mp;
        memset(ady,0,sizeof(ady));
        for(i=0;i<cant;i++){
          scanf("%d %d",&orig,&dest);
          //mapeo valores grandes en pequeños ejem nodo 35 sera nodo 1
          if(mp.find(orig)==mp.end()){
             mp[orig]=k++;
          }
          if(mp.find(dest)==mp.end()){
             mp[dest]=k++;
          }
          ady[mp[orig]][mp[dest]]=ady[mp[dest]][mp[orig]]=1; //nodos a matriz
        }

        while(scanf("%d %d",&orig,&dist)){
            if(orig==0 && dist==0)break;
            nvisit=k-1-bfs(mp[orig],dist,k);

            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",casos++,nvisit,orig,dist);
        }
    }

    return 0;
}
