/*****************************************
 ***Problema: Largest Block
 ***ID: 10667
 ***Juez: UVA
 ***Tipo: DP, Maximum 2D sum
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
int h , w;
int a[ MAX ][ MAX ], sum , s , maxi, n;
int pr[ MAX ];
int Kadane2D(){
    maxi = 0;
    int resp = 0;
    int k, l , x1 = 0 , x2 = 0 , y1 = 0, y2 = 0, j;
    for( int z = 0 ; z < n; ++z ){
         for( int i = 0 ; i < n ; ++i ) pr[ i ] = 0;
         for( int x = z ; x < n ; ++x ){
             s = 1<<31;
             sum = 0;
             for( int i = 0 ; i < n ; ++i ){

                 pr[ i ] += a[ x ][ i ];
                 sum += pr[ i ];
                 if( sum > s ){
                     s = sum;
                 }
                 if( sum < 0 ){
                     sum = 0;
                 }
             }
             if( s > maxi ){
                 maxi = s;
             }
         }

    }
    return maxi;
}
int main(){

    int t , b , x1 , y1 , x2 , y2;
    scanf("%d" , &t );

    while( t-- ){

        scanf("%d %d" , &n , &b );

        for( int i = 0 ; i < n ; ++i ){
            for( int j = 0 ; j < n ; ++j ){
                a[ i ][ j ] = 1;
            }
        }
        while( b-- ){
            scanf("%d %d %d %d" , &x1 , &y1 , &x2 , &y2 );
            x1--; y1--; x2--; y2--;
            for( int i = x1 ; i <= x2 ; ++i ){
                for( int j = y1 ; j <= y2 ; ++j ){
                     a[ i ][ j ] = -10050;
                }
            }
        }
        printf("%d\n" , Kadane2D() );
    }

    return 0;
}
