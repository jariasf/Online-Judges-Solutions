/*****************************************
 ***Problema: Have Fun with Matrices
 ***ID: 11360
 ***Juez: UVA
 ***Tipo: Simulation
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
#define MAX 15
int n;
int matrix[ MAX ][ MAX ];

void incr(){
    for( int i = 0 ; i < n ; ++i ){
        for( int j = 0 ; j < n ; ++j ){
            matrix[ i ][ j ] = ( matrix[ i ][ j ] + 1 ) % 10;
        }
    }
}

void decr(){
    for( int i = 0 ; i < n ; ++i ){
        for( int j = 0 ; j < n ; ++j ){
            matrix[ i ][ j ] = ( ( matrix[ i ][ j ] - 1 ) + 10 ) % 10;
        }
    }
}

void transpose(){
    int tmp;
    for( int i = 0 ; i < n ; ++i ){
        for( int j = i ; j < n ; ++j ){
            tmp = matrix[ i ][ j ];
            matrix[ i ][ j ] = matrix[ j ][ i ];
            matrix[ j ][ i ] = tmp;
        }
    }
}

void row( int a , int b ){
    int tmp;
    for( int i = 0 ; i < n ; ++i ){
        tmp = matrix[ a ][ i ];
        matrix[ a ][ i ] = matrix[ b ][ i ];
        matrix[ b ][ i ] = tmp;
    }
}

void col( int a , int b ){
    int tmp;
    for( int i = 0 ; i < n ; ++i ){
        tmp = matrix[ i ][ a ];
        matrix[ i ][ a ] = matrix[ i ][ b ];
        matrix[ i ][ b ] = tmp;
    }
}

void show(){
    for( int i = 0 ; i < n ; ++i ){
        for( int j = 0 ; j < n ; ++j ){
            printf( "%d" , matrix[ i ][ j ] );
        }
        printf("\n");
    }
}

int main(){
    int t, m , a , b ;
    scanf("%d" , &t );
    char s[ 15 ];
    for( int q = 1 ; q <= t ; ++q ){
        scanf("%d" , &n );

        for( int i = 0 ; i < n ; ++i )
        {
            scanf("%s" , s );
            for( int j = 0 ; s[ j ] ; ++j )
                matrix[ i ][ j ] = s[ j ] -'0';
        }
        scanf("%d" , &m );
        while( m-- ){
            scanf(" %s" , s );
            if( strcmp( s , "transpose" ) == 0 ){
                transpose();
            }
            else if( strcmp( s , "row") == 0 ){
                scanf("%d %d" , &a , &b );
                a--; b--;
                row( a , b );
            }
            else if( strcmp( s , "col") ==0 ){
                scanf("%d %d" , &a , &b );
                a--; b--;
                col( a , b );
            }
            else if( strcmp( s , "inc" ) == 0 ){
                incr();
            }
            else{
                decr();
            }
        }
        printf("Case #%d\n" , q );
        show();
        printf("\n");
    }

    return 0;
}
