/*****************************************
 ***Problema: Unique Factorization
 ***ID: 10858
 ***Juez: UVA
 ***Tipo: Number Theory, Recursion
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

#define MAX 1500
int fact[ MAX ];
int ans[ 7000 ][ 500 ], lresp, resp[ MAX ];
int cont, N;
void solve( int n , int len , int act){
    int l = ( int ) sqrt( n );
    for( int i = act ; i <= l ; ++i ){
        if( n % i == 0 ){
            resp[ len ] = i;
            solve( n / i , len + 1  , i );
        }
    }
    resp[ len ] = n;
    for( int i = 0 ; i <= len ; ++i ){
        ans[ cont ][ i ] = resp[ i ];
    }
    cont++;
}

int main(){

    while( scanf("%d" , &N ) , N ){
        int l = ( int ) sqrt( N );
        int len = 0;
        for( int i = 2 ; i <= l ; ++i ){
            if( N % i == 0 ){
                fact[ len++ ] = i;
            }
        }
        if( len == 0 ){
            printf("0\n");
            continue;
        }
        cont = 0;

        memset( ans , -1 , sizeof( ans ) );

        for( int i = 0 ; i < len ; ++i ){
            resp[ 0 ] = fact[ i ];
            solve( N/fact[ i ] , 1 , fact[ i ] );
        }
        printf("%d\n" , cont );

        for( int i = 0 ; i < cont ; ++i ){
            printf("%d" , ans[ i ][ 0 ] );
            for( int j = 1 ; j < 500 ; ++j ){
                if( ans[ i ][ j ] == -1 )break;
                printf(" %d" , ans[ i ][ j ] );
            }
            printf("\n");

        }
    }
    return 0;
}
