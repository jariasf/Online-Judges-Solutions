/*****************************************
 ***Problema: Collector's Problem
 ***ID: 10779
 ***Juez: UVA
 ***Tipo: Max Flow
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
#define MAX 50
int cnt[ 26 ] , c[ MAX ][ MAX ] , prev[ MAX ] , seen[ MAX ];

bool augmentPath( int source , int sink ){
    int u , v;
    queue< int > Q;
    Q.push( source );
    memset( seen , 0 , sizeof( seen ) );
    prev[ source ] = -1;
    seen[ source ] = 1;
    while( !Q.empty() ){
        u = Q.front(); Q.pop();
        if( u == sink ) return true;
        for( v = 0 ; v <= sink ; ++v ){
            if( c[ u ][ v ] > 0 && !seen[ v ] ){
                prev[ v ] = u;
                seen[ v ] = 1;
                Q.push( v );
            }
        }
    }
    return false;
}

int maxflow( int source , int sink ){
    int mf = 0 , mini , i;
    while( augmentPath( source , sink ) ){
        mini = 1<<30;
        for( i = sink ; prev[ i ] != -1 ; i = prev[ i ] ){
            mini = min( mini , c[ prev[ i ] ][ i ] );
        }
        for( i = sink ; prev[ i ] != -1 ; i = prev[ i ] ){
            c[ prev[ i ] ][ i ] -= mini;
            c[ i ][ prev[ i ] ] += mini;
        }
        mf += mini;
    }
    return mf;
}

int main(){
    int t , q , n , m , k , i , x , source = 0, sink , j ;
    scanf("%d" , &t);
    for( q = 1 ; q <= t && scanf("%d %d"  , &n , &m ); ++q ){
        sink = n + m + 1;
        memset( c , 0 , sizeof( c ) );
        for( i = 0 ; i < n && scanf("%d" , &k ) ; ++i ){
            memset( cnt , 0 , sizeof( cnt ) );
            while( k-- > 0 && scanf("%d" , &x ) ){
                cnt[ x ]++;
            }
            if( !i ){
                for( j = 1 ; j <= m ; ++j ){
                    c[ source ][ j ] = cnt[ j ];
                    c[ j ][ sink ] = 1;
                }
            }
            else{

                for( j = 1 ; j <= m ; ++j ){
                    if( cnt[ j ] == 0 ){
                        c[ j ][ m + i ] = 1;
                    }
                    else if( cnt[ j ] > 1 ){
                        //siempre se debe quedar con 1 sticker
                        c[ m + i ][ j ] = cnt[ j ] - 1;
                    }
                }
            }
        }

        printf("Case #%d: %d\n" , q , maxflow( source , sink ) );
    }

    return 0;
}
