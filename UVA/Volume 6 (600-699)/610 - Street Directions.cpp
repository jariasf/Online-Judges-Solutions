/*****************************************
 ***Problema: Street Directions
 ***ID: 610
 ***Juez: UVA
 ***Tipo: Bridge, Back Edges
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <cstring>
#include <vector>
using namespace std;
#define MAX 1005
int V, dfsNum[ MAX ] , low[ MAX ], num,seen[ MAX ];

vector< int > ady[ MAX ];
void dfs( int x , int parent ){
    dfsNum[ x ] = low[ x ] = num++;
    seen[ x ] = 1;
    for( int i = 0 ; i < ady[ x ].size() ; ++i ){
        int y = ady[ x ][ i ];

        if( !seen[ y ] )
        {
            printf("%d %d\n" , x , y );
            dfs( y , x );
            if( dfsNum[ x ] < low[ y ] ){
                printf("%d %d\n" , y , x );
            }
            low[ x ] = min( low[ x ] , low[ y ] );
        }
        else if( y != parent && dfsNum[ x ] > dfsNum[ y ]  ){
            printf("%d %d\n" , x , y );
            if( low[ x ] > dfsNum[ y ] ) low[ x ] = dfsNum[ y ];
        }
    }
}

int main(){
    int E , u , v , q = 1;
    while( scanf("%d %d" , &V , &E ) , V | E ){
        while( E-- ){
            scanf("%d %d" , &u , &v );
            ady[ u ].push_back( v );
            ady[ v ].push_back( u );
        }
        memset( seen , 0 , sizeof( seen ) );
        num = 1;
        printf("%d\n\n", q++ );
        dfs( 1 , -1 );
        printf("#\n");
        for( int i = 1 ; i <= V ; ++i ) ady[ i ].clear();
    }
    return 0;
}
