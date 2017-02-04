/*****************************************
 ***Problema: Software Allocation
 ***ID: 259
 ***Juez: UVA
 ***Tipo: Max Flow || Maximum Bipartite Matching
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
#define MAX 40
#define INF 1<<30

int c[ MAX ][ MAX ];
char line[ 30 ], programs[ 15 ];
int prev[ MAX ] , seen[ MAX ];
bool augmentPath( int source , int sink ){
    queue< int > Q;
    Q.push( source );
    memset( seen , 0 , sizeof( seen ) );
    seen[ source ] = 1;
    prev[ source ] = -1;
    int u , v;
    while( !Q.empty() ){
        u = Q.front(); Q.pop();
        if( u == sink ) return true;
        for( v = 0 ; v < MAX ; ++v ){
            if( c[ u ][ v ] > 0 && !seen[ v ] ){
                seen[ v ] = 1;
                prev[ v ] = u;
                Q.push( v );
            }
        }
    }
    return false;
}

int ans[ MAX ];
int maxflow( int source , int sink ){
    int flow = 0 , x , mini;
    while( augmentPath( source , sink ) ){
        mini = INF;
        for( x = sink ; prev[ x ] != -1 ; x = prev[ x ] ){
            mini = min( mini , c[ prev[ x ] ][ x ] );
        }
        for( x = sink ; prev[ x ] != -1 ; x = prev[ x ] ){
            c[ prev[ x ] ][ x ] -= mini;
            c[ x ][ prev[ x ] ] += mini;
        }
        flow += mini;
    }
    return flow;
}


int main(){
    char computer;
    int users , len , source = 38 , sink = 39, i , mf , totUsers , j;
    while( gets( line ) ){

        sscanf( line , "%c%d %s" , &computer , &users , &programs );
        len = strlen( programs );
        totUsers = users;
        memset( c , 0 , sizeof( c ) );
        for( i = 0 ; i < len - 1 ; ++i ){
            c[ computer - 'A' + 10 ][ programs[ i ] - '0' ] = 1;
            c[ programs[ i ] - '0' ][ sink ] = 1;
        }

        c[ source ][ computer - 'A' + 10 ] += users;
        while( gets( line )  ){
            if( strlen( line ) == 0 ) break;
            sscanf( line , "%c%d %s" , &computer , &users , &programs );
            totUsers += users;
            len = strlen( programs );
            for( i = 0 ; i < len - 1 ; ++i ){
                c[ computer - 'A' + 10 ][ programs[ i ] - '0' ] = 1;
                c[ programs[ i ] - '0' ][ sink ] = 1;
            }
            c[ source ][ computer - 'A' + 10 ] += users;
        }
        memset( ans , -1 , sizeof( ans ) );
        mf = maxflow( source , sink );
        if( totUsers != mf ){
            puts("!");
            continue;
        }
        for( i = 0 ; i < 10 ; ++i ){
            for( j = 10 ; j < 36 ; ++j ){
                if( c[ i ][ j ] == 1 ){
                    break;
                }
            }
            if( j == 36 ) putchar('_');
            else printf("%c" , j - 10 + 'A' );
        }
        printf("\n");
    }
    return 0;
}
