/*****************************************
 ***Problema: Maximum sum on a torus
 ***ID: 10827
 ***Juez: UVA
 ***Tipo: DP
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
#define MAX 80
int h , w;
int a[ MAX ][ MAX ], sum , s , maxi, n;
int pr[ MAX ];
int Kadane2D(){
    maxi = 0;
    int resp = 0;
    int k, l , j , tot, minSum, mini;

    for( int z = 0 ; z < h; ++z ){
         for( int i = 0 ; i < w ; ++i ) pr[ i ] = 0;
         //si empiezo en la segunda fila, evaluo filas superiores
         for( int x = z ,k = 0 ; k < h ; x = ( x + 1 ) % h , ++k ){
             s = 1<<31;
             sum = 0;
             tot = 0;
             minSum = 0;
             mini = 1<<30;
             for( int i = 0 ; i < w ; ++i ){
                 pr[ i ] += a[ x ][ i ];
                 sum += pr[ i ];
                 if( sum > s ){
                     s = sum;
                 }
                 if( sum < 0 ){
                     sum = 0;
                 }

                 tot += pr[ i ];
                 minSum += pr[ i ];
                 if( minSum > 0 ) minSum = 0;
                 if( mini > minSum ) mini = minSum;

             }
             if( s > maxi ){
                 maxi = s;
             }

             if( tot - mini > maxi ) maxi = tot - mini;
         }

    }
    return maxi;
}

int main(){
    int t;
    scanf("%d" , &t );
    while( t-- ){
        scanf("%d" , &n );
        for( int i = 0 ; i < n ; ++i ){
            for( int j = 0 ; j < n ; ++j ){
                scanf("%d" , &a[ i ][ j ] );
            }
        }
        h = w = n;
        printf("%d\n" , Kadane2D() );
    }
    return 0;
}
