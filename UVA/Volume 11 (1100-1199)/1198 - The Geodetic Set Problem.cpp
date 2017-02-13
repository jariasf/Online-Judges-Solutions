/*****************************************
 ***Problema: The Geodetic Set Problem
 ***ID: 1198
 ***Juez: UVA
 ***Tipo: Floyd Warshall
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

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
#define MAX 105
#define INF 1<<30
int V, ady[ MAX ][ MAX ] , path[ MAX ][ MAX ];
char s[ 2 * MAX ];
void init(){
    for( int i = 0 ; i < V ; ++i ){
        for( int j = 0 ; j < V ; ++j ){
            ady[ i ][ j ] = ( i == j )?0:INF;
        }
    }
}

void floyd(){
    for( int k = 0 ; k < V ; ++k ){
        for( int i = 0 ; i < V ; ++i ){
            if( ady[ i ][ k ] == INF ) continue;
            for( int j = 0 ; j < V ; ++j ){
                if( ady[ k ][ j ] == INF || ady[ i ][ j ] < ady[ i ][ k ] + ady[ k ][ j ] ) continue;
                ady[ i ][ j ] = ady[ i ][ k ] + ady[ k ][ j ];
            }
        }
    }

}

set< int > possible[ MAX ][ MAX ];
int a[ MAX ], seen[ MAX];
int main(){
    int x , q , len , cnt;

    set< int > :: iterator it;
    while( scanf("%d" , &V ) != EOF ){
        getchar();
        init();
        for( int i = 0 ; i < V && gets( s ) ; ++i ){
            stringstream ss( s );
            while( ss>>x ){
                x--;
                ady[ i ][ x ] = ady[ x ][ i ] = 1;
            }
        }
        floyd();
        for( int i = 0 ; i < V ; ++i ){
            for( int j = 0 ; j < V ; ++j ){
                for( int k = 0 ; k < V ; ++k ){
                    if( ady[ i ][ k ] + ady[ k ][ j ] <= ady[ i ][ j ] ){
                        possible[ i ][ j ].insert( k );
                    }
                }
            }
        }

        scanf("%d" , &q );
        getchar();
        while( q-- ){
            gets( s );
            stringstream ss( s );
            len = 0;
            while( ss>>x ){
                a[ len++ ] = --x;
            }
            memset( seen , 0 , sizeof( seen ) );
            cnt = 0;
            for( int i = 0 ; i < len ; ++i ){
                for( int j = i + 1 ; j < len ; ++j ){
                    for( it = possible[ a[ i ] ][ a[ j ] ].begin() ; it != possible[ a[ i ] ][ a[ j ] ].end() ; ++it ){
                        if( !seen[ *it ] ) cnt++;
                        seen[ *it ] = 1;
                    }
                }
            }
            if( cnt == V ) puts("yes");
            else puts("no");
        }

        for( int i = 0 ; i < V ; ++i )
            for( int j = 0 ; j < V ; ++j )
                possible[ i ][ j ].clear();
    }

    return 0;
}
