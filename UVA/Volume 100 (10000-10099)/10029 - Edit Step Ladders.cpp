/*****************************************
 ***Problema: Edit Step Ladders
 ***ID: 10029
 ***Juez: UVA
 ***Tipo: LIS
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

#define MAX 25005
#define MAXN 26
char s[ MAX ][ 17 ] , aux[ 17 ];
int len , dp[ MAX ] , l;

//borro s[ act ] en indice idx s[ act ][ idx ]
void borrar( int act , int idx ){
    int i , l = 0;
    for( i = 0 ; i < idx ; ++i ) aux[ l++ ] = s[ act ][ i ];
    for( i = idx + 1 ; s[ act ][ i ] ; ++i ) aux[ l++ ] = s[ act ][ i ];
    aux[ l++ ] = '\0';
}

//insert en s[ act] en indice idx caracter car s[ act ][ idx ] = car
void insertar( int act , int idx , int car ){
    int i , l = 0;
    for( i = 0 ; i < idx ; ++i ) aux[ l++ ] = s[ act ][ i ];
    aux[ l++ ] = car + 'a';
    for( i = idx ; s[ act ][ i ] ; ++i ) aux[ l++ ] = s[ act ][ i ];
    aux[ l++ ] = '\0';
}

void cambiar( int act , int idx , int car ){
    memcpy( aux , s[ act ] , sizeof( s[ act ] ) );
    aux[ idx ] = car + 'a';
}

void transformar( int act , int op , int idx, int car ){
    if( op == 0 ) borrar( act , idx );
    else if( op == 2 ) insertar( act , idx , car );
    else cambiar( act , idx , car );
}

int bs(){
    int left = 0 , right = len , mid , idx = -1 , val;
    while( left < right ){
        mid = ( left + right ) >> 1;
        val = strcmp( s[ mid ] , aux );
        if( val == 0 ){
            idx = mid;
            break;
        }
        if( val < 0 ){
            left = mid + 1;
        }
        else{
            right = mid;
        }
    }
    return idx;
}

int main(){
    len = 0;
    int ans = 0 , i , j , op , ll , idx;
    for( i = 0 ; i < MAX ;++i ) dp[ i ] = 1;
    while( scanf("%s" , &s[ len ] ) != EOF ){
        for( op = 0 ; op < 3 ; ++op ){
            for( i = 0 ; i < s[ len ][ i ] ; ++i ){
                for( j = 0 ; j < 26 ; ++j ){
                    transformar( len , op , i , j );
                    //no tiene caso buscar palabras por que me lo dan ordenado
                    if( strcmp( s[ len ] , aux ) < 0 ) continue;
                    idx = bs();
                    if( idx >= 0 && dp[ len ] < dp[ idx ] + 1 ){
                        dp[ len ] = dp[ idx ] + 1;
                    }
                }
            }
        }
        len++;
    }
    for( i = 0 ; i < len ; ++i ) ans = max( ans , dp[ i ] );
    printf("%d\n" , ans );

    return 0;
}
