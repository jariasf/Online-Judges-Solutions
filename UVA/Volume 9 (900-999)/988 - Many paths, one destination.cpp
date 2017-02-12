/*******************************************
 ***Problema: Many paths, one destination
 ***ID: 988
 ***Juez: UVA
 ***Tipo: Topological Sort, Longesth Path DP
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;
#define MAX 105
int V, dp[ MAX ], outdegree[ MAX ] , indegree[ MAX ];
vector< int > ady[ MAX ];

void countingPath(){
    int i , act , y , ans = 0;
    queue< int > Q;
    memset( dp , 0 , sizeof( dp ) );
    for( i = 0 ; i < V ; ++i ){
        if( !indegree[ i ] ){
            Q.push( i );
            dp[ i ] = 1;
        }
    }

    while( !Q.empty() ){
        act = Q.front(); Q.pop();
        for( i = 0 ; i < ady[ act ].size() ; ++i ){
            y = ady[ act ][ i ];
            indegree[ y ]--;
            if( !indegree[ y ] ) Q.push( y );
            dp[ y ] += dp[ act ];
        }
    }

    for( i = 0 ; i < V ; ++i ){
        if( !outdegree[ i ] ) ans += dp[ i ];
    }
    printf("%d\n" , ans );
}

int main(){
    int i , j , k , v, q = 0;
    while( scanf("%d" , &V ) != EOF ){
        if( q++ ) printf("\n");
        memset( indegree , 0 , sizeof( indegree ) );
        memset( outdegree , 0 , sizeof( outdegree ) );
        for( i = 0 ; i < V && scanf("%d" , &k ) == 1 ; ++i ){
            for( j = 0 ; j < k && scanf("%d" , &v ) ; ++j ){
                ady[ i ].push_back( v );
                outdegree[ i ]++;
                indegree[ v ]++;
            }
        }
        countingPath();
        for( i = 0 ; i < V ; ++i ) ady[ i ].clear();
    }

    return 0;
}
