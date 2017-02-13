/*****************************************
 ***Problema: The Suspects
 ***ID: 1197
 ***Juez: UVA
 ***Tipo: Flood Fill | Union Find
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#define MAX 30005
int parent[ MAX ];
int Find( int x ){
    return ( x == parent[ x ] )? x: parent[ x ] = Find( parent[ x ] );
}

void Union( int x , int y ){
    parent[ Find( x ) ] = Find( y );
}

int V;
void makeSet(){
    for( int i = 0 ; i < V ; ++i ) parent[ i ] = i;
}

int numNodes( int x ){
    int ans = 0;
    for( int i = 0 ; i < V ; ++i ){
        ans += ( x == Find( i ) )?1:0;
    }
    return ans;
}

int main(){
    int g , k , ant, x ;
    while( scanf("%d %d" , &V , &g ) , V | g ){
        makeSet();
        while( g-- ){
            scanf("%d" , &k );
            for( int q = 0 ; q < k ; ++q ){
                scanf("%d" , &x );
                if( q ) Union( ant , x );
                ant = x;
            }
        }
        printf("%d\n" , numNodes( Find( 0 ) ) );
    }
    return 0;
}
