/*****************************************
 ***Problema: Disjoint water supply
 ***ID: 12671
 ***Juez: UVA
 ***Tipo: DP
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <cstring>
#include <vector>

using namespace std;
#define MAX 1005
int V , E , dp[ MAX ][ MAX ];
vector< int > ady[ MAX ];

bool solve( int u , int v ){
    if( u == 0 )
        return true;

    if( dp[ u ][ v ] != -1 )
        return dp[ u ][ v ];

    bool b = false;

    for( int i = 0 ; i < ady[ v ].size() ; ++i ){
        int y = ady[ v ][ i ];
        if( u != y ){
            b |= solve( min( u , y ) , max( u , y ) );
            if( b )
                break;
        }
    }
    return dp[ u ][ v ] = b;
}
int main(){
    int ans , u , v;
    while( scanf("%d %d", &V , &E ) != EOF ){
        while( E-- > 0 && scanf("%d %d" , &u , &v ) ){
            ady[ v - 1 ].push_back( u - 1 );
        }
        memset( dp , -1 , sizeof( dp ) );
        ans = V - 1;
        for( int i = 1 ; i < V ; ++i ){
            for( int j = i + 1 ; j < V ; ++j ){
                ans += solve( i , j );
            }
        }
        printf("%d\n" , ans );
        for( int i = 0 ; i < V ; ++i )
            ady[ i ].clear();
    }
    return 0;
}
