/*****************************************
 ***Problema: Crossword Answers
 ***ID: 232
 ***Juez: UVA
 ***Tipo: Ad hoc simulation
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
#define MAX 105
char ady[ MAX ][ MAX ];
int num[ MAX ][ MAX ];
int h ,w;
int dx[ 2 ] = { -1 , 0 };
int dy[ 2 ] = { 0 , -1 };

void Across(){

    for( int i = 0 ; i < h ; ++i ){
        for( int j = 0 ; j < w ; ++j ){
            if( num[ i ][ j ] != 0 ){
                printf("%3d.%c" , num[ i ][ j ] , ady[ i ][ j ] );
                while( ady[ i ][ ++j ] != '*' ){
                    printf("%c" , ady[ i ][ j ] );
                }
                printf("\n");
            }
        }
    }
}

void Down(){
    for( int i = 0 ; i < h ; ++i ){
        for( int j = 0 ; j < w ; ++j ){
            if( num[ i ][ j ] != 0 && ( ( i == 0 ) || (i > 0 && ady[ i - 1 ][ j ] == '*') )){
                printf("%3d.%c" , num[ i ][ j ] , ady[ i ][ j ] );
                int x = i;
                while( ady[ ++x ][ j ] != '*' ){
                    printf("%c" , ady[ x ][ j ] );
                }
                printf("\n");
            }
        }
    }
}

int main(){
    int n , q = 0;
    while( scanf("%d" , &h ) , h  ){
        scanf("%d" , &w );
        n = 1;
        if( q )printf("\n");
        for( int i = 0 ; i < h ; ++i ) scanf("%s" , &ady[ i ] );
        memset( num , 0 , sizeof( num ) );

        for( int i = 0 ; i < h ; ++i ){
            for( int j = 0 ; j < w ; ++j ){
                if( ady[ i ][ j ] == '*' )continue;
                for( int k = 0 ; k < 2 ; ++k ){
                    int nx = dx[ k ] + i, ny = dy[ k ] + j;
                    if( nx >= 0 && ny >= 0 && nx < h && ny < w ){
                        if( ady[ nx ][ ny ] == '*'){ num[ i ][ j ] = n++; break;}
                    }
                    else{ num[ i ][ j ] = n++; break; }
                }
            }
        }

        for( int i = 0 ; i < h ; ++i ) ady[ i ][ w ] = '*';
        for( int i = 0 ; i < w ; ++i ) ady[ h ][ i ] = '*';
        printf("puzzle #%d:\n" , ++q );
        printf("Across\n");
        Across();
        printf("Down\n");
        Down();
    }
    return 0;
}
