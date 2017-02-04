/*****************************************
 ***Problema: Vertex
 ***ID: 280
 ***Juez: UVA
 ***Tipo: Graph Theory, reachability, DFS, BFS
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
#define MAX 200
vector<int> ady[ MAX ];
int visited[ MAX ];

void dfs( int x ){
    for( int i = 0 ; i < ady[ x ].size(); ++i ){
         if( !visited[ ady[ x ][ i ] ] ){
            visited[ ady[ x ][ i ] ] = 1 ;
            dfs( ady[ x ][ i] );
         }
    }
}

int main(){
    int V, n, origen, cont;
    bool b;
    while( scanf( "%d", &V ) && V ){

        while( scanf("%d",&origen) && origen ){
            while( scanf("%d", &n ) && n ){
                ady[ origen ].push_back( n );
            }
        }

        scanf("%d", &n );
        while( n-- ){
            scanf("%d",&origen);
            memset( visited, 0, sizeof( visited) );
            dfs( origen );
            cont = 0;
            for( int i = 1; i <= V ;++i ){
               if( !visited[ i ] )cont++;
            }
            printf("%d",cont);
            for( int i = 1 ; i <= V; ++i ){
               if( !visited[ i ])printf(" %d",i);
            }
            printf("\n");
        }
        for( int i = 0 ; i <= V ;++i )ady[ i ].clear();
    }

    return 0;
}
