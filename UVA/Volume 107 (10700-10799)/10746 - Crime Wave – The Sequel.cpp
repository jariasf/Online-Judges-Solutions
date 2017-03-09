/*****************************************
 ***Problema: Crime Wave -The Sequel
 ***ID: 10746
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
#define MAX 50
#define INF 1<<30
#define EPS 1e-8
struct Edge{
    int u , v, c;
    double w;
    Edge( int uu , int vv , int cc , double ww ): u( uu ) , v( vv ) , c( cc ) , w( ww ){}
};

vector< Edge > E;
vector< int > ady[ MAX ];

double dist[ MAX ];
int seen[ MAX ] , prev[ MAX ];
bool augmentPath( int source , int sink ){

    int i , u , v , c;
    double w;

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
            if( dist[ v ] > dist[ u ] + w + EPS && c > 0 ){
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

double mcmf( int source , int sink ){
    double mc = 0;
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
        mc += mini * dist[ sink ];
    }
    return mc;
}

void add( int u , int v , int c , double w ){
    Edge e= Edge( u , v , c , w );
    ady[ u ].push_back( E.size() );
    E.push_back( e );
    e = Edge( v , u , 0 , -w );
    ady[ v ].push_back( E.size() );
    E.push_back( e );
}

int main(){

    int n , m , source = 0 , sink , i,  j;
    double w;
    while( scanf("%d %d" , &n , &m ) , n | m ){
        sink = n + m + 5;
        for( i = 1 ; i <= n ; ++i ){
            for( j = 1 ; j <= m && scanf("%lf" , &w ) == 1 ; ++j ){
                add( i , n + j , 1 , w );
            }
            add( source , i , 1 , 0.0 );
        }

        for( j = 1 ; j <= m ; ++j ) add( j + n , sink , 1 , 0.0 );
        printf("%.2lf\n" , mcmf( source , sink )/(double)n + EPS );
        for( i = 0 ; i <= sink ; ++i ) ady[ i ].clear();
        E.clear();
    }

    return 0;
}
