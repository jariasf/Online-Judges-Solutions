/*****************************************
 ***Problema: Route Change
 ***ID: 11833
 ***Juez: UVA
 ***Tipo: Dijkstra
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
#define MAX 300
#define INF 1<<30
struct Edge{
    int v ,w;
    Edge( int vv , int ww ): v( vv ) , w( ww ){}
};
vector< Edge > ady[ MAX ];
int V, C , K, dist[ MAX ];

struct Node{
    int x , d;
    Node( int xx , int dd ): x( xx ) , d( dd ){}
};

struct cmp{
    bool operator() ( Node n1 , Node n2 ){
        return n1.d > n2.d;
    }
};

int dijkstra( int ini ){
    int i , u , v, w;
    priority_queue< Node , vector< Node > , cmp > Q;

    for( i = 0 ; i < V ; ++i ) dist[ i ] = INF;
    Q.push( Node( ini , 0  ) );
    dist[ ini ] = 0;

    while( !Q.empty() ){
        Node act = Q.top() ; Q.pop();
        u = act.x;
        for( i = 0 ; i < ady[ u ].size() ; ++i ){
            v = ady[ u ][ i ].v;
            w = ady[ u ][ i ].w;

            if( u >= 0 && u < C ){
                if( v == u + 1 && dist[ v ] > dist[ u ] + w ){
                    dist[ v ] = dist[ u ] + w;
                    Q.push( Node( v , dist[ v ] ) );
                }
            }
            else if( dist[ v ] > dist[ u ] + w ){
                dist[ v ] = dist[ u ] + w;
                Q.push( Node( v , dist[ v ] ) );
            }
        }
    }
    return dist[ C - 1 ];
}

int main(){
    int E , u , v , w , i;
    while( scanf("%d %d %d %d" , &V , &E , &C , &K ) , V | E | C | K ){
        while( E-- > 0 && scanf("%d %d %d" , &u , &v , &w ) ){
            ady[ u ].push_back( Edge( v , w ) );
            ady[ v ].push_back( Edge( u , w ) );
        }
        printf("%d\n" , dijkstra( K ) );
        for( i = 0 ; i < V ; ++i ) ady[ i ].clear();
    }

    return 0;
}
