/*****************************************
 ***Problema: Oil Deposits
 ***ID: 572
 ***Juez: UVA
 ***Tipo: Graph Theory, BFS, Flood Fill
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include<iostream>
#include<stdio.h>
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <numeric>
#include <utility>
#include <deque>
#include <stack>
#include <bitset>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <queue>
#include <limits>
#include <fstream>
using namespace std;
#define MAX 105
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
      if(visitado[actual.x][actual.y])continue;
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


    while(scanf("%d %d",&h,&w) && (h!=0 && w!=0)){

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
              if(!visitado[i][j] && ady[i][j]=='@'){
                bfs(i,j,'@');
                resp++;
              }
          }
       }

       printf("%d\n",resp);


    }

    return 0;
}

