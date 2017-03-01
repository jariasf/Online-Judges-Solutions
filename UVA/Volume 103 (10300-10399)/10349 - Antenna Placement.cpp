/*****************************************
 ***Problema: Antenna Placement
 ***ID: 10349
 ***Juez: UVA
 ***Tipo: Max Independent Set - BPM
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

#define MAXL 405
#define MAXR 405
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
#define MAX 50
char table[ MAX ][ MAX ];
int a[ MAX ][ MAX ] , dx[ ] = { 0 , 0 , 1 , -1 } , dy[ ] = { 1 , -1 , 0 , 0 };
int main(){
    int t , q , h , w , white , black , i, j , k , nx , ny , V , cnt;
    scanf("%d" , &t );

    while( t-- > 0 && scanf("%d %d" , &h , &w ) ){
        white = black = 0;
        for( i = 0 ; i < h && scanf("%s" , &table[ i ] ) ; ++i ){
            for( j = 0 ; j < w ; ++j ){
                if( table[ i ][ j ] == '*' ){
                    if( ( i + j ) & 1 ) a[ i ][ j ] = white++;
                    else a[ i ][ j ] = black++;
                }
            }
        }

        for( i = 0 ; i < h ; ++i ){
            for( j = 0 ; j < w ; ++j ){
                if( table[ i ][ j ] == '*' && ( ( i + j ) & 1 )  ){
                    for( k = 0 ; k < 4 ; ++k ){
                        nx = dx[ k ] + i;
                        ny = dy[ k ] + j;
                        if( nx >= 0 && ny >= 0 && nx < h && ny < w && table[ nx ][ ny ] == '*' ){
                            ady[ a[ i ][ j ] ].push_back( a[ nx ][ ny ] );
                        }
                    }
                }
            }
        }

        memset( matchL , -1 , sizeof( matchL ) );
        memset( matchR , -1 , sizeof( matchR ) );
        V = white + black;
        cnt = 0;
        for( i = 0 ; i < white ; ++i ){
            memset( seen , 0 , sizeof( seen ) );
            if( bpm( i ) ) cnt++;
        }
        printf("%d\n" ,V - cnt );
        for( i = 0 ; i <= white ; ++i ) ady[ i ].clear();

    }

    return 0;
}
