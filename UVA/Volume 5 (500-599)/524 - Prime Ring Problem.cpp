
/************************************************
 ***Problema: Prime Ring Problem
 ***ID: 524
 ***Juez: UVA
 ***Tipo: Backtracking, sieve, graph theory, DFS
 ***Autor: Jhosimar George Arias Figueroa
 ************************************************/

#include<stdio.h>

#define MAX 17
int prime[33]={0, 0, 1, 1, 0, 1, 0, 1, 0, 0,
             0, 1, 0, 1, 0, 0, 0, 1, 0, 1,
             0, 0, 0, 1, 0, 0, 0, 0, 0, 1,
             0, 1, 0};
int ady[MAX][MAX];
int visitado[MAX];
int resp[MAX];
int idx;


void dfs(int inicio,int tamano){
    visitado[inicio]=true;
    resp[idx++]=inicio;
    if(idx==tamano && prime[resp[0]+resp[tamano-1]]){
        putchar('1');
        for(int i=1;i<tamano;i++){
            printf(" %d",resp[i]);
        }
        putchar('\n');
    }
    for(int i=1;i<=tamano;++i){
        if(ady[inicio][i]==1 && !visitado[i]){
           dfs(i,tamano);
        }
    }
    resp[--idx]=0;
    visitado[inicio]=false;
}

void solve(int inicio,int final){
     idx=0;
     resp[idx++]=inicio;
     visitado[inicio]=true;
     for(int i=1;i<=final;i++){
        if(ady[inicio][i]==1 && !visitado[i]){
           dfs(i,final);
        }
     }
}

int main(){
    int n,i,j,cont=1;
    for(i=1;i<=MAX;i++){
        for(j=1;j<=MAX;j++){
            if(prime[i+j] && i!=j){ady[i][j]=1;}
        }
    }
    while(scanf("%d",&n)!=EOF){
        if(cont-1)putchar('\n');
        printf("Case %d:\n",cont++);
        if(!(n&1)){
            for(i=0;i<=n;i++)visitado[i]=false;
            solve(1,n);
        }
    }
    return 0;
}
