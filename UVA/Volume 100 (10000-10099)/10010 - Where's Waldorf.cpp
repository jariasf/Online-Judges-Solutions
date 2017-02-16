/*****************************************
 ***Problema: Where's Waldorf?
 ***ID: 10010
 ***Juez: UVA
 ***Tipo: Brute Force
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
#define MAX 55
char ady[ MAX ][ MAX ] , s[ MAX ];
int h , w , len;
int dx[ 8 ] = { 1 , -1,  0 ,  0 , 1 , 1 , -1 , -1 };
int dy[ 8 ] = { 0 ,  0 , 1 , -1 , 1 , -1 , 1 , -1};
bool solve( int x , int y){
    int i , k , nx , ny;
    for( i = 0 ; i < 8 ; ++i ){
        k = 0;
        while( true ){
            nx = dx[ i ] * k + x; ny = dy[ i ] * k + y;
            if( nx >= 0 && ny >= 0 && nx < h && ny < w && ady[ nx ][ ny ] == s[ k ] ){
                k++;
            }
            else break;
            if( k == len ){
                return true;
            }
        }
    }
    return false;
}
int main(){
    int t , i , j , k;
    scanf("%d" , &t );
    while( t-- > 0 && scanf("%d %d" , &h , &w ) ){
        for( i = 0 ; i < h && scanf("%s" , &ady[ i ]); ++i )
            for( j = 0 ; j < w ; ++j )
                ady[ i ][ j] = tolower( ady[ i ][ j ] );

        scanf("%d" , &k );
        while( k-- > 0 && scanf("%s" , &s ) ){
            for( i = 0 ; s[ i ] ; ++i ) s[ i ] = tolower( s[ i ] );
            len = strlen( s );
            for( i = 0 ; i < h ; ++i ){
                for( j = 0 ; j < w ; ++j ){
                    if( solve( i , j ) ){ goto end;}
                }
            }
            end:
            printf("%d %d\n" , i + 1 , j + 1 );
        }
        if( t ) printf("\n");
    }

    return 0;
}
