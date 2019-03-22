/*****************************************
 ***Problema: Claw Decomposition
 ***ID: 11396
 ***Juez: UVA
 ***Tipo: Bipartite Check
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
#define MAX 305
int V;
vector< int > ady[ MAX ];
int color[ MAX ];
bool bfs( int inicial ){
    int act;
    queue< int > Q;
    Q.push( inicial );
    color[ inicial ] = 1;
    while( !Q.empty() ){
        act = Q.front(); Q.pop();
        for( int i = 0 ; i < ady[ act ].size() ; ++i ){
            if( !color[ ady[ act ][ i ] ] ){
                color[ ady[ act ][ i ] ] = ( color[ act ] == 1 )?2:1;
                Q.push( ady[ act ][ i ] );
            }
            else if( color[ ady[ act ][ i ] ] == color[ act ] ){
                return false;
            }
        }
    }
    return true;
}

int main(){
    int V, u , v;
    while( scanf("%d" , &V ) , V ){
        while( scanf("%d %d" , &u , &v ) , v| u ){
            ady[ u - 1 ].push_back( v - 1 );
            ady[ v - 1 ].push_back( u - 1 );
        }
        memset( color , 0 , sizeof( color ) );
        if( bfs(  0) ) puts("YES");
        else puts("NO");
        for( int i = 0 ; i <= V ; ++i ) ady[ i ].clear();
    }
    return 0;
}
