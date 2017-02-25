/*****************************************
 ***Problema: Fire! Fire!! Fire!!!
 ***ID: 10243
 ***Juez: UVA
 ***Tipo: DP Minimum Vertex Cover
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <cstring>
#include <vector>
using namespace std;
#define MAX 1005
#define INF 1<<30
int V , dp[ MAX ][ 2 ];
vector< int > ady[ MAX ];
int min( int a , int b ){ return ( a < b )? a : b; }
int solve( int cur , int color , int parent ){

    if( dp[ cur ][ color ] != -1 ) return dp[ cur ][ color ];
    int ans = INF , i , y;

    if( color ){
        ans = 1;
        for( i = 0 ; i < ady[ cur ].size() ; ++i ){
            y = ady[ cur ][ i ];
            if( y != parent )
                ans +=  min( solve( y , 0 , cur ) , solve( y , 1 , cur ) );
        }
    }
    else{
        ans = 0;
        for( i = 0 ; i < ady[ cur ].size() ; ++i ){
            y = ady[ cur ][ i ];
            if( y != parent )
                ans += solve( y , 1 , cur );
        }
    }
    return dp[ cur ][ color ] = ans;
}

int main(){
    int i , k , v , ans;
    while( scanf("%d" , &V ) , V ){
        for( i = 0 ; i < V && scanf("%d" , &k ) == 1 ; ++i ){
            while( k-- ){
                scanf("%d" , &v );
                ady[ i ].push_back( v - 1 );
            }
        }
        memset( dp , -1 , sizeof( dp ) );
        ans = solve( 0 , 1 , -1 );
        if( ans > 1 ) ans = min( ans , solve( 0 , 0 , -1 ) );
        printf( "%d\n" , ans );
        for( i = 0 ; i < V ; ++i ) ady[ i ].clear();
    }
    return 0;
}
