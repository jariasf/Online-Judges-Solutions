/*****************************************
 ***Problema: Test
 ***ID: 10731
 ***Juez: UVA
 ***Tipo: Graph Theory, SCC
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
#define MAX 1000
#define MAXN 26
vector<int> ady[ MAX ];
bool used[ MAXN ] , in_stack[ MAXN ];
int lowlink[ MAXN ] , dfsNum[ MAXN ] , num_scc, scc[ MAXN ] , idx;
stack<int> S;
void tarjan( int v ){

    dfsNum[ v ] = lowlink[ v ] = idx++;
    S.push( v ); in_stack[ v ] = true;

    for( int i = 0 ; i < ady[ v ].size(); ++i ){
        int w = ady[ v ][ i ];
        if( dfsNum[ w ] == -1  ){
            tarjan( w );
            lowlink[ v ] = min( lowlink[ v ] , lowlink[ w ] );
        }
        else if( in_stack[ w ])lowlink[ v ] = min( lowlink[ v ] , lowlink[ w ] );

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
    memset( in_stack , false , sizeof( in_stack ) );
    idx = num_scc = 0;
    for( int i = 0 ; i < MAXN ; ++i ){
        if( used[ i ] && dfsNum[ i ] == -1 )tarjan( i );
    }

}
bool seen[ MAXN ];

int main(){

    int n;
    char c[ 6 ];
    bool b = false;
    while( scanf("%d" ,&n) && n ){
        if( b )printf("\n");
        b = true;
        for( int i = 0 ; i < MAXN ; ++i ) ady[ i ].clear();
        memset( used, 0 , sizeof( used ) );
        memset( seen , 0 ,sizeof( seen ) );
        for( int i = 0 ; i < n ; ++i ){
            scanf("\n%c %c %c %c %c %c", &c[ 1 ], &c[ 2 ], &c[ 3 ] , &c[ 4 ], &c[ 5 ], &c[ 0 ] );
            used[ c[ 0 ]-'A' ] = true;
            for( int j = 1 ; j < 6 ; ++j ){
                used[ c[ j ] - 'A' ] = true;
                if( c[ 0 ] != c[ j ] ){
                    ady[ c[ 0 ] - 'A' ].push_back( c[ j ] - 'A' );
                }
            }

        }
        build_scc();

        for( int i = 0 ; i < MAXN ; ++i ){
            if( used[ i ] && !seen[ i ] ){
                bool first  = true;
                for( int j = i ; j < MAXN ; ++j ){
                    if( !seen[ j ] && used[ j ] && scc[ j ] == scc[ i ] ){
                        ( first )? printf("%c", ( j +'A') ):printf(" %c", (j+'A') );
                        seen[ j ] = true;
                        first = false;
                    }
                }
                printf("\n");
            }
        }
    }

    return 0;
}
