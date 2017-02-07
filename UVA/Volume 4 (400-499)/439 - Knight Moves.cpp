/*****************************************
 ***Problema: Knight Moves
 ***ID: 439
 ***Juez: UVA
 ***Tipo: Graphs theory, bfs
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include<iostream>
#include<stdio.h>
#include<queue>
#include<vector>
using namespace std;
struct Estado{
    int x; //coordenada x
    int y; //coordenada y
    int d; //distancia recorrida
    Estado(int x1,int y1,int d1):x(x1),y(y1),d(d1){};
};

int dx[ 8 ]={ -2 , -2 , -1 , -1 ,  1 , 1 ,  2 , 2 };
int dy[ 8 ]={ -1 ,  1 , -2 ,  2 , -2 , 2 , -1 , 1 };

const int h=8,w=8;
int tabla[h+3][w+3];
int bfs(int x, int y) {
    Estado inicial (x,y,0); //posicion inicial
    queue<Estado> cola;     //cola que tendra estados de adyacentes
    cola.push(inicial);     //pongo el estado inicial
    bool visitado[h+3][w+3];
    memset(visitado,false,sizeof(visitado));
    while(!cola.empty()){ //mientras no este vacia, mientras tengamos nodos para recorrer
        Estado actual=cola.front(); //actual
        cola.pop();  //elimino de la cola
        if(tabla[actual.x][actual.y]==-2)return actual.d; //si encontramos salida retornarla
        visitado[actual.x][actual.y]=true; //marco como visitado nodo actual
        for(int i=0;i<8;i++){
            int nx=actual.x+dx[i],ny=actual.y+dy[i];//vemos adyacentes
            //si no excede limites y no es pared ademas de no haber sido visitado
            if(nx>=0 && ny>=0 && nx<h && ny<w && !visitado[nx][ny]){
                Estado ady(nx,ny,actual.d+1); //colocamos a la cola los adyacentes
                cola.push(ady);
            }
        }
    }
    return 0;

}
int main(){

    char a[3],b[3];
    int xi,yi,xf,yf;
    while(scanf("%s %s",&a,&b)!=EOF){
        memset(tabla,0,sizeof(tabla));
        xi=(a[0]-'a')+1;
        yi=a[1]-'0';
        xf=(b[0]-'a')+1;
        yf=b[1]-'0';
        tabla[xf-1][yf-1]=-2;
        printf("To get from %s to %s takes %d knight moves.\n",a,b,bfs(xi-1,yi-1));
    }
    return 0;
}


