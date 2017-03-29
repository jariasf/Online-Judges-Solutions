/********************************************
 ***Problema: Place the Guards
 ***ID: 11080
 ***Juez: UVA
 ***Tipo: Graph Theory, Bipartite Graph Check
 ***Autor: Jhosimar George Arias Figueroa
 ********************************************/

#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <stdlib.h>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <numeric>
#include <utility>
#include <deque>
#include <stack>
#include <bitset>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <queue>
#include <limits>
#include <fstream>
#include <list>
#include <sstream>
#include <iostream>
#include <iomanip>

using namespace std;
#define MAX 205
vector< int > ady[ MAX ];
int V, numColor[ MAX ], seen[ MAX ] , color[ MAX ];
int MIN( int a , int b ){
    if( a == 0 || b == 0 ) return 1;
    return ( a < b )? a : b; }
int bfs( int origen ){
    memset( numColor , 0 , sizeof( numColor ) );
    queue< int > Q;
    Q.push( origen );
    int act;
    color[ origen ] = 1;
    while( !Q.empty() ){
        act = Q.front(); Q.pop();
        numColor[ color[ act ] ]++;
        for( int i = 0 ; i < ady[ act ].size() ; ++i ){
            if( !color[ ady[ act ][ i ] ] ){
                color[ ady[ act ][ i ] ] = ( color[ act ] + 1 ) % 2;
                if( color[ ady[ act ][ i ] ] == 0 ) color[ ady[ act ][ i ] ] = 2;
                Q.push( ady[ act ][ i ] );
            }
            else if( color[ ady[ act ][ i ] ] == color[ act ] ){
                return -1;
            }
        }
    }
    return 1;
}

int main(){

    int t , E , u , v, ans;
    scanf("%d" , &t );

    while( t-- ){
        scanf("%d %d" , &V , &E );
        while( E-- ){
            scanf("%d %d" , &u , &v );
            ady[ u ].push_back( v );
            ady[ v ].push_back( u );
        }
        ans = 0;
        memset( color , 0 , sizeof( color ) );
        for( int i = 0 ; i < V ; ++i ){
            if( color[ i ] ) continue;
            if( bfs( i ) == -1 ){
                ans = -1;
                break;
            }
            ans += MIN( numColor[ 1 ] , numColor[ 2 ] );
        }

        printf("%d\n" , ans );
        for( int i = 0 ; i <= V ; ++i ){
            ady[ i ].clear();
        }
    }

    return 0;
}
