/*****************************************
 ***Problema: Galactic Bonding
 ***ID: 11966
 ***Juez: UVA
 ***Tipo: Union Find
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

#define MAX 1005
int uf[ MAX ];
int Find( int x ){
    return ( uf[ x ] == x ) ? x : uf[ x ] = Find( uf[ x ] );
}

void Union( int x , int y ){
    uf[ Find( x ) ] = Find( y );
}

int main(){
    int t, N, resp, c;
    int a[ 1005 ];
    double D, x, y, p[ 1005 ][ 2 ] , d;
    scanf("%d" , &t );
    for( int q = 1 ; q <= t ; ++q ){
        scanf("%d %lf" , &N , &D );
        for( int i = 0 ; i < N ; ++i ){
             uf[ i ] = i;
             scanf("%lf %lf" , &p[ i ][ 0 ] , &p[ i ][ 1 ] );
        }
        resp = 0;

        for( int i = 0 ; i < N ; ++i ){
            for( int j = i + 1 ; j < N ; ++j ){
                d = ( p[ i ][ 0 ] - p[ j ][ 0 ] )*( p[ i ][ 0 ] - p[ j ][ 0 ] ) + ( p[ i ][ 1 ] - p[ j ][ 1 ] )*( p[ i ][ 1 ] - p[ j ][ 1 ] );
                if( d <= D * D ){
                    if( Find( i ) != Find( j ) ){
                        Union( i , j );
                    }
                }
            }
        }
        if( N > 0 ){
            memset( a , 0 , sizeof( a ) );
            for( int i = 0 ; i < N ; ++i ){
                a[ Find( i ) ] = 1;
            }
            for( int i = 0 ; i < N ; ++i ) resp += a[ i ];
        }

        printf("Case %d: %d\n" ,q , resp );
    }
    return 0;
}
