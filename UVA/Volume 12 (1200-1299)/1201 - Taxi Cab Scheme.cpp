/*****************************************
 ***Problema: Taxi Cab Scheme
 ***ID: 1201
 ***Juez: UVA
 ***Tipo: Min Path Cover
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

#define MAXL 505
#define MAXR 1010
int seen[ MAXL ], matchL[ MAXL ] , matchR[ MAXR ] , L;
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

int matchings(){
    memset( matchR , -1 , sizeof( matchR ) );
    memset( matchL , -1 , sizeof( matchL ) );
    int ans = 0 , i;
    for( i = 0 ; i < L ; ++i ){
        memset( seen , 0 , sizeof( seen ) );
        if( bpm( i ) ) ans++;
    }
    return ans;
}

struct Data{
    int time , x1 , x2 , y1 , y2 , dist;
    Data(){}
}d[ MAXL ];

int main(){
    int t , q , n , h , m , i , j;
    scanf("%d" , &t );
    while( t-- > 0 && scanf("%d" , &L ) ){
        for( i = 0 ; i < L && scanf("%d:%d %d %d %d %d" , &h ,&m , &d[ i ].x1 , &d[ i ].y1 , &d[ i ].x2 , &d[ i ].y2 ); ++i ){
            d[ i ].time = h * 60 + m;
            d[ i ].dist = abs( d[ i ].x2 - d[ i ].x1 ) + abs( d[ i ].y2 - d[ i ].y1 );
        }
        for( i = 0 ; i < L ; ++i ){
            for( j = 0 ; j < L ; ++j ){
                if( i != j && ( abs( d[ j ].x1 - d[ i ].x2 ) + abs( d[ j ].y1 - d[ i ].y2 ) + 
									d[ i ].time + d[ i ].dist ) < d[ j ].time ){
                    ady[ i ].push_back( j + L );
                }
            }
        }
        printf("%d\n" , L - matchings() );
        for( i = 0 ; i < L ; ++i ) ady[ i ].clear();
    }
    return 0;
}
