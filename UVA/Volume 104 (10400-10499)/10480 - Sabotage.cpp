/*****************************************
 ***Problema: Sabotage
 ***ID: 10480
 ***Juez: UVA
 ***Tipo: Graph Theory, MinCut - Maxflow
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

struct Edge{
    int u, v ,c , r;
    Edge( int uu , int vv , int cc , int rr ): u(uu), v(vv), c(cc), r(rr){ }
};

vector< Edge > E;
vector< vector<int> > ady;
int V;
int maxflow( int source, int sink ){

    for( int flow = 0; ;){
        vector<int> prev( ady.size() , -1);
        queue<int> Q;
        Q.push( source );
        prev[ source ] = 0;
        while( !Q.empty() ){
            int act = Q.front(); Q.pop();

            for( int i = 0 ; i < ady[ act ].size(); ++i ){
                 int e = ady[ act ][ i ];
                 int v = E[ e ].v;
                 if( prev[ v ] >= 0 || E[ e ].c == 0 )continue;
                 prev[ v ] = e;
                 Q.push( v );
            }
        }

        if( prev[ sink ] < 0 ) return flow;
        int c = 0x7ffffff;
        for( int x = sink; x != source ; x = E[ prev[ x ] ].u  ){
             c <?= E[ prev[ x ] ].c;
        }

        for( int x = sink ; x != source ; x = E[ prev[ x ] ].u ){
             E[ prev[ x ] ].c -= c;
             E[ E[ prev[ x ] ].r ].c += c;
        }
        flow += c;
    }
}

#define MAX 60
int visited[ MAX ];
void mincut( int source ){
    visited[ source ] = 1;
    for( int i = 0 ; i < ady[ source ].size(); ++i ){
         if( !visited[ E[ ady[ source ][ i ] ].v ]  && E[ ady[ source ][ i ] ].c ){
             mincut( E[ ady[ source ] [ i ] ].v );
         }
    }
}


void add( int u, int v , int c ){
    Edge e( u , v , c , E.size() + 1 );
    ady[ u ].push_back( E.size() );
    E.push_back( e );
    Edge e2( v , u , c , E.size() - 1 );
    ady[ v ].push_back( E.size() );
    E.push_back( e2 );
}


int main(){
    int V, A, u , v, c;

    while( scanf("%d %d", &V , &A ) && V|A ){
        E.clear();
        ady = vector< vector<int> > ( V + 1 , vector<int>() );
        for( int i = 0 ; i < A ;++i ){
             scanf("%d %d %d", &u, &v , &c );
             add( u , v , c );
        }
        int flow = maxflow( 1 , 2 );

        memset( visited , 0 , sizeof( visited ) );
        mincut( 1 );

        for( int i = 1 ; i <= V ;++i ){
            for( int j = 0 ; j < ady[ i ].size() ;++j ){
                 if( E[ ady[ i ][ j ] ].c  == 0 && visited[ i ] != visited[ E[ ady[ i ][ j ] ].v ] ){
                     printf("%d %d\n", i , E[ ady[ i ][ j ] ].v );
                 }
            }
        }
        printf("\n");
    }


    return 0;
}
