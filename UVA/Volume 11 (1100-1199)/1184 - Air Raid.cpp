/*****************************************
 ***Problema: Air Raid
 ***ID: 1184
 ***Juez: UVA
 ***Tipo: Bipartite Matching
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
/*
  Min Path Cover on DAG
  Minimo numero de taxis requeridos para visitar todos los vertices tomando en cuenta
  que cada taxi sirve a 2 vertices a la vez al coger una arista, y que el taxi puede visitar
  otros vertices que continuan a la actual. Tambien cada vertice no puede tener mas de 1 taxi.
*/
#define MAXL 125
#define MAXR 255
int seen[ MAXL ], matchL[ MAXL ] , matchR[ MAXR ];
vector< int > ady[ MAXL ];
int bpm( int left ){
    if( seen[ left ] ) return 0;
    seen[ left ] = 1;
    int right , i;
    for( i = 0 ; i < ady[ left ].size() ; ++i ){
        right = ady[ left ][ i ];
        if( matchR[ right ] == -1 || bpm( matchR[ right ] ) ){
            matchR[ right ] = left;
            matchL[ left ] = right;
            return 1;
        }
    }
    return 0;
}

int main(){
    int t , E , V , u , v , cnt , i;
    scanf("%d" , &t );
    while( t-- > 0 && scanf("%d %d" , &V , &E ) ){
        memset( matchL , -1 , sizeof( matchL ) );
        memset( matchR , -1 , sizeof( matchR ) );
        while( E-- > 0 && scanf("%d %d" , &u , &v ) == 2 ){
            ady[ u - 1 ].push_back( v - 1 + V );
        }
        cnt = 0;
        for( i = 0 ; i < V ; ++i ){
            memset( seen , 0 , sizeof( seen ) );
            if( bpm( i ) ) cnt++;
        }
        printf("%d\n" , V - cnt );
        for( i = 0 ; i <= V ; ++i ) ady[ i ].clear();
    }
    return 0;
}
