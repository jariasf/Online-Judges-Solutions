/*****************************************
 ***Problema: Triangle Counting
 ***ID: 10973
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

#define MAX 3005
vector<int> ady[ MAX ];
int graph[ MAX ][ MAX ];
int V;
int main(){
    int t ,  E , u , v, cont;
    scanf( "%d" , &t );

    while( t-- ){
        scanf("%d %d" , &V , &E );
        memset( graph , 0, sizeof( graph ) );

        cont = 0;
        while( E-- ){
            scanf( "%d %d" , &u , &v );
            if( v > u )ady[ u ].push_back( v ) , graph[ u ][ v ] = 1;
            if( u > v )ady[ v ].push_back( u ) , graph[ v ][ u ] = 1;
        }

        for( int i = 1 ; i <= V ; ++i ){
            for( int j = 0 ; j < ady[ i ].size() ; ++j ){
                for( int k = 0 ; k < ady[ ady[ i ][ j ] ].size() ; ++k ){
                    if( graph[ i ][ ady[ ady[ i ][ j ] ][ k ] ] ){
                        cont++;
                    }
                }
            }
        }

        printf("%d\n" , cont );
        for( int i = 1 ; i <= V ; ++i )ady[ i ].clear();
    }

    return 0;
}
