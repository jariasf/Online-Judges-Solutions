/*****************************************
 ***Problema: Clever Naming Patterns
 ***ID: 11418
 ***Juez: UVA
 ***Tipo: Graph Theory, Maximum Bipartite Matching
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

/**
Grafo Bipartito
Lado L son las letras del abecedario A-Z
Lado R numeros de los posibles problemas
El enlace sera el nombre del problema
**/
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
#define MAX 50
int V;
bool seen[ MAX ];
int matchR[ MAX ];
char *matchL[ MAX ], *ady[ MAX ][ MAX ];

bool bpm( int u ){

     for( int v = 0 ; v < V ;++v ){
         if( ady[ u ][ v ] != NULL ){
             if( seen[ v ] )continue;
             seen[ v ] = true;

             if( matchR[ v ] < 0 || bpm( matchR[ v ] ) ){
                 matchR[ v ] = u;
                 matchL[ u ] = ady[ u ][ v ];
                 return true;
             }
         }
     }
     return false;
}

int main(){

    int t, cnt, idx, k;
    scanf("%d", &t );
    char s[ 1000 ];
    for( int q = 1 ; q <= t ; ++q ){

        scanf("%d", &V );
        for( int i = 0 ; i < V ; ++i ){

            scanf("%d", &k );

            for( int j = 0 ; j < k ; ++j ){
                 scanf("%s", s );
                 s[ 0 ] = toupper( s[ 0 ] );
                 for( int v = 1 ; s[ v ] ; ++v ) s[ v ] = tolower( s[ v ] );
                 ady[ s[ 0 ] - 'A'  ][ i ] = strdup( s );
            }
        }
        memset( matchL, -1 , sizeof( matchL ) );
        memset( matchR, -1 , sizeof( matchR ) );
        cnt = 0;
        for( int i = 0 ; i < V ; ++i){
             memset( seen, 0 , sizeof( seen ) );
             if( bpm( i ) )cnt++;
        }
        printf("Case #%d:\n", q );
        for( int i = 0 ; i < V ;++i ){
            printf("%s\n", matchL[ i ]);
        }
        memset( ady, 0 , sizeof( ady ) );
    }
    return 0;
}
