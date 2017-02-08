/*****************************************
 ***Problema: The Settlers of Catan
 ***ID: 539
 ***Juez: UVA
 ***Tipo: Backtracking
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <cstring>

#define MAX 26
int ady[ MAX ][ MAX ];
int V;
int resp;

void dfs( int n , int len ){
    if( resp < len )resp = len;
    for( int i = 0 ; i < V ; ++i ){
        if( ady[ n ][ i ] ){
            ady[ n ][ i ] = ady[ i ][ n  ] = 0;
            dfs( i , len + 1 );
            ady[ n ][ i ] = ady[ i ][ n ] = 1;
        }
    }
}

int main(){
    int E, u , v;
    while( scanf("%d %d" , &V , &E ) && V|E ){
        memset( ady , 0 , sizeof( ady ) );
        while( E-- ){
            scanf("%d %d" , &u , &v );
            ady[ u ][ v ] = ady[ v ][ u ] = 1;
        }
        resp = 0;
        for( int i = 0 ; i < V ; ++i ){
            dfs( i , 0 );
        }
        printf("%d\n" , resp );

    }
    return 0;
}
