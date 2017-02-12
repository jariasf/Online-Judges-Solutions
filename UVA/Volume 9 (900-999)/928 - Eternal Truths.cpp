/*****************************************
 ***Problema: Eternal Truths
 ***ID: 908
 ***Juez: UVA
 ***Tipo: Graph Theory, BFS, shortest path
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include<iostream>
#include<stdio.h>
#include<queue>
using namespace std;
#define MAX 305
int h,w;
const int INF=  ( 1 << 21);
struct Estado{
    int x;
    int y;
    int d;
    int dir;
    Estado(int x1,int y1,int d1):x(x1),y(y1),d(d1){}
    Estado(int x1,int y1,int d1,int av1):x(x1),y(y1),d(d1),dir(av1){}
};

char ady[MAX][MAX];
///ARREGLO PARA DISTANCIAS, TBN PONEMOS LA CANTIDAD DE PASOS A DAR 1 2 3
int dist[MAX][MAX][3];

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int xfin,yfin;
int bfs(int x,int y){
    Estado inicial(x,y,0,0);
    queue<Estado> Q;
    Q.push(inicial);

    for(int i=0; i<h; i++)
    for(int j = 0; j<w; j++)
    for(int k = 0; k<3;k++)
       dist[i][j][k] = INF;

    dist[x][y][0]=0;
    int len;
    while(!Q.empty()){
        Estado actual=Q.front();Q.pop();
        len=actual.dir+1;
        for(int i=0;i<4;i++){
            int nx=actual.x;
            int ny=actual.y;
            bool b=true;
            for(int j=0;j<len;j++){
                nx=dx[i]+nx;
                ny=dy[i]+ny;
                if(nx<0 ||nx>=h || ny<0 || ny>=w || ady[nx][ny]=='#'){b=false;break;}
            }
            if(b){
                if(dist[nx][ny][len%3]>dist[actual.x][actual.y][actual.dir]+1){
                   dist[nx][ny][len%3]=dist[actual.x][actual.y][actual.dir]+1;
                   Estado vecino(nx,ny,dist[actual.x][actual.y][actual.dir]+1,len%3);
                   Q.push(vecino);

                }
            }
        }
    }
    int min=INF;
    for(int i=0;i<3;i++){
        if(dist[xfin][yfin][i]<min){
           min=dist[xfin][yfin][i];
        }
    }
    if(min==INF)return -1;
    return min;
}

int main(){
    int casos,xini,yini;
    string s;
    scanf("%d",&casos);
    while(casos--){
        scanf("%d %d",&h,&w);
        for(int i=0;i<h;i++){
           cin>>s;
           for(int j=0;j<w;j++){
              ady[i][j]=s[j];
              if(s[j]=='S'){xini=i;yini=j;}
              if(s[j]=='E'){xfin=i;yfin=j;}
           }
        }

        int dist=bfs(xini,yini);
        if(dist==-1)printf("NO\n");
        else printf("%d\n",dist);


    }

    return 0;
}
