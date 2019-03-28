/*****************************************
 ***Problema: Krochanska is Here
 ***ID: 11792
 ***Juez: UVA
 ***Tipo: Graph Theory, BFS, Shortest Path
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

#define MAX 10005
vector<int> ady[ MAX ];
int freq[ MAX ] , d[ MAX ] , V;

int bfs( int x ){
    memset( d , -1 , sizeof( d ) );
    queue<int> Q;
    Q.push( x );
    d[ x ] = 0;
    while( !Q.empty() ){
        int act = Q.front(); Q.pop();
        for( int i = 0 ; i < ady[ act ].size(); ++i ){
             int w = ady[ act ][ i ];
             if( d[ w ] == -1 ){
                 d[ w ] = d[ act ] + 1;
                 Q.push( w );
             }
        }
    }
    int cost = 0;
    for( int i = 1 ; i <= V ; ++i ){
        if( freq[ i ] >= 2 ){
            cost += d[ i ];
        }
    }
    return cost;

}

int main(){
    int t , L , prev, act, min, cost , idx;
    scanf("%d", &t);
    while( t-- ){
        memset( freq , 0 ,sizeof( freq ) );

        scanf( "%d %d" , &V , &L );
        while( L-- ){
            scanf("%d" , &prev );
            freq[ prev ]++;
            while( scanf("%d" , &act ) && act ){
                ady[ act].push_back( prev );
                ady[ prev ].push_back( act );
                prev = act;
                freq[ act ]++;
            }
        }
        min = 1<<20;
        ///si esta en mas de 2 lineas
        for( int i = 1 ; i <= V ; ++i ){
            if( freq[ i ] >= 2 ){
                cost = bfs( i );
                if( min > cost ){
                    min = cost;
                    idx = i;
                }
            }
        }
        printf("Krochanska is in: %d\n",idx);
        for( int i = 0 ; i <= V ; ++i )ady[ i ].clear();
    }


    return 0;
}
