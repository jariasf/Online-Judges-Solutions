/*****************************************
 ***Problema: Sum of different primes
 ***ID: 1213
 ***Juez: UVA
 ***Tipo: DP, knapsack
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

#define MAX 1125
int prime[ MAX ] ,primes[ MAX ] , sz;
void sieve(){
    memset( prime , 1 , sizeof( prime ) );
    prime[ 0 ] = 0;
    prime[ 1 ] = 0;
    for(int i = 2 ; i * i <= MAX ; ++i ){
        if( prime[ i ] ){
            for(int k = 2 ; k * i <= MAX ; ++k){
                prime[ k * i ] = 0;
            }
        }
    }
    sz = 0;
    for( int i = 2 ; i <= MAX ; ++i ){
        if( prime[ i ] ) primes[ sz++ ] = i;
    }
}

int n , k;
int dp[ MAX ][ 15 ];

int main(){
    sieve();
    memset( dp , 0 , sizeof( dp ) );
    dp[ 0 ][ 0 ] = 1;
    for( int i = 0 ; i < sz ; ++i ){
        for( int j = MAX ; j >= primes[ i ] ; --j ){
            for( int q = 1 ; q < 15 ; ++q ){
                dp[ j ][ q ] += dp[ j - primes[ i ] ][ q - 1 ];
            }
        }
    }
    while( scanf("%d %d" , &n , &k ) , n | k ){
        printf("%d\n" , dp[ n ][ k ]);
    }
    return 0;
}
