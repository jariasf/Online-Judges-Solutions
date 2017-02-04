/*****************************************
 ***Problema: Calling Circles
 ***ID: 247
 ***Juez: UVA
 ***Tipo: Graph Theory, Strongly Connected Components
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

#define MAX 50
vector<int> ady[ MAX ];
int dfsNum[ MAX ] , lowlink[ MAX ] , scc[ MAX ], num_scc, V , idx;
bool in_stack[ MAX ];
stack<int> S;

void tarjan( int v ){
    dfsNum[ v ] = lowlink[ v ] = idx++;
    S.push( v ); in_stack[ v ] = true;

    for( int i = 0 ; i < ady[ v ].size(); ++i ){
        int w = ady[ v ][ i ];
        if( dfsNum[ w ] == -1 ){
            tarjan( w );
            lowlink[ v ] = min( lowlink[ v ] , lowlink[ w ] );

        }else if( in_stack[ w ] )lowlink[ v ] = min( lowlink[ v ] , lowlink[ w ] );
    }

    if( dfsNum[ v ] == lowlink[ v ] ){
        int aux;

        do{
            aux = S.top(); S.pop();
            scc[ aux ] = num_scc;
            in_stack[ aux ] = false;
        }while( aux != v );
        num_scc++;
    }
}

void build_scc(){
    memset( dfsNum , -1 , sizeof( dfsNum ) );
    memset( in_stack , 0 , sizeof( in_stack ) );
    idx = num_scc = 0;
    for( int i = 0 ; i < V ; ++i ){
        if( dfsNum[ i ] == -1 )tarjan( i );
    }
}

int main(){
    int E, t = 1;
    char s1[ 30 ] , s2[ 30 ];
    while( scanf("%d %d",&V,&E) && V|E ){
        if( t > 1 )printf("\n");
        map<string , int > mp;
        map<int , string > mp2;
        for( int i = 0 ; i < V ; ++i )ady[ i ].clear();
        V = 0;

        while( E-- ){
            scanf("%s %s", s1 , s2 );
            if( mp.find( s1 ) == mp.end() ){
                mp2[ V ] = s1;
                mp[ s1 ] = V++;
            }
            if( mp.find( s2 ) == mp.end() ){
                mp2[ V ] = s2;
                mp[ s2 ] = V++;
            }
            ady[ mp[ s1 ] ].push_back( mp[ s2 ] );
        }
        build_scc();
        printf("Calling circles for data set %d:\n", t++);
        for( int i  = 0; i < num_scc ; ++i ){
            bool first = true;
            for( int j = 0 ; j < V ; ++j ){
                if( scc[ j ] == i ){
                    ( first )? printf( "%s", mp2[ j ].c_str() ) : printf(", %s" , mp2[ j ].c_str() );
                    first = false;
                }
            }
            printf("\n");

        }
    }
    return 0;
}
