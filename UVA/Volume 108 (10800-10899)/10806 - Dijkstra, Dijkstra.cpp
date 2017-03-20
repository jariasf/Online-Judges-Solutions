/*****************************************
 ***Problema: Dijkstra, Dijkstra.
 ***ID: 10806
 ***Juez: UVA
 ***Tipo: Min-Cost Max-Flow
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
struct Edge{
    int u , v, c;
    long long w;
    Edge( int uu , int vv , int cc , long long ww ): u( uu ) , v( vv ) , c( cc ) , w( ww ){}
};

vector< Edge > E;
vector< int > ady[ MAX ];

long long dist[ MAX ];
int seen[ MAX ] , prev[ MAX ];
bool augmentPath( int source , int sink ){

    int i , u , v , c;
    long long w;

    for( i = 0 ; i <= sink ; ++i ){
        dist[ i ] = INF;
        seen[ i ] = 0;
        prev[ i ] = -1;
    }
    queue< int > Q;
    Q.push( source );
    dist[ source ] = 0;

    while( !Q.empty() ){
        u = Q.front(); Q.pop();
        seen[ u ] = 0;

        for( i = 0 ; i < ady[ u ].size() ; ++i ){
            v = E[ ady[ u ][ i ] ].v;
            c = E[ ady[ u ][ i ] ].c;
            w = E[ ady[ u ][ i ] ].w;
            if( dist[ v ] > dist[ u ] + w&& c > 0 ){
                dist[ v ] = dist[ u ] + w;
                prev[ v ] = ady[ u ][ i ];
                if( !seen[ v ] ){
                    seen[ v ] = 1;
                    Q.push( v );
                }
            }
        }
    }

    return dist[ sink ] != INF;
}

long long mc , mf;
void mcmf( int source , int sink ){
    mc = mf = 0;
    int mini , x;

    while( augmentPath( source , sink ) ){
        mini = INF;
        for( x = sink ; prev[ x ] != -1 ; x = E[ prev[ x ] ].u ){
            mini = min( mini , E[ prev[ x ] ].c );
        }

        for( x = sink ; prev[ x ] != -1 ; x = E[ prev[ x ] ].u ){
            E[ prev[ x ] ].c -= mini;
            E[ prev[ x ] ^ 1 ].c += mini;
        }
        mf += mini;
        mc += mini * dist[ sink ];
    }
}

void add( int u , int v , int c , long long w ){
    Edge e= Edge( u , v , c , w );
    ady[ u ].push_back( E.size() );
    E.push_back( e );
    e = Edge( v , u , 0 , -w );
    ady[ v ].push_back( E.size() );
    E.push_back( e );
}

int main(){

    int V ,EE , u , v , i;
    long long w;
    while( scanf("%d" , &V ) , V ){
        scanf("%d" , &EE );
        while( EE-- > 0 && scanf("%d %d %lld" , &u , &v , &w ) == 3 ){
            add( u , v , 1 , w );
            add( v , u , 1 , w );
        }

        add( 0 , 1 , 2 , 0 );
        mcmf( 0 , V );
        if( mf != 2 ) puts("Back to jail");
        else printf("%lld\n"  , mc );

        for( i = 0 ; i <= V ; ++i ) ady[ i ].clear();
        E.clear();
    }

    return 0;
}
