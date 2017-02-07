/*****************************************
 ***Problema: Anagrams
 ***ID: 454
 ***Juez: UVA
 ***Tipo: Strings
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

static int cmpr(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

int main(){
    int t;
    scanf("%d" , &t );
    char s[ 105 ];
    char *words[ 105 ];
    int len = 0;
    gets( s );
    gets( s );

    int values[ 105 ][ 64 ];

    for( int q = 0 ; q < t ; ++q ){
        if( q )putchar('\n');
        len = 0;
        while( gets( s ) ){
            if( strlen( s ) == 0 )break;
            words[ len++ ] = strdup( s );
        }

        qsort( words , len , sizeof( char* ) , cmpr );

        memset( values , 0 , sizeof( values ) );
        for( int i = 0 ; i < len ; ++i ){
            int l = strlen( words[ i ] );
            for( int j = 0 ; j < l ; ++j ){
                if( words[ i ][ j ] == ' ') continue;
                if( islower( words[ i ][ j ] ) )
                    values[ i ][ words[ i ][ j ] - 'a'  ]++;
                else values[ i ][ words[ i ][ j ] - 'A' + 26  ]++;
            }
        }

        for( int i = 0 ; i < len ; ++i ){
            if( i && !strcmp( words[ i ] , words[ i - 1 ] ) ) continue;
            for( int j = i + 1 ; j < len ; ++j ){
                if( !strcmp( words[ j ] , words[ j - 1 ] ) )continue;
                int k;
                for( k = 0 ; k < 64 ; ++k ){
                    if( values[ i ][ k ] != values[ j ][ k ] ) break;
                }
                if( k != 64 )continue;
                printf("%s = %s\n" , words[ i ] , words[ j ] );
            }
        }
    }
    return 0;
}
