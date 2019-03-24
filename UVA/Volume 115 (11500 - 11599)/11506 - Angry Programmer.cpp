/*****************************************
 ***Problema: Angry Programmer
 ***ID: 11506
 ***Juez: UVA
 ***Tipo: Graph Theory, MinCut-MaxFlow, Vertes Capacity
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

///para transformar capacidad de vertice a arista
///creo dos vertices Vin y Vout y los conecto
///con capacidad de arista igual a capacidad de vertice
/// para todos los vertices ejemplo 2 ,3
/// 2in con 3out y 2out con 3in
/// ejemplo si tnego 2 ,3
/// 2out = 2 , 3out = 3 le sumo N maximo numero de vertices
/// 2in = 6 , 3in = 7
///entonces coneccion seria 3in-> 2out , 2in->3out
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

                  if( prev[ v ] >= 0 || E[ e ].c == 0) continue;
                  prev[ v ] = e;
                  Q.push( v );
             }
         }
         if( prev[ sink ] < 0 )return flow;

         int c = 0x7ffffff;

         for( int x = sink ; x!=source ; x = E[ prev[ x ] ].u )
              c <?= E[ prev[ x ] ].c;

         for( int x = sink ; x != source ; x = E[ prev[ x ] ].u ){
              E[ prev[ x ] ].c -= c;
              E[ E[ prev[ x ] ].r ].c +=c;
         }

         flow += c;
    }
}

void add( int u , int v , int c, bool undirected = true ){
    Edge e( u , v , c , E.size() + 1 );
    ady[ u ].push_back( E.size() );
    E.push_back( e );

    Edge e2( v ,u , (undirected)?c: 0 , E.size() - 1 );
    ady[ v ].push_back( E.size() );
    E.push_back( e2 );
}

int main(){

    int m, u, c, v, N;

    while( scanf("%d %d", &N, &m) && N|m ){
        E.clear();
        ady = vector< vector<int> > ( N + N + 1  , vector<int> () );

        for( int i = 0 ; i < N - 2 ; ++i ){
            scanf("%d %d", &u ,&c );
            add( u , u + N , c, false );
        }
        while( m-- ){
            scanf("%d %d %d", &u ,&v ,&c );
            /// Uout -> Vin , Vout->Uin
            if( u > 1 && u < N  &&  v > 1 && v < N  ){
                add( u + N , v , c , false );
                add( v + N , u , c , false );
            }
            else if( ( u == 1 || u == N ) && (v > 1 && v < N) ){
                add( u , v , c , false );
                add( v + N , u , c , false );
            }
            else if( ( v == 1 || v == N ) &&( u > 1 && u < N ) ){
                add( u + N , v , c , false  );
                add( v , u , c , false );
            }
            else add( u , v , c , false );
        }
        printf("%d\n", maxflow( 1 , N ) );

    }

    return 0;
}
