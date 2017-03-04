/*****************************************
 ***Problema: Montesco vs Capuleto
 ***ID: 10505
 ***Juez: UVA
 ***Tipo: Graph Conectivity, union find
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

#define MAX 255
int V;
vector< int > ady[ MAX ];
int color[ MAX ] , contColor[ 5 ];
int bfs( int inicial ){
    int act;
    queue< int > Q;
    Q.push( inicial );
    color[ inicial ] = 1;
    memset( contColor , 0 , sizeof( contColor ) );
    bool finish = false;
    while( !Q.empty() ){
        act = Q.front(); Q.pop();
        contColor[ color[ act ] ]++;
        for( int i = 0 ; i < ady[ act ].size() ; ++i ){
            if( !color[ ady[ act ][ i ] ] ){
                color[ ady[ act ][ i ] ] = ( color[ act ] == 1 )?2:1;
                Q.push( ady[ act ][ i ] );
            }
            else if( color[ ady[ act ][ i ] ] == color[ act ] ){
                finish = true;
            }
        }
    }
    if( finish ) return 0;
    return max( contColor[ 1 ] , contColor[ 2 ] );
}

int main(){
    int t , k , v , ans;
    scanf("%d" , &t );
    while( t-- ){
        scanf("%d" , &V );
        for( int i = 0 ; i < V && scanf("%d" , &k ) == 1 ; ++i ){
            while( k-- ){
                scanf("%d" , &v );
                if( v - 1 < V ){
                    ady[ i ].push_back( v - 1 );
                    ady[ v - 1 ].push_back( i );
                }
            }
        }
        ans = 0;
        memset( color , 0 , sizeof( color ) );
        for( int i = 0 ; i < V ; ++i ){
            if( color[ i ] ) continue;
            ans += bfs( i );
        }

        printf("%d\n" , ans );
        for( int i = 0 ; i <= V ; ++i ){ ady[ i ].clear(); }
    }

    return 0;
}
