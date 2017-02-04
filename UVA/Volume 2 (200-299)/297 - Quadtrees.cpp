/*****************************************
 ***Problema: Quadtrees
 ***ID: 297
 ***Juez: UVA
 ***Tipo: recursion
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
#define MAX 2225
char s1[ MAX ], s2[ MAX ];
int len, sum;
bool seen[ MAX ];
int a[ 6 ][ 1<<17 ], visit[ 6 ][ 1<<17 ];
//marco en a como 1 si tenemos full
/*
arbol representado como matriz
1 - root
2 - 1 2 3 4
3 - 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 //hijos de nodos de altura 1 (4 * 40
...
*/
void solve( int l , string s , int d , int altura , int ant ){

    if( l == len ){
        return;
    }

    for( int i = l , j = 0 ; i < len && j < 4; ++i ){
        if( seen[ i ] )continue;
        if( s[ i ] == 'f' ){
            a[ altura ][ ant + j ] = 1;
        }
        else if( s[ i ] == 'p' ){
            solve( i + 1 , s , d - 2 , altura + 1 , ( ant + j ) * 4 );
        }
        j++;
        seen[ i ] = 1;
    }

}

//si al unir dos arboles el nodo padre es negro, todos sus hijos seran empty o nulos
void clean( int i , int j ){

    if( i > 5 || j > 1<<16 ){
        return;
    }

    for( int k = 0 ,ini = ( j + k )*4 ; k < 4 ; ++k ){
        a[ i + 1 ][ ini + k ] = 0;
        clean( i + 1 , ini + k );
    }
}

int main(){

    int t;
    scanf("%d" , &t );

    while( t-- ){
        scanf("%s %s" , &s1 , &s2 );
        if( s1[ 0 ] == 'f' || s2[ 0 ] == 'f' ){
            printf("There are 1024 black pixels.\n");
            continue;
        }
        len = strlen( s1 );
        memset( a , 0 , sizeof( a ) );
        memset( seen , 0 , sizeof( seen ) );
        solve( 1 , s1 , 8 , 1 , 0 );
        len = strlen( s2 );
        memset( seen , 0 , sizeof( seen ) );
        sum = 0;
        solve( 1 , s2 , 8 , 1  , 0);
        for( int i = 0, aux = 0 , d = 10; i < 6 ; ++i , aux += 2 , d -= 2 ){
            for( int j = 0 ; j < 1<<aux ; ++j ){
                if( a[ i ][ j ] == 1 ){
                    sum += 1<<d;
                    clean( i , j );
                }
            }
        }
        printf("There are %d black pixels.\n" , sum );
    }

    return 0;
}
