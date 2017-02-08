/*****************************************
 ***Problema: Always on the run
 ***ID: 590
 ***Juez: UVA
 ***Tipo: DP
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <cstring>
#include <vector>

using namespace std;
#define MAXV 15
#define MAXT 1005
#define MAXD 35
#define INF 1<<30
int V , k;
vector< int > ady[ MAXV ][ MAXV ];
int dp[ MAXT ][ MAXV ];
int solve( int day , int last ){
    if( day == k  ){
        if( last == V - 1 ) return 0;
        return INF;
    }

    if( dp[ day ][ last ] != INF ) return dp[ day ][ last ];
    int ans = INF , i , y , w;
    for( i = 0 ; i < V ; ++i ){
        if( i == last ) continue;
        y = day % ady[ last ][ i ].size();
        w = ady[ last ][ i ][ y ];
        if( w == 0 ) continue;
        ans = min( ans , w + solve( day + 1 , i ) );
    }
    return dp[ day ][ last ] = ans;
}

int main(){
    int q , x , i , j , t = 1 , ans;
    while( scanf("%d %d" , &V , &k ) , V | k ){
        for( i = 0 ; i < V ; ++i ){
            for( j = 0 ; j < V ; ++j ){
                if( i == j ) continue;
                scanf("%d" , &q );
                while( q-- ){
                    scanf("%d" , &x );
                    ady[ i ][ j ].push_back( x );
                }
            }
        }

        for( i = 0 ; i < k ; ++i )
            for( j = 0 ; j < V ; ++j )
                dp[ i ][ j ] = INF;

        printf("Scenario #%d\n" , t++ );
        ans = solve( 0 , 0 );
        if( ans == INF ) puts("No flight possible.");
        else printf("The best flight costs %d.\n" , ans );
        printf("\n");
        for( i = 0 ; i < V ; ++i )
            for( j = 0 ; j < V ; ++j )
                ady[ i ][ j ].clear();
    }
    return 0;
}
