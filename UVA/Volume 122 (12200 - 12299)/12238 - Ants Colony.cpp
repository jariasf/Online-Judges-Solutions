/*****************************************
 ***Problema: Ants Colony
 ***ID: 12238
 ***Juez: UVA
 ***Tipo: LCA
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <cstring>
#include <vector>
#include <iostream>

using namespace std;
#define MAX 100010
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define pii pair<int , long long >
#define MIN( a , b ) ( a < b ) ? a : b

int n, parent[ MAX ] , kparent[ MAX ][ 18 ] , depth[ MAX ], seen[ MAX ];
long long dist[ MAX ];
vector< pii > ady[ MAX ];
void dfs( int x , int lvl ){
    seen[ x ] = 1;
    depth[ x ] = lvl;
    for( int i = 0 ; i < ady[ x ].size() ; ++i ){
        if( !seen[ ady[ x ][ i ].first ] ){
            parent[ ady[ x ][ i ].first ] = x;
            dist[ ady[ x ][ i ].first ] = dist[ x ] + ady[ x ][ i ].second;
            dfs( ady[ x ][ i ].first , lvl + 1 );
        }
    }
}

void lca_init(){
    int i , j;
    memset( kparent , -1 , sizeof( kparent ) );
    for( i = 0 ; i < n ; ++i ) kparent[ i ][ 0 ] = parent[ i ];
    for( j = 1 ; 1<<j <= n ; ++j )
        for( i = 0 ; i < n ; ++i )
            kparent[ i ][ j ] = kparent[ kparent[ i ][ j - 1 ] ][ j - 1 ];
}

int LCA( int p , int q ){
    int i, j;
    if( depth[ p ] < depth[ q ] ) swap( p , q );
    for( j = 1 ; 1<<j <= depth[ p ] ; ++j ); --j;

    for( i = j ; i >= 0 ; --i )
        if( depth[ p ] - ( 1<<i ) >= depth[ q ] ) p = kparent[ p ][ i ];
    if( p == q ) return q;

    for( i = j ; i >= 0 ; --i )
        if( kparent[ p ][ i ] != -1 && kparent[ p ][ i ] != kparent[ q ][ i ] )
            p = kparent[ p ][ i ] , q = kparent[ q ][ i ];

    return parent[ p ];
}

int main(){
    int u , v , Q , lca;
    long long w;
    while( scanf("%d" , &n ) , n ){
        for( int i = 1 ; i < n  ; ++i ){
            scanf("%d %lld" , &v , &w );
            ady[ v ].pb( pii( i , w ) );
            ady[ i ].pb( pii( v , w ) );
        }
        memset( seen , 0 , sizeof( seen ) );
        dfs( 0 , 0 );
        lca_init();
        scanf("%d" , &Q );
        for( int q = 0 ; q < Q ; ++q ){
            if( q )printf(" ");
            scanf("%d %d" , &u , &v );
            lca = LCA( u , v );
            printf("%lld" , dist[ u ] + dist[ v ] - 2 * dist[ lca ] );
        }
        printf("\n");
        for( int i = 0 ; i < n ; ++i ) ady[ i ].clear();
    }
}
