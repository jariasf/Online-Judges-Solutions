/*****************************************
 ***Problema: All Roads Lead Where
 ***ID: 10009
 ***Juez: UVA
 ***Tipo: Graph Theory, BFS
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

vector<int> ady[ MAX ];
int prev[ MAX ] , dist[ MAX ];

void bfs( int x, int fin ){
    queue< int > Q;
    memset( dist , -1 , sizeof( dist ) );
    memset( prev , -1 , sizeof( prev ) );
    Q.push( x );
    dist[ x ] = 0;

    while( !Q.empty() ){
        int u = Q.front(); Q.pop();
        if( u == fin )return;
        for( int i = 0 ; i < ady[ u ].size(); ++i ){
            int v = ady[ u ][ i ];
            if( dist[ v ] == -1 ){
                dist[ v ] = dist[ u ] + 1;
                prev[ v ] = u;
                Q.push( v );

            }
        }
    }
}

int main(){
    int t, E, Q;
    scanf("%d" ,&t );
    char s1[ 105 ], s2[ 105 ];
    for( int q = 0 ; q < t ; ++q ){
        if( q )putchar('\n');

        scanf("%d %d", &E, &Q );
        while( E-- ){
            scanf("%s %s", &s1 ,&s2);
            ady[ s1[ 0 ] -'A' ].push_back( s2[ 0 ]-'A' );
            ady[ s2[ 0 ] - 'A' ].push_back( s1[ 0 ] - 'A' );

        }

        while( Q-- ){
            scanf("%s %s", &s1 , &s2 );
            bfs( s1[ 0 ] - 'A' , s2[ 0 ] -'A');
            string resp = "";
            int act = s2[ 0 ]-'A';
            while( 1 ){
                resp += (char)( act + 'A');
                if( act == s1[ 0 ]-'A' )break;
                act = prev[ act ];
            }
            reverse( resp.begin() , resp.end() );
            printf("%s\n", resp.c_str() );

        }
        for( int i = 0 ; i < MAX ; ++i )ady[ i ].clear();
    }

    return 0;
}
