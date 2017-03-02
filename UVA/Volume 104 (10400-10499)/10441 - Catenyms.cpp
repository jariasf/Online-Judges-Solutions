/***********************************************
 ***Problema: Catenyms
 ***ID: 10441
 ***Juez: UVA
 ***Tipo: Graph Theory, Euler Tour, Connectivity
 ***Autor: Jhosimar George Arias Figueroa
 ***********************************************/

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
#define MAX 26
int aux[ MAX ][ MAX ];
vector<string> ady[ MAX ];
int in[ MAX ], out[ MAX ];

int ini;

bool caminoEulerianoDirigido(){
    int cont1 = 0, cont2 = 0 , cont3 = 0;

    for( int i = 0 ; i < MAX ; ++i ){
         if( in[ i ] == out[ i ] + 1 ) { cont1++; }
         if( out[ i ] == in[ i ] + 1 ) { cont2++; ini = i; }
         if( in[ i ] == out[ i ] ) cont3++;
    }
    if( cont1 == 0 && cont2 == 0 ){
        for( int i = 0 ; i < MAX ; ++i ) if( ady[ i ].size() != 0 ){ini = i;break;}
    }
    if( cont3 == MAX || ( cont1 <= 1 && cont2 <= 1 && cont1 + cont2 + cont3 == MAX) ) return true;
    return false;
}

///vemos si es conexo x medio de transitive closure, solo para nodos <= 100
///si es mas usar union find
bool connected(){

    for( int k = 0 ; k < MAX ; ++k ){
        for( int i = 0 ; i < MAX ; ++i ){
            for( int j = 0 ; j < MAX ; ++j ){
                aux[ i ][ j ] |= aux[ i ][ k ] & aux[ k ][ j ];
            }
        }
    }

    for( int i = 0 ; i < MAX ; ++i ){
        for( int j = 0 ; j < MAX ; ++j ){
            if( i != j && in[ i ] + out[ i ] > 0 && in[ j ] + out[ j ] > 0 && !aux[ i ][ j ] ){
                return false;
            }
        }
    }
    return true;
}

int cmp( const void *a , const void *b ){
    char *x = ( char *) a, *y = ( char *) b;
    return -strcmp( x , y );
}


vector<string> resp;
void tour(int x)
{
    while ( ady[ x ].size() > 0) {
        string y = ady[ x ].back();
        ady[ x ].pop_back();
        tour( y[ y.size() - 1 ] - 'a' );
        resp.push_back( y );
    }

}

int main(){

    int t, n;
    scanf("%d", &t );
    char s[ MAX ];
    while( t-- ){

        for( int i = 0 ; i < MAX ; ++i )ady[ i ].clear();
        scanf("%d", &n );

        memset( in , 0 , sizeof( in ) );
        memset( out , 0 , sizeof( out ) );
        memset( aux , 0 ,sizeof( aux ) );

        for( int i = 0 ; i < n ; ++i ){
            scanf("%s", s);
            int u = s[ 0 ] - 'a' , v = s[ strlen( s ) - 1 ] - 'a';
            ady[ u ].push_back(  string( s )  );
            aux[ u ][ v ] = aux[ v ][ u ] = 1;
            out[ u ]++;
            in[ v ]++;
        }
        ///verificamos q sea conexo

        if( !connected() ){
            printf("***\n");
            continue;
        }

        ///verificamos reglas de camino de euler en grafo dirigido

        if( caminoEulerianoDirigido() ){

            for( int i = 0 ; i < MAX ; ++i ) {

                sort( ady[ i ].begin(), ady[ i ].end() );
                reverse( ady[ i ].begin() , ady[ i ].end() );
            }
            resp.clear();
            tour( ini );
            printf("%s", resp[ resp.size() - 1].c_str() );
            for( int i = resp.size() - 2  ; i >= 0 ; --i ){
                printf(".%s", resp[ i ].c_str() );
            }
            printf("\n");

        }
        else printf("***\n");
    }

    return 0;
}
