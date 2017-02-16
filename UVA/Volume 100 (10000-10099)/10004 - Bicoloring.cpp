/*****************************************
 ***Problema: Bicoloring
 ***ID: 10004
 ***Juez: UVA
 ***Tipo: Graph Theory, DFS
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include<iostream>
#include<stdio.h>
using namespace std;
#define MAX 205
int ady[MAX][MAX];
bool visitado[MAX];
char color[MAX];
bool bicolor;
void Init(int n){
   for(int i=0;i<n;i++){
        visitado[i]=false;
        color[i]=' ';
      for(int j=0;j<n;j++){
        ady[i][j]=0;
      }
   }
}


void solve(int inicial,int tamano){
   visitado[inicial]=true;
   for(int i=0;i<tamano;i++){
      if(ady[inicial][i]==1 && !visitado[i]){
         if(color[i]==' '){
            if(color[inicial]=='R')color[i]='B';
            else color[i]='R';
         }
         solve(i,tamano);
      }
   }
   visitado[inicial]=false;
}

void dfs(int inicial,int tamano){
   visitado[inicial]=true;
   color[inicial]='R';
   for(int i=0;i<tamano;i++){
      if(ady[inicial][i]==1 && !visitado[i]){
         if(color[i]==' '){
            color[i]='B';
         }
         solve(i,tamano);
      }
   }
}

int main(){
    int vertex,no,x,y,xini,yini;
    while(scanf("%d",&vertex) && vertex!=0){
        scanf("%d",&no);
        bicolor=true;
        Init(vertex);

        for(int i=0;i<no;i++){
            scanf("%d %d",&x,&y);
            if(!i){xini=x;yini=y;}
            ady[x][y]=1;
            ady[y][x]=1;
        }
        dfs(xini,vertex);

        for(int i=0;i<vertex;i++){
           for(int j=0;j<vertex;j++){
               if(ady[i][j]==1){
                 if(color[i]==color[j]){bicolor=false;break;}
               }
           }
           if(!bicolor)break;
        }
        if(bicolor)printf("BICOLORABLE.\n");
        else printf("NOT BICOLORABLE.\n");
    }

    return 0;
}
