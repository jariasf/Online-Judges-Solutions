/*****************************************
 ***Problema: XYZZY
 ***ID: 10557
 ***Juez: UVA
 ***Tipo: Bellman Ford
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
#define pii pair< int , int >
#define mp make_pair
#define pb push_back
int V, cost[ MAX ] , dist[ MAX ] , seen[ MAX ];
vector< int > ady[ MAX ];

//Para conectividad
void dfs( int x ){
    seen[ x ] = 1;
    for( int i = 0 ; i < ady[ x ].size() ; ++i ){
        if( !seen[ ady[ x ][ i ] ] ){
            dfs( ady[ x ][ i ] );
        }
    }
}

void bellmanFord(){
    int i , k , j , v;

    for( i = 0 ; i < V ; ++i ) dist[ i ] = -1<<30;
    dist[ 0 ] = 100;

    for( k = 0 ; k < V - 1 ; ++k ){
        for( i = 0 ; i < V ; ++i ){
            for( j = 0 ; j < ady[ i ].size() ; ++j ){
                v = ady[ i ][ j ];
                if( dist[ i ] > 0 && dist[ v ] < dist[ i ] + cost[ v ] ){
                    dist[ v ] = dist[ i ] + cost[ v ];
                }
            }
        }
    }

    //Verifico ciclo positivo
    int node = -1;
    bool positive = false;
    for( i = 0 ; i < V ; ++i ){
        for( j = 0 ; j < ady[ i ].size() ; ++j ){
            v = ady[ i ][ j ];
            if( dist[ i ] > 0 && dist[ v ] < dist[ i ] + cost[ v ] ){
                dist[ v ] = dist[ i ] + cost[ v ];
                positive = true;
                node = v;
            }
        }
        seen[ i ] = 0;
    }

    //Si tengo ciclo positivo, veo si a partir de ese ciclo llego al destino
    //si es posible entonces winnable
    if( positive ){
        dfs( node );
        if( seen[ V - 1 ] ){
            puts("winnable");
            return;
        }
    }

    //si llegue al destino con energias gano
    if( dist[ V - 1 ] > 0 ) puts("winnable");
    else puts("hopeless");
}

int main(){
    int i , k , v;
    while( scanf("%d" , &V ) , V != -1 ){

        for( i = 0 ; i < V && scanf("%d %d" , &cost[ i ] , &k ); ++i ){
            while( k-- > 0 && scanf("%d" , &v ) ){
                ady[ i ].pb( v - 1 );
            }
            seen[ i ] = 0;
        }
        dfs( 0 );
        if( !seen[ V - 1 ] ) puts("hopeless");
        else bellmanFord();
        for( i = 0 ; i < V ; ++i ) ady[ i ].clear();
    }
    return 0;
}
