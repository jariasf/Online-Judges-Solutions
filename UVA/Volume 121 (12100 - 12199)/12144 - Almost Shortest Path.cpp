/*****************************************
 ***Problema: Almost Shortest Path
 ***ID: 12144
 ***Juez: UVA
 ***Tipo: Graph Theory, Shortest Path
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


#define MAX 501
#define INF (1<<25)
#define pii pair< int, int >
#define pb push_back

struct comp {
    bool operator() (const pii &a, const pii &b) {
        return a.second > b.second;
    }
};

int D[ MAX ];
bool F[ MAX ];
int V;
vector<pii> ady[ MAX ], inv[ MAX ];
bool deleted[ MAX ][ MAX ];
void dijkstra( int S ){
    priority_queue< pii , vector<pii> , comp > Q;
    for( int i = 0 ; i < V ; ++i ){
        F[ i ] = false;
        D[ i ] = INF;
    }
    D[ S ] = 0;
    int u , v , w;
    Q.push( pii( S , 0 ) );
    while( !Q.empty() ){
        u = Q.top().first;
        Q.pop();
        if( F[ u ] )continue;
        for( int i = 0 ; i < ady[ u ].size() ; ++i ){
            v = ady[ u ][ i ].first;
            if( deleted[ u ][ v ] || deleted[ v ][ u ])continue;
            w = ady[ u ][ i ].second;
            if( !F[ v ] && D[ u ] + w < D[ v ] ){
                D[ v ] = D[ u ] + w;
                Q.push( pii( v , D[ v ] ) );
            }
        }
        F[ u ] = true;
    }
}

int path[ MAX ];
void dfs( int u , int S , int len ){

    path[ len ] = u;
    if( u == S ){
        //elimino shortest path
        for( int i = len ; i > 0 ; --i ){
            deleted[ path[ i ] ][ path[ i - 1 ] ] = true;
            deleted[ path[ i - 1 ] ][ path[ i ] ] = true;
        }
        return;
    }
    F[ u ] = true;
    for( int i = 0 ; i < inv[ u ].size() ; ++i ){
        int v = inv[ u ][ i ].first, w = inv[ u ][ i ].second;
        //si minimas distancias cumplen
        if( !F[ v ] && D[ v ] + w == D[ u ] ){
            dfs( v , S , len + 1 );
        }
    }
    F[ u ] = false;
}

int main(){
    int Edges , S , E , u , v, w;
    while( scanf("%d %d" , &V , &Edges ) , Edges | V ){
        scanf("%d %d" , &S , &E );

        while( Edges-- ){
            scanf("%d %d %d" , &u , &v , &w );
            ady[ u ].pb( pii( v , w ) );
            inv[ v ].pb( pii( u , w ) );
        }
        memset(deleted , 0 , sizeof( deleted ));
        dijkstra( S );
        memset( F , 0 , sizeof( F ) );
        dfs( E , S , 0 );
        dijkstra( S );
        if( D[ E ] == INF ) printf("-1\n");
        else printf("%d\n" , D[ E ] );
        for( int i = 0 ; i < V ; ++i ){
            ady[ i ].clear();
            inv[ i ].clear();
        }
    }
    return 0;
}
