/******************************************************
 ***Problema: Critical Links
 ***ID: 796
 ***Juez: UVA
 ***Tipo: Graph Theory, Bridges, Biconnected Components
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************************/

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
#define MAX 10005
int min( int a , int b ){ return ( a < b )? a : b ; }
int seen[ MAX ] , dfsNum[ MAX ] , low[ MAX ] , num , numBridges , V;
struct Bridges{
    int x , y;
    Bridges( int xx , int yy ): x( xx ), y( yy ){}
    Bridges(){}
    bool operator < ( const Bridges b ) const{
        return x < b.x || ( x == b.x && y < b.y );
    }
}bridges[ MAX ];

vector< int > ady[ MAX ];
void dfs( int x , int parent ){
    dfsNum[ x ] = low[ x ] = num++;
    seen[ x ] = 1;
    for( int i = 0 ; i < ady[ x ].size() ; ++i ){
        int y = ady[ x ][ i ];
        if( !seen[ y ] ){
            dfs( y , x );
            if( dfsNum[ x ] < low[ y ]){
                if( x < y ) bridges[ numBridges++ ] = Bridges( x , y );
                else bridges[ numBridges++ ] = Bridges( y , x );
            }
            low[ x ] = min( low[ x ] , low[ y ] );
        }
        else if( y != parent ){
            low[ x ] = min( dfsNum[ y ] , low[ x ] );
        }
    }
}


int main(){
    int t , u , k , v;
    while( scanf("%d"  , &V ) != EOF ){

        for( int i = 0 ; i < V ; ++i ){
            scanf("%d (%d)" , &u , &k );
            ady[ u ].clear();
            while( k-- ){
                scanf("%d" , &v );

                ady[ u ].push_back( v );
            }
        }

        memset( seen , 0 , sizeof( seen ) );
        numBridges = 0;
        for( int i = 0 ; i < V ; ++i ){
            if( !seen[ i ] ){
                num = 0;
                dfs( i , -1 );
            }
        }
        printf("%d critical links\n" , numBridges );
        sort( bridges , bridges + numBridges );
        for( int i = 0 ; i < numBridges ; ++i ) printf("%d - %d\n" , bridges[ i ].x , bridges[ i ].y );
        printf("\n");
    }

    return 0;
}
