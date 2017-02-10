/*****************************************
 ***Problema: Monkeys in a Regular Forest
 ***ID: 776
 ***Juez: UVA
 ***Tipo: Flood Fill
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
int h, w;

#define MAX 130
char ady[ MAX ][ MAX ];
int resp[ MAX ][ MAX ];
int digits[ MAX ][ MAX ];
bool seen[ MAX ][ MAX ];
int maxD[ MAX ]; //maxima cantidad de digitos x columna para alinear;
int dx[ 8 ] = { 1 , -1 , 0 ,  0 , 1 , 1 , -1 , -1 };
int dy[ 8 ] = { 0 ,  0 , 1 , -1 , 1 , -1 , 1 , -1};

int numDigits( int n ){
    int c = 0;
    while( n > 0 ){
        n /= 10;
        c++;
    }
    return c;
}

void dfs( int x , int y , char c, int val  ){

    if( x < 0 || y < 0 || x >= h || y >= w || seen[ x ][ y ] || ady[ x ][ y ] != c )return;
    seen[ x ][ y ] = true;
    resp[ x ][ y ] = val;
    if( val > maxD[ y ] ) maxD[ y ] = val;
    for( int i = 0 ; i < 8 ; ++i )dfs( dx[ i ] + x , dy[ i ] + y , c , val  );
}

int main(){
    int l, ancho ;
    char C;
    while( 1 ){
        memset( ady , 0 , sizeof( ady ) );
        h = w = ancho = 0;
        while( ( C = getchar() ) != EOF ){
            if( isalpha( C ) ){
                ady[ h ][ w++ ] = C;
                if( ancho < w ) ancho = w;
            }
            else if( C == '\n'){
                h++; w = 0;
            }
            else if( C == '%'){ C = getchar(); break;}
        }
        w = ancho;
        if( w == 0 || h == 0 ) break;

        int idx = 1;
        memset( seen , false , sizeof( seen ) );
        memset( maxD , 0 , sizeof( maxD ) );
        for( int i = 0 ; i < h ; ++i ){
            for( int j = 0 ; j < w ; ++j ){
                if( !seen[ i ][ j ] ){
                    dfs( i , j , ady[ i ][ j ] , idx++ );
                }
            }
        }

        for( int i = 0 ; i < w ; ++i ) maxD[ i ] = numDigits(( maxD[ i ] ) );
        for( int i = 0 ; i < h ; ++i ){
            for( int j = 0 ; j < w ; ++j ){
                printf((j + 1) >= w ? "%*d\n" : "%*d " , maxD[ j ], resp[ i ][ j ] );
            }
        }
        printf("%%\n");
    }

    return 0;
}
