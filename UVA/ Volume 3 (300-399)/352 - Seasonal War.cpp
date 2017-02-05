/*****************************************
 ***Problema: Seasonal War
 ***ID: 352
 ***Juez: UVA
 ***Tipo: Graph Theory, BFS, DFS
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include<iostream>
#include<stdio.h>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
#define MAX 30
char ady[MAX][MAX];
bool visitado[MAX][MAX];
int h,w;

struct Estado{
   int x,y;
   Estado(int x1,int y1):x(x1),y(y1){}

};

int dx[8]={1,-1,0, 0,1,-1,-1,1};
int dy[8]={0, 0,1,-1,1, 1,-1,-1};

void bfs(int x, int y, char c){
   Estado inicial(x,y);
   queue<Estado> Q;
   Q.push(inicial);

   while(!Q.empty()){
      Estado actual=Q.front();Q.pop();

      visitado[actual.x][actual.y]=true;
      for(int i=0;i<8;i++){
         int nx=dx[i]+actual.x;
         int ny=dy[i]+actual.y;
         if(nx>=0 && nx<h && ny>=0 && ny<w && ady[nx][ny]==c && !visitado[nx][ny]){
              Estado vecino(nx,ny);
              Q.push(vecino);
         }
      }

   }
   return ;
}


int main(){
    int resp;
    string s;
    int ii=1;

    while(scanf("%d",&h)!=EOF){
       w=h;
       for(int i=0;i<h;i++){
         for(int j=0;j<w;j++){
           ady[i][j]=' ';
           visitado[i][j]=false;
         }
       }

       for(int i=0;i<h;i++){
          cin>>s;
          for(int j=0;j<w;j++){
              ady[i][j]=s[j];
            }
       }
       resp=0;
       for(int i=0;i<h;i++){
          for(int j=0;j<w;j++){
              if(!visitado[i][j] && ady[i][j]=='1'){
                bfs(i,j,'1');
                resp++;
              }
          }
       }

       printf("Image number %d contains %d war eagles.\n",ii++,resp);


    }

    return 0;
}
