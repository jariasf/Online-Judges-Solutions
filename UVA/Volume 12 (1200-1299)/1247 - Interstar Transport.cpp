/*****************************************
 ***Problema: Interstar Transport
 ***ID: 1247
 ***Juez: UVA
 ***Tipo: Floyd Warshall
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
#define MAX 27
#define INF 10000
int V , ady[ MAX ][ MAX ] , path[ MAX ][ MAX ], intermediate[ MAX ][ MAX ];

void init(){

    for( int i = 0 ; i < V ; ++i ){
        for( int j = 0 ; j < V ; ++j ){
            ady[ i ][ j ] = ( i == j )?0:INF;
        }
    }
}

void init2(){
    for( int i = 0 ; i < V ; ++i ){
        for( int j = 0 ; j < V ; ++j ){
            if( ady[ i ][ j ] == INF || ady[ i ][ j ] == 0 ){ path[ i ][ j ] = 0; intermediate[ i ][ j ] = INF;  }
            else path[ i ][ j ] = i, intermediate[ i ][ j ] = 0;
            intermediate[ i ][ j ] = 0;
        }
    }
}

void floyd(){

    for( int k = 0 ; k < V ; ++k ){
        for( int i = 0 ; i < V ; ++i ){
            if( ady[ i ][ k ] == INF ) continue;
            for( int j = 0 ; j < V ; ++j ){
                if( ady[ k ][ j ] != INF){
                    if( ady[ i ][ k ] + ady[ k ][ j ] < ady[ i ][ j ] ){
                        ady[ i ][ j ] = ady[ i ][ k ] + ady[ k ][ j ];
                        path[ i ][ j ] = path[ k ][ j ];
                        intermediate[ i ][ j ] = intermediate[ i ][ k ] + intermediate[ k ][ j ] + 1;
                    }
                    else if( ady[ i ][ k ] + ady[ k ][ j ] == ady[ i ][ j ] ){
                        if( intermediate[ i ][ j ] > intermediate[ i ][ k ] + intermediate[ k ][ j ] + 1 ){
                            intermediate[ i ][ j ] = intermediate[ i ][ k ] + intermediate[ k ][ j ] + 1;
                            path[ i ][ j ] = path[ k ][ j ];
                        }
                    }
                }
            }
        }
    }
}

void print( int x , int y ){
    if( x == INF || y == INF ) return;
    if( x == y ) printf("%c" , x + 'A' );
    else{
        print( x , path[ x ][ y ] );
        printf(" %c" , y + 'A');
    }
    return;
}

int main(){
    char u , v;
    int E , w , Q;
    scanf("%d %d" , &V , &E );
    init();
    for( int i = 0 ; i < E && scanf(" %c %c %d" , &u , &v , &w ) ; ++i ){
        ady[ u - 'A'  ][ v - 'A'  ] = ady[ v - 'A'  ][ u - 'A'  ] = w;
    }
    init2();
    floyd();
    scanf("%d" , &Q );
    while( Q-- ){
        scanf(" %c %c" , &u , &v );
        print( u - 'A'  , v - 'A' );
        printf("\n");
    }
    return 0;
}

/*
5 6
A B 1
B C 1
C D 1
A D 6
E A 1
E D 2
1
A D
*/
