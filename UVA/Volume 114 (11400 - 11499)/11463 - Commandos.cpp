/*****************************************
 ***Problema: Commandos
 ***ID: 11463
 ***Juez: UVA
 ***Tipo: Graph Theory, Floyd Warshall
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include<iostream>
#include<stdio.h>
using namespace std;
#define MAX 101
#define INF 9999999
int ady[MAX][MAX];
int V;
void Init(){
    for(int i=0;i<V;i++){
         for(int j=0;j<V;j++){
                 ady[i][j]=INF;
         }
        ady[i][i]=0;
    }
}

void floyd(){
    for(int k=0;k<V;k++){
        for(int i=0;i<V;i++){
             for(int j=0;j<V;j++){
                    int t=ady[i][k]+ady[k][j];

                    if(t<ady[i][j]){
                      ady[i][j]=t;
                    }
             }
        }
    }
}

int main(){
    int casos,E,x,y;
    scanf("%d",&casos);
    for(int i=1;i<=casos;i++){

        scanf("%d",&V);
        Init();
        scanf("%d",&E);

        while(E--){
            scanf("%d %d",&x,&y);
            ady[x][y]=1;
            ady[y][x]=1;
        }

        scanf("%d %d",&x,&y);
        floyd();
        int maxi=0;
        for(int j=0;j<V;j++){
           maxi=std::max(ady[x][j]+ady[j][y],maxi);
        }
        printf("Case %d: %d\n",i,maxi);
    }

    return 0;
}
