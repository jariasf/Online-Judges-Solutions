/************************************************
 ***Problema: Power Transmision
 ***ID: 10330
 ***Juez: UVA
 ***Tipo: Graph Theory, max flow, vertex capacity
 ***Autor: Jhosimar George Arias Figueroa
 ************************************************/

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
   int u , v , c, r;
   Edge( int uu, int vv , int cc ,int rr): u(uu), v(vv), c(cc), r(rr){}
};

vector< Edge > E;
vector< vector<int > >ady;

int maxflow( int source , int sink ){

    for( int flow = 0; ; ){
         vector<int> prev( ady.size() , -1 );
         queue<int> Q;
         Q.push( source );
         prev[ source ] = 0;
         while( !Q.empty() ){
             int act = Q.front(); Q.pop();
             for( int i = 0 ; i < ady[ act ].size(); ++i ){
                 int e = ady[ act ][ i ], v = E[ e ].v;
                 if( prev[ v ] >= 0 || E[ e ].c == 0 ) continue;
                 prev[ v ] = e;
                 Q.push( v );
             }

         }
         if( prev[ sink ] < 0 )return flow;

         int c = 0x7ffffff;

         for( int x = sink ; x != source ; x = E[ prev[ x ] ].u )
             c <?= E[ prev[ x ] ].c;

         for( int x = sink ; x != source ; x = E[ prev[ x ] ].u ){
             E[ prev[ x ] ].c -= c;
             E[ E[ prev[ x ] ].r ].c += c;
         }
         flow += c;
    }
}

void add( int u , int v , int c ){
     Edge e ( u , v , c , E.size() + 1 );
     ady[ u ].push_back( E.size() );
     E.push_back( e );

     Edge e2( v, u , 0 , E.size() - 1 );
     ady[ v ].push_back( E.size() );
     E.push_back( e2 );
}
#define INF INT_MAX
int main(){
    int N, u , v , c, m, left, right;
    while( scanf("%d", &N) != EOF ){
        E.clear();
        ady = vector< vector<int> > ( N + N + 5 , vector<int>() );
        for( int i = 1 ; i <= N ;++i ){
             scanf("%d", &c );
             add( i , i + N , c );
        }
        scanf("%d",&m);
        for( int i = 0 ; i < m ;++i ){
             scanf("%d %d %d", &u, &v ,&c );
             add( u + N , v , c );
        }
        scanf("%d %d", &left , &right );

        for( int i = 0 ; i < left ; ++i ){
             scanf("%d", &v );
             add( 0 , v , INF );
        }
        for( int i = 0 ; i < right ; ++i ){
             scanf("%d", &v );
             add( v + N , N + N + 2 , INF );
        }
        printf("%d\n", maxflow( 0 , N + N + 2) );

    }

    return 0;
}
