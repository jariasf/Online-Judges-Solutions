/*****************************************
 ***Problema: Brainfuck
 ***ID: 11956
 ***Juez: UVA
 ***Tipo: Ad hoc
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

int main(){
    int t , l, a[ 105 ], idx;
    char s[ 100005 ];
    scanf("%d" , &t );
    for( int q = 1 ; q <= t ; ++q ){
        scanf("%s" , &s );
        idx = 0;
        memset( a , 0 , sizeof( a ) );
        l = strlen( s );
        for( int i = 0 ; i < l ; ++i ){

            if( s[ i ] == '.' ){
                continue;
            }else if( s[ i ] == '+' ) {
                if( a[ idx ] == 255 ) a[ idx ] = 0;
                else a[ idx ]++;
            }
            else if( s[ i ] == '-' ) {
                if( a[ idx ] == 0 )a[ idx ] = 255;
                else a[ idx ]--;
            }
            else if( s[ i ] == '<' ){
                if( idx == 0 )idx = 99;
                else idx--;
            }
            else if( s[ i ] == '>' ) {
                if( idx == 99 ) idx = 0;
                else idx++;
            }
        }

        printf("Case %d:" , q );
        for( int i = 0 ; i < 100 ; ++i ){
            putchar(' ');
            if( a[ i ] < 16 )putchar('0');
            printf("%X" , a[ i ] );
        }
        putchar( '\n' );
    }
    return 0;
}
