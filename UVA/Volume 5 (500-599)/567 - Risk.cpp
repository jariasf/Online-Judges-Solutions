/*****************************************
 ***Problema: Risk
 ***ID: 567
 ***Juez: UVA
 ***Tipo: Graph theory, bfs, floyd warshal
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include<iostream>
#include<stdio.h>
#include<queue>
using namespace std;
#define MAX 20
#define INF 9999999
int ady[MAX][MAX];

void init(){
    for(int i=0;i<MAX;i++){
         for(int j=0;j<MAX;j++){
                 ady[i][j]=INF;
         }
        ady[i][i]=0;
    }
}

void floyd(){
    for(int k=0;k<MAX;k++){
        for(int i=0;i<MAX;i++){
             for(int j=0;j<MAX;j++){
                    int t=ady[i][k]+ady[k][j];
                    if(t<ady[i][j]){
                       ady[i][j]=t;
                    }
             }
        }
    }
}


int main(){

    int nodos,i,j,cont=1,dest,casos,xi,xf;
    while(scanf("%d",&nodos)!=EOF){
        init();
        for(i=0;i<nodos;i++){
           scanf("%d",&dest);
           ady[0][dest-1]=ady[dest-1][0]=1;

        }
        for(i=1;i<=18;i++){
           scanf("%d",&nodos);
           for(j=0;j<nodos;j++){
               scanf("%d",&dest);
               ady[i][dest-1]=ady[dest-1][i]=1;
           }
        }
        scanf("%d",&casos);
        floyd();
        printf("Test Set #%d\n",cont);
        while(casos--){
           scanf("%d %d",&xi,&xf);
           printf("%2d to %2d: %d\n",xi,xf,ady[xi-1][xf-1]);
        }
        cont++;
        putchar('\n');


    }
    return 0;
}
