/*****************************************
 ***Problema: Robot
 ***ID: 314
 ***Juez: UVA
 ***Tipo: Graph Theory, bfs
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<queue>
using namespace std;
#define MAX 101
struct Estado{
    int x; //coordenada x
    int y; //coordenada y
    int dir; //direccion este,oeste,norte,sur
    int d;  //distancia
    Estado(int x1,int y1,int dir1,int d1):x(x1),y(y1),dir(dir1),d(d1){};

};
int dx[] = { -1, 0, 1, 0};
int dy[] = {  0, 1, 0,-1};
int tabla[MAX][MAX];
void bfs(int f,int c, int x, int y, int xf,int yf,int dir) {
    if(x==xf && y==yf){printf("0\n");return;}
    if(tabla[x][y]==0 && tabla[xf][yf]==0){
    Estado inicial(x,y,dir,0);
    queue<Estado> cola;
    cola.push(inicial);
    int nx,ny;
    bool visitado[f][c][4];
    memset(visitado,false,sizeof(visitado));
    while(!cola.empty()){
        Estado actual=cola.front();
        cola.pop();
 
        if(tabla[actual.x][actual.y]==1 || visitado[actual.x][actual.y][actual.dir] || actual.x<=0 || actual.y<=0 || actual.x>=f ||actual.y>=c){continue;}
        if(actual.x==xf && actual.y==yf){printf("%d\n",actual.d);return;}
        visitado[actual.x][actual.y][actual.dir]=true;
        Estado izq(actual.x,actual.y,(actual.dir+1)%4,actual.d+1);
        Estado der(actual.x,actual.y,(actual.dir+3)%4,actual.d+1);
        cola.push(izq);
        cola.push(der);
        nx=actual.x;
        ny=actual.y;
        for(int i=0;i<3;i++){
            nx+=dx[actual.dir],ny+=dy[actual.dir];//vemos adyacentes
            //no tiene caso seguir avanzando si excede limites de matriz
            if(nx<=0 || ny<=0 || nx>=f || ny>=c || tabla[nx][ny]==1)break;
            Estado ady(nx,ny,actual.dir,actual.d+1); //colocamos a la cola los pasos que puede avanzar
            cola.push(ady);
        }

    }
    }
    printf("-1\n");
}

int main(){
    int f,c,j,i,xi,yi,xf,yf,direccion;
    char estado[5];
    while(scanf("%d %d",&f,&c) && f+c){
        int a[f][c];
        for(i=0;i<f;i++){
           for(j=0;j<c;j++){
               scanf("%d",&a[i][j]);
           }
        }

        memset(tabla,0,sizeof(tabla));
        //modifico arreglo ingresado
        for(i=0;i<f;i++){
           for(j=0;j<c;j++){
               if(a[i][j]){
                      tabla[i][j]=1;
                      tabla[i][j+1]=1;
                      tabla[i+1][j]=1;
                      tabla[i+1][j+1]=1;
               }
           }
        }

        scanf("%d %d %d %d %s",&xi,&yi,&xf,&yf,&estado);

        switch(estado[0]){
           case 'n': direccion=0;break;
           case 'e': direccion=1;break;
           case 's': direccion=2;break;
           case 'w': direccion=3;break;
        }
        bfs(f,c,xi,yi,xf,yf,direccion);
    }

    return 0;
}
