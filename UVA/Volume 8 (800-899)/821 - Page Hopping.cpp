/*****************************************
 ***Problema: Page Hopping
 ***ID: 821
 ***Juez: UVA
 ***Tipo: Graph Theory
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
#define INF 1<<30
int ady[ MAX ][ MAX ], seen[ MAX ];
void init(){
    for( int i = 0 ; i < MAX ; ++i )
        for( int j = 0 ; j < MAX ; ++j )
            ady[ i ][ j ] = ( i == j ) ? 0 : INF;
}

void floyd(){

    for( int k = 0 ; k < MAX ; ++k ){
        if( !seen[ k ] )continue;
        for( int i = 0 ; i < MAX ; ++i ){
            if( !seen[ i ] || ady[ i ][ k ] == INF ) continue;
            for( int j = 0 ; j < MAX ; ++j ){
                if( !seen[ j ] || ady[ k ][ j ] == INF ) continue;
                ady[ i ][ j ] = ( ady[ i ][ j ] > ady[ i ][ k ] + ady[ k ][ j ] )?ady[ i ][ k ] + ady[ k ][ j ] : ady[ i ][ j ];
            }
        }
    }
}

int main(){
    int u , v , q = 1;
    double sum , cnt;
    while( scanf("%d %d" , &u , &v ) , u | v ){
        memset( seen , 0 , sizeof( seen ) );
        seen[ u ] = seen[ v ] = 1;
        init();
        ady[ u ][ v ] = 1;
        while( scanf("%d %d" , &u , &v ) , u | v ){
            ady[ u ][ v ] = 1;
            seen[ u ] = seen[ v ] = 1;
        }
        floyd();
        sum = cnt = 0.0;
        for( int i = 0 ; i < MAX ; ++i ){
            if( !seen[ i ] ) continue;
            for( int j = 0 ; j < MAX ; ++j ){
                if( !seen[ j ] || i == j || ady[ i ][ j ] == INF ) continue;
                cnt++;
                sum += ady[ i ][ j ];
            }
        }
        printf("Case %d: average length between pages = %.3lf clicks\n" , q++ , sum/cnt );
    }

    return 0;
}
