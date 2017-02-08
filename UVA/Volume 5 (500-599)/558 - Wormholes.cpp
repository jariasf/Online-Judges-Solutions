/****************************************************
 ***Problema: Wormholes
 ***ID: 558
 ***Juez: UVA
 ***Tipo: Graph Theory, Bellmand Ford, negative cycle
 ***Autor: Jhosimar George Arias Figueroa
 ****************************************************/

#include <stdio.h>
#include <limits.h>
#define MAX 1005

struct edge{
    int u, v, w;
};

edge *e; //e = Arreglo de todas las aristas
long long d[ MAX ]; //Distancias
int n; //Cantidad de nodos
int m; //Cantidad de aristas

//retorna true si no hay ciclos negativos y false en caso q exista ciclo negativo
bool bellman(int &s){

    for ( int i = 0 ; i < n ; ++i ) d[ i ] = INT_MAX;
    d[ s ] = 0LL;

    // relajamos cada arista del grafo tantas veces como número de nodos -1 haya en el grafo
    for ( int i = 0 ; i < n - 1 ; ++i ){
        bool cambio = false;
        for (int j = 0; j < m ; ++j){
            int u = e[ j ].u, v = e[ j ].v;

            long long w = e[ j ].w;
            if ( d[ u ] + w < d[ v ] ){
                d[ v ] = d[ u ] + w;
                cambio = true;
            }
        }
        if ( !cambio ) break;
    }
    // comprobamos si hay ciclos negativo
    for (int j = 0 ; j < m ; ++j ){
        int u = e[ j ].u, v = e[ j ].v;
        long long w = e[ j ].w;
        if ( d[ u ] + w < d[ v ] ) return false;
    }

    return true;
}



int main(){
    int t;
    scanf("%d", &t);
    while( t-- ){
        scanf("%d %d", &n ,&m);
        e = new edge[ n ];
        for ( int i = 0 ; i < m ;++i ){
            scanf("%d %d %d",&e[ i ].u , &e[ i ].v , &e[ i ].w);
        }
        int inicio = 0;
        if( bellman( inicio ) )printf("not possible\n");
        else printf("possible\n");
    }
    return 0;
}
