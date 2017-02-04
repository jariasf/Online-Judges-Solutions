/*****************************************
 ***Problema: FireTruck
 ***ID: 208
 ***Juez: UVA
 ***Tipo: DFS
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

int V , cnt , end ;
#define MAX 25
int ady[ MAX ][ MAX ], G[ MAX ][ MAX ];
map<int , bool> _seen;
bool seen[ MAX ];
int path[ MAX ];

void TransitiveClosure(){
    for( int k = 1; k <= V ; ++k )
        for( int i = 1 ; i <= V ; ++i )
            for( int j = 1 ; j <= V ; ++j )
                ady[ i ][ j ] |= ( ady[ i ][ k ] & ady[ k ][ j ] );
}

void solve( int u , int len ){
    path[ len ] = u;
    if( u == end ){
        for( int i = 0 ; i <= len ; ++i ){
            if( i )
                printf(" ");
            printf("%d" , path[i]);
        }
        printf("\n");
        cnt++;
        return;
    }

    for( int i = 1 ; i <= V ; ++i ){
        if( !seen[ i ] && ady[ i ][ end ] && G[u][i] ){
            seen[ i ] = 1;
            solve( i  , len + 1 );
            seen[ i ] = 0;
        }
    }

}

int main(){
    int t = 1 , u , v;
    while( scanf("%d" , &end ) != EOF ){
        memset( ady , 0 , sizeof( ady ) );
        memset( G , 0 , sizeof( G ) );
        while( scanf("%d %d" , &u , &v ) , u|v ){
            ady[ u ][ v ] = ady[ v ][ u ] = 1;
            G[u][v] = G[v][u] = 1;
            V= max( V , max(u , v) );
        }
        TransitiveClosure();
        printf("CASE %d:\n" , t++ );
        memset( seen , 0 , sizeof( seen ) );
        cnt = 0;
        seen[ 1 ] = 1;
        path[0] = 1;
        solve( 1 , 0 );

        printf("There are %d routes from the firestation to streetcorner %d.\n" , cnt , end );
    }

    return 0;
}
