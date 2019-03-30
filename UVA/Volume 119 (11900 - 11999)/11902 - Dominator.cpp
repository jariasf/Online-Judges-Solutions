/*****************************************
 ***Problema: Dominator
 ***ID: 11902
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
#define MAX 105
vector< int > ady[ MAX ];
int n;
int degree[ MAX ], domina[ MAX ][ MAX ];
int reach[ MAX ];
void dfs1( int x ){
    reach[ x ] = 1;
    int i;
    for( i = 0 ; i < ady[ x ].size() ; ++i ){
        if( !reach[ ady[ x ][ i ] ] ) dfs1( ady[ x ][ i ] );
    }
}

int seen[ MAX ], visito[ MAX ];

//elimino un nodo y veo a cuales puedo llegar partiendo de 0 sino exisitiese ese nodo
//kiere decir que los nodos que visite en este dfs seran los nodos NO DOMINADOS POR el nodo eliminado
//puesto que estamos hallando otra ruta posible
void dfs2( int x ){
    if( seen[ x ] ) return;
    visito[ x ] = 1;
    seen[ x ] = 1;
    for( int i = 0 ; i < ady[ x ].size() ; ++i ){
        if( !seen[ ady[ x ][ i ] ] ) dfs2( ady[ x ][ i ] );
    }
}

int main(){
    int t , q , len , x , i , j , k;
    scanf("%d" , &t );
    for( q = 1 ; q <= t ; ++q ){
        scanf("%d" , &n );
        memset( degree , 0 , sizeof( degree ) );
        for( i = 0 ; i < n ; ++i ){
            for( j = 0 ; j < n && scanf("%d" , &x ) ; ++j ){
                if( x ) ady[ i ].push_back( j );
            }
        }
        printf("Case %d:\n" , q );
        memset( reach , 0 , sizeof( reach ) );
        dfs1( 0 );

        memset( domina , 0 , sizeof( domina ) );
        memset( seen , 0 , sizeof( seen ) );

        for( i = 0 ; i < n ; ++i ){
            if( !reach[ i ] ) continue;
            domina[ i ][ i ] = 1;
            memset( seen , 0  ,sizeof( seen ) );
            seen[ i ] = 1;
            memset( visito , 0 , sizeof( visito ) );
            dfs2( 0 );
            for( j = 0 ; j < n ; ++j ){
                if( !visito[ j ] && reach[ j ] ) domina[ i ][ j ] = 1;
            }
        }

        len = n + n - 1;
        putchar('+');
        for( i = 0 ; i < len ; ++i ) printf("-");
        puts("+");

        for( i = 0 ; i < n ; ++i ){
            for( j = 0 ; j < n ; ++j ){
                printf("|%c" , ( domina[ i ][ j ] )?'Y': 'N' );
            }
            puts("|");

            putchar('+');
            for( j = 0 ; j < len ; ++j ) printf("-");
            puts("+");
        }

        for( i = 0 ; i <= n ; ++i ) ady[ i ].clear();
    }

    return 0;
}
