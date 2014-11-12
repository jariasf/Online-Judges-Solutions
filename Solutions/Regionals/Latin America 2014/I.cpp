/*****************************************
 ***Problema: Intrepid climber
 ***Tipo: Graph Theory - DFS
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

#define MAX 1000006
#define pb push_back
#define mp make_pair
#define pii pair<int , int >
#define INF 1<<30
int seen[ MAX ];
vector< pii > ady[ MAX ];
int f[ MAX ];
int dp[ MAX ];
int dpMax[ MAX ];

void solve( int u , int parent ){
    for( int i = 0 ; i < ady[ u ].size() ; ++i ){
        int v = ady[ u ][ i ].first;
        int w = ady[ u ][ i ].second;
        if( !seen[ v ] ){
            seen[ v ] = 1;
            solve( v , u );
            if( f[ v ] ){
                f[ u ] = 1;
                dpMax[ u ] = max( dpMax[ u ] , dpMax[ v ] + w );
                dp[ u ] += w;
            }else
                dpMax[ u ] = max( dpMax[ u ] , dpMax[ v ] );
            dp[ u ] += dp[ v ];
        }
    }
}

int main(){
    int V , Q , u , v , w , x;
    while( scanf("%d %d" , &V , &Q ) != EOF ){

        for( int i = 0 ; i < V - 1 && scanf("%d %d %d" , &u , &v , &w ) ; ++i ){
            u--; v--;
            ady[ u ].pb( mp( v , w ));
            ady[ v ].pb( mp( u , w ) );
        }
        for( int i = 0 ; i <= V ; ++i ){
            f[ i ] = seen[ i ] = dp[ i ] = dpMax[ i ] = 0;
        }

        for( int i = 0 ; i < Q && scanf("%d" , &x ); ++i ){
            x--;
            f[ x ] = 1;
        }
        seen[ 0 ] = 1;
        solve( 0 , -1 );
        printf("%d\n" , dp[ 0 ] - dpMax[0]);
        for( int i = 0 ; i <= V ; ++i )
            ady[ i ].clear();
    }
    return 0;
}
