/*****************************************
 ***Problema: Largest Submatrix
 ***ID: 836
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
#define MAX 26
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

    int t , l;
    char line[ MAX ];
    scanf("%d\n" , &t );
    gets( line );
    for( int q = 0 ; q < t ; ++q ){
        if( q )putchar('\n');
        n = 0;
        while( gets( line ) ){
            l = strlen( line );
            if( l == 0 )break;
            for( int j = 0 ; j < l ; ++j ){
                if( line[ j ] == '0' )a[ n ][ j ] = -1005;
                else a[ n ][j ] = 1;
            }
            ++n;
        }
        printf("%d\n" , Kadane2D() );
    }

    return 0;
}
