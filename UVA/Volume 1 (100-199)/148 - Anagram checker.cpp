/*****************************************
 ***Problema: Anagram checker
 ***ID: 148
 ***Juez: UVA
 ***Tipo: Backtracking, strings
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
#define MAX 3015

char dictionary[ MAX ][ 42 ];
int cantidad[ MAX ][ 27 ];
int a[ 27 ];
char paragraph[ 42 ];
char resp[ MAX ][ 42 ];
bool seen[ MAX ];
int len , len_anagram;

char anagram[ 25 ][ 22 ];

void solve( int word , int lon ){
    int i;
    for( i = 0 ; i < 26 ; ++i ){
        if( a[ i ] )break;
    }
    if( i == 26 ){
        int cnt = 0;
        for( int k = 0 ; k < lon ; ++k ){
            for( int i = 0 ; i < len_anagram ; ++i ){
                if( !strcmp( anagram[ i ] , resp[ k ] ) ){
                    cnt++;
                }
            }
        }
        //si mi respuesta contiene las letras en el mismo orden que la original no va
        if( cnt == len_anagram )return;
        printf("%s=" , paragraph );
        for( int j = 0 ; j < lon ; ++j ){
            printf(" %s" , resp[ j ] );
        }
        printf("\n");
        return;
    }
    if( word >= len ||lon >= len ){
        return;
    }
    for( int i = word ; i < len ; ++i ){

        int j;
        for(  j = 0 ; j < 26 ; ++j ){
            if( a[ j ] >= cantidad[ i ][ j ] )continue;
            else break;
        }
        //si tiene todos los caracteres
        if( j == 26 ){
            for(  j = 0 ; j < 26 ; ++j ){
                a[ j ] -= cantidad[ i ][ j ];
            }
            seen[ i ] = true;
            strcpy( resp[ lon ] , dictionary[ i ] );
            solve( i + 1 , lon + 1 );
            //backtrack
            seen[ i ] = false;
            for(  j = 0 ; j < 26 ; ++j ){
                a[ j ] += cantidad[ i ][ j ];
            }
        }
    }
}

int main(){

    int lp = 0;
    len = 0;
    memset( cantidad , 0 , sizeof( cantidad ) );

    while( gets( dictionary[ len ] ) && dictionary[ len ][ 0 ] != '#'){
        int l = strlen( dictionary[ len ] );
        for( int i = 0 ; i < l ; ++i ){
            if( 'A' <= dictionary[ len ][ i ] && dictionary[ len ][ i ] <= 'Z'  )
                cantidad[ len ][ dictionary[ len ][ i ] - 'A' ]++;
        }
        len++;
    }

    int aux;
    while( gets( paragraph ) , strcmp( paragraph  , "#") ){
        lp = strlen( paragraph );
        len_anagram = 0;
        aux = 0;
        memset( seen , 0 , sizeof( seen ) );
        bool enter = false;
        memset( a , 0 , sizeof( a ) );
        paragraph[ lp ] = ' ';
        paragraph[ lp + 1 ] = '\0';
        for( int i = 0 ; i <= lp ; ++i ){
            if( 'A' <= paragraph[ i ] && paragraph[ i ] <= 'Z'  ){
                anagram[ len_anagram ][ aux++ ] = paragraph[ i ];
                anagram[ len_anagram][aux] = '\0';
                a[ paragraph[ i ] - 'A' ]++;
                enter = true;
            }
            else{
                if( enter )len_anagram++;
                enter = false;
                aux = 0;
            }
        }
        solve( 0 , 0 );
    }
    return 0;
}
