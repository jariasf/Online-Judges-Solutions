/*****************************************
 ***Problema: Intrepid climber
 ***ID: 12862
 ***Juez: UVA
 ***Tipo: Dynamic Programming
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
#define x first
#define y second
#define pii pair<int , int >
#define MIN( a , b ) ( a < b ) ? a : b
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
            f[ i ] = seen[ i ] = 0;
            dp[ i ] = 0;
            dpMax[ i ] = 0;
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

/*

6 2
1 2 2
2 4 2
1 3 3
3 6 3
3 5 1
5 2
4 2
1 2 2
1 3 1
3 4 2
2 4
4 2
1 4 1
1 3 1
4 2 2
2 4
7 3
1 4 1
1 3 1
4 2 2
3 5 5
3 6 1
5 7 1
2 7 6
*/
