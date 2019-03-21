/*****************************************
 ***Problema: Wedding
 ***ID: 11294
 ***Juez: UVA
 ***Tipo: 2-SAT
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
#define MAX 2 * 105
int V , dfsNum[ MAX ] , low[ MAX ] , scc[ MAX ] , num_scc , num, seen[ MAX ];
stack< int > S;
vector< int > ady[ MAX ];

void dfs( int x ){
    dfsNum[ x ] = low[ x ] = num++;
    seen[ x ] = 1;
    S.push( x );
    for( int i = 0 ; i < ady[ x ].size() ; ++i ){
        int y = ady[ x ][ i ];
        if( dfsNum[ y ] == -1 ){
            dfs( y );
            low[ x ] = min( low[ x ] , low[ y ] );
        }
        else if( seen[ y ] ){
            low[ x ] = min( low[ x ] , low[ y ] );
        }
    }

    if( dfsNum[ x ] == low[ x ] ){
        int y;
        do{
            y = S.top(); S.pop();
            scc[ y ] = num_scc;
            seen[ y ] = 0;
        }while( x != y );
        num_scc++;
    }
}

void build_scc(){

    memset( seen , 0 , sizeof( seen ) );
    memset( dfsNum , -1 , sizeof( dfsNum ) );
    num = num_scc = 0;

    for( int i = 0 ; i < 2 * V ; ++i ){
         if( dfsNum[ i ] == -1 ) dfs( i );
    }

    while( !S.empty() ){ S.pop(); }
}

int NOT( int x ){
    return ( x < V )? x + V : x - V;
}

int degree[ MAX ], notSCC[ MAX ];
vector< int > G[ MAX ];
int val[ MAX ];
void topologicalSort(){
    queue< int > Q;
    memset( val , 0 , sizeof( val ) );
    for( int i = 0 ; i < num_scc ; ++i ){
        if( degree[ i ] == 0 ) Q.push( i );
    }

    while( !Q.empty() ){
        int x = Q.front(); Q.pop();
        if( val[ x ] == 0 ){
            val[ x ] = 1;
            val[ notSCC[ x ] ] = -1;
        }

        for( int i = 0 ; i < G[ x ].size() ; ++i ){
            int y = G[ x ][ i ];
            degree[ y ]--;
            if( degree[ y ] == 0 ) Q.push( y );
        }
    }
}

int main(){
    int u , v , E , i;
    char cu , cv;
    while( scanf("%d %d" , &V , &E ) , V | E ){
        for( i = 0 ; i < E ; ++i ){
            scanf("%d%c %d%c" , &u , &cu , &v , &cv );
            if( cu == 'w' ) u = NOT( u );
            if( cv == 'w' ) v = NOT( v );
            ady[ NOT( u ) ].push_back( v );
            ady[ NOT( v ) ].push_back( u );
        }
        ady[ 0 ].push_back( NOT( 0 ) );
        build_scc();
        memset( notSCC , 0 , sizeof( notSCC ) );
        for( i = 0 ; i < V ; ++i ){
            if( scc[ i ] == scc[ NOT( i ) ] ) break;
        }

        if( i != V ) printf("bad luck\n");
        else{
            bool first = true;
            for( i = 1 ; i < V ; ++i ){
                if( !first )printf(" ");
                if( scc[ i ] > scc[ NOT( i ) ] )printf("%dw" , i );
                else printf("%dh" , i );
                first = false;
            }
            printf("\n");
        }
        for( i = 0 ; i < 2 * V ; ++i ) ady[ i ].clear();
    }

    return 0;
}
