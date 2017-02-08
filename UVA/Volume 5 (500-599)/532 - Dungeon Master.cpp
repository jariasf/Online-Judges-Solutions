/*****************************************
 ***Problema: Dungeon Master
 ***ID: 532
 ***Juez: UVA
 ***Tipo: Graph Theory, BFS
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<queue>
using namespace std;
#define MAX 30
struct Estado{
    int x; //coordenada x
    int y; //coordenada y
    int z;
    Estado(int x1=-1,int y1=-1,int z1=-1):x(x1),y(y1),z(z1){};

};

void bfs(vector< vector<string> > niveles,int h,int w, int x, int y, int z) {
    Estado inicial(z,x,y);
    queue<Estado> cola;     //cola que tendra estados de adyacentes
    cola.push(inicial);     //pongo el estado inicial
    int distance[niveles.size()][h][w];
    memset(distance,-1,sizeof(distance));
    distance[inicial.x][inicial.y][inicial.z]=0;
    while(!cola.empty()){ //mientras no este vacia, mientras tengamos nodos para recorrer
        Estado actual=cola.front(); //actual
        cola.pop();  //elimino de la cola
        if(niveles[actual.x][actual.y][actual.z]=='E'){
			printf("Escaped in %d minute(s).\n",distance[actual.x][actual.y][actual.z]);
			return;
		}
        int dx[] = { 0, 0, 0, 0,-1, 1};
        int dy[] = { 0, 0,-1, 1, 0, 0};
        int dz[] = {-1, 1, 0, 0, 0, 0};
        for(int i=0;i<6;i++){
            int nx=actual.x+dx[i],ny=actual.y+dy[i],nz=actual.z+dz[i];//vemos adyacentes
            //si no excede limites y no es pared ademas de no haber sido visitado
            if(nx>=0 && ny>=0 && ny<h && nz<w && nz>=0 && nx<niveles.size() && niveles[nx][ny][nz]!='#' && distance[nx][ny][nz] == -1){
                Estado ady(nx,ny,nz); //colocamos a la cola los adyacentes
                distance[nx][ny][nz] = distance[actual.x][actual.y][actual.z] + 1;
                cola.push(ady);
            }
        }


    }
    printf("Trapped!\n");

}
int main(){
    int l,f,c,i,j,k,tm,xi,yi,xf,yf,zi;
    char line[50],C;
    while(scanf("%d %d %d",&l,&f,&c) && l!=0 && f!=0 && c!=0){
        vector< vector<string> > laberinto;
        cin.get();
        for(k=0;k<l;k++){
           vector<string> nivel;
           for(i=0;i<f;i++){
               scanf("%s",&line);
             for(j=0;j<c;j++){
               if(line[j]=='S'){xi=i;yi=j;zi=k;}
             }
             nivel.push_back(line);
           }
           laberinto.push_back(nivel);
        }
        bfs(laberinto,f,c,xi,yi,zi);
    }
    return 0;
}
