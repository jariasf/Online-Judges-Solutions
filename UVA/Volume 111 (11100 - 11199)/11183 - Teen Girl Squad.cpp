/*****************************************
 ***Problema: Teen Girl Squad
 ***ID: 11183
 ***Juez: UVA
 ***Tipo: Graph Theory - MCA
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
#define INF 1<<30
#define MAX 1005
int C[ MAX ][ MAX ]; //costo de arista
int  root, V, MCA, prev[ MAX ];
bool seen[ MAX ], cycle[ MAX ];


void add_edge( int u , int v , int w ){
    C[ u ][ v ] = min( C[ u ][ v ] , w );
}

///dfs para ver conectividad
void dfs( int u ){
    seen[ u ] = 1;
    for( int i = 0 ; i < V; ++i ){
        if( !seen[ i ] && C[ u ][ i ] != INF ){
            dfs( i );
        }
    }
}

///vemos si todo el grafo es conexo
bool connected(){
    memset( seen , 0 , sizeof( seen ) );
    dfs( root );
    for( int i = 0 ; i < V ; ++i ){
        if( !seen[ i ] )return false;
    }
    return true;
}

int exist_cycle(){
    prev[ root ] = root;

    for( int i = 0 ; i < V ; ++i ){

        if( !cycle[ i ] && i != root ){
            prev[ i ] = i; C[ i ][ i ] = INF;
            ///elijo arista que ingresa a nodo con el menor costo
            for( int j = 0 ; j < V ; ++j ){
                if( !cycle[ j ] &&  C[ j ][ i ] < C[ prev[ i ] ][ i ] )
                    prev[ i ] = j;
            }
        }
    }

    ///una vez elejidas las aristas q ingresan a un nodo con menor peso
    ///vemos si se formo ciclo
    for( int i = 0 , j ; i < V ; ++i ){

        if( cycle[ i ] )continue;
        memset( seen , 0 , sizeof( seen ) );
        j = i;

        while( !seen[ j ] ){
            seen[ j ] = true;
            j = prev[ j ];
        }
        ///no ciclo
        if( j == root )continue;
        return j;
    }
    return -1;
}


void update( int v ){
    MCA += C[ prev[ v ] ][ v ];
    ///hallo MCA de ciclo y marco todos los nodos pertenecientes al cuclo
    for( int i = prev[ v ] ; i != v ; i = prev[ i ] ){
        MCA += C[ prev[ i ] ][ i ];
        cycle[ i ] = true;
    }

    for( int i = 0 ; i < V ; ++i ){
        if( !cycle[ i ] && C[ i ][ v ] != INF )
            C[ i ][ v ] -= C[ prev[ v ] ][ v ];
    }

    for( int j = prev[ v ] ; j != v ; j = prev[ j ] ){
        for( int i = 0 ; i < V ; ++i ){
            if( !cycle[ i ] && C[ i ][ j ] != INF ){
                C[ i ][ v ] = min( C[ i ][ v ] , C[ i ][ j ] - C[ prev[ j ] ][ j ] );
            }
            C[ v ][ i ] = min( C[ j ][ i ] , C[ v ][ i ] );
        }
    }

}

bool min_cost_arborescence( ){

    if( !connected() )return false;

    memset( cycle , false , sizeof( cycle ) );
    MCA = 0;

    int v;
    while( ( v = exist_cycle() ) != -1 ){
        update( v );
    }
    for( int i = 0 ; i < V ; ++i ){
        if( i != root && !cycle[ i ] ){
            MCA += C[ prev[ i ] ][ i ] ;
        }
    }

    return true;
}

int main(){
    int t, A, u , v , w;
    scanf("%d" , &t );
    for( int q = 1 ; q <= t ; ++q ){
        scanf("%d %d" , &V , &A );
        for( int i = 0 ; i < V ; ++i )
            for( int j = 0 ; j < V ; ++j )
                C[ i ][ j ] = INF;


        while( A-- ){
            scanf("%d %d %d" , &u , &v, &w );
            add_edge( u , v , w );
        }
        printf("Case #%d: ", q );
        root = 0;
        if( !min_cost_arborescence() )printf("Possums!\n");
        else printf("%d\n" , MCA );
    }

    return 0;
}
