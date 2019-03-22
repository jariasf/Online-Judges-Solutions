/*****************************************
 ***Problema: Bond
 ***ID: 11354
 ***Juez: UVA
 ***Tipo: LCA
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/


#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <vector>
#include <iostream>

using namespace std;
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define pii pair<int , long long >

#define MAXN 100050
int uf[ MAXN ];

int Find( int x ){
    return ( uf[ x ] == x ) ? x : uf[ x ] = Find( uf[ x ] );
}
void Union( int x , int y ){
    uf[ Find( x ) ] = Find( y );
}
struct Arista{
    int u , v;
    long long w;
    Arista( int uu , int vv , long long ww ): u( uu ) , v( vv ) , w( ww ){}
    Arista(){}
    bool operator <( const Arista &a ) const{
        return w < a.w;
    }
}graph[ MAXN ];

int n, parent[ MAXN ], seen[ MAXN ], kparent[ MAXN ][ 18 ] , depth[ MAXN ];
long long dmax[ MAXN ][ 18 ], dist[ MAXN ];
vector< pii > ady[ MAXN ];
int MAX( int a , int b ){ return ( a < b ) ? b : a; }
void dfs( int x , int lvl ){
    seen[ x ] = 1;
    depth[ x ] = lvl;
    for( int i = 0 ; i < ady[ x ].size() ; ++i ){
        if( !seen[ ady[ x ][ i ].first ] ){
            dist[ ady[ x ][ i ].first ] = dist[ x ] + ady[ x ][ i ].second;
            parent[ ady[ x ][ i ].first ]= x;
            dfs( ady[ x ][ i ].first , lvl + 1 );
        }
    }
}

void lca_init(){
    int i, j;
    memset( kparent , -1 , sizeof( kparent ) );
    memset( dmax , 0 , sizeof( dmax ) );
    for( i = 0 ; i < n ; ++i ){
        kparent[ i ][ 0 ] = parent[ i ];
        if( i == 0 ){ //distancia entre 2 nodos
            dmax[ i ][ 0 ] = 0;
        }
        else{
            dmax[ i ][ 0 ] = dist[ i ] - dist[ parent[ i ] ];
        }
    }

    //dmin minima distancia entre i y si 2^k ancestro
    for( j = 1 ; 1<<j <= n ; ++j )
        for( i = 0 ; i < n ; ++i ){
            dmax[ i ][ j ] = MAX( dmax[ i ][ j - 1 ] , dmax[ kparent[ i ][ j - 1 ] ][ j - 1 ] );
            kparent[ i ][ j ] = kparent[ kparent[ i ][ j - 1 ] ][ j - 1 ];
        }
}
long long maxi;
void LCA( int p , int q ){
    int i,j;
    if( depth[ p ] < depth[ q ] ) swap( p , q );

    for( j = 1 ; 1<<j <= depth[ p ] ; ++j ); --j;
    for( i = j ; i >= 0 ; --i )
        if( depth[ p ] - (1<<i) >= depth[ q ] )
        {
            maxi = MAX( maxi , dmax[ p ][ i ] );
            p = kparent[ p ][ i ];
        }

    if( p == q ) return;
    for( i = j ; i >= 0 ; --i )
        if( kparent[ p ][ i ] != -1 && kparent[ p ][ i ] != kparent[ q ][ i ] ){
            maxi = MAX( maxi , MAX( dmax[ p ][ i ] , dmax[ q ][ i ] ) );
            p = kparent[ p ][ i ] , q = kparent[ q ][ i ];
        }

    maxi = MAX( maxi , MAX( dmax[ p ][ 0 ] , dmax[ q ][ 0 ] ) );
}

int main(){

    int  E, u , v, Q, ini, lca;
    long long w;
    bool f = true;
    while( scanf(" %d %d" , &n , &E ) == 2 ){
        if( !f )printf("\n");
        f = false;
        for( int i = 0 ; i < n ; ++i ) uf[ i ] = i;
        for( int i = 0 ; i < E ; ++i ){
            scanf("%d %d %lld" , &u , &v  ,&w );
            u--; v--;
            graph[ i ].u = u;
            graph[ i ].v = v;
            graph[ i ].w = w;
        }
        sort( graph , graph + E );

        for( int i = 0 ; i < E ; ++i ){
            u = graph[ i ].u; v = graph[ i ].v; w = graph[ i ].w;
            if( Find( u ) != Find( v ) ){
                ini = u;
                ady[ u ].push_back( pii( v , w ) );
                ady[ v ].push_back( pii( u , w ) );
                Union( u , v );
            }
        }
        memset( dist , 0 , sizeof( dist ) );
        memset( seen , 0 , sizeof( seen ) );
        dfs( ini , 0 );
        lca_init();
        scanf("%d" , &Q );
        while( Q-- ){
            scanf("%d %d" , &u , &v );
            u--;
            v--;
            maxi = 0;
            LCA( u , v );
            printf("%lld\n" , maxi );
        }
        for( int i = 0 ; i <= n ; ++i ) ady[ i ].clear();
    }

    return 0;
}
