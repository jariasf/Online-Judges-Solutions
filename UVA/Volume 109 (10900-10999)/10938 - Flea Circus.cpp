/*****************************************
 ***Problema: Flea Circus
 ***ID: 10938
 ***Juez: UVA
 ***Tipo: LCA
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <cstring>
#include <vector>
#include <iostream>

using namespace std;
#define MAX 10010
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define pii pair<int , int >
#define MIN( a , b ) ( a < b ) ? a : b

int n, parent[ MAX ] , kparent[ MAX ][ 15 ] , depth[ MAX ], seen[ MAX ], dist[ MAX ];
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

//devuelve el kth elemento del lca desde u a v
//k es la profundidad al que tengo q igualar
int find_kth( int p , int k ){
    int j , i ;
    for( j = 1 ; 1<<j <= depth[ p ] ; ++j ); --j;
    for( i = j ; i >= 0 ; --i )
        if( depth[ p ] - ( 1<<i ) >= k ) p = kparent[ p ][ i ];
    return p;
}

int main(){
    int d, Q , u , v, w, ini, lca , k , uu, vv;
    while( scanf("%d" , &n ) , n ){
        for( int i = 0 ; i < n - 1 ; ++i ){
            scanf("%d %d" , &u , &v  );
            u--;
            v--;
            ady[ u ].pb( pii( v , 1 ) );
            ady[ v ].pb( pii( u , 1 ) );
            ini = u;
        }
        memset( seen , 0 , sizeof( seen ) );
        memset( dist , 0 , sizeof( dist ) );
        dfs( ini , 0 );
        lca_init();
        scanf("%d" , &Q );
        while( Q-- ){
            scanf("%d %d" , &u , &v );
            u--; v--;
            lca = LCA( u , v );
            d = dist[ u ] + dist[ v ] - 2 * dist[ lca ] + 1;
            int l1 = depth[ u ] - depth[ lca ] + 1;
            if( d & 1 ){
                k = d/2 + 1;
                if( k <= l1 ){
                    printf("The fleas meet at %d.\n" , find_kth( u , depth[ lca ] + ( l1 - k )) + 1 );
                }
                else{
                    printf("The fleas meet at %d.\n" , find_kth( v , depth[ lca ] + (k - l1 ) ) + 1 );
                }
            }
            else{
                k = d/2;
                if( k <= l1 ){
                    uu = find_kth( u , depth[ lca ] + ( l1 - k )) + 1 ;
                }
                else{
                    uu = find_kth( v , depth[ lca ] + (k - l1 ) ) + 1 ;
                }
                k++;
                if( k <= l1 ){
                    vv = find_kth( u , depth[ lca ] + ( l1 - k )) + 1 ;
                }
                else{
                    vv = find_kth( v , depth[ lca ] + (k - l1 ) ) + 1 ;
                }

                printf("The fleas jump forever between %d and %d.\n" , min( uu , vv ) , max( uu , vv ) );
            }
        }
        for( int i = 0 ; i < n ; ++i ) ady[ i ].clear();
    }
    return 0;
}
