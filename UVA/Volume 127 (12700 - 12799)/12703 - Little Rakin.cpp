/*****************************************
 ***Problema: Little Rakin
 ***ID: 12703
 ***Juez: UVA
 ***Tipo: Number Theory
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
#define MAXF 1005
#define MAX 50
#define pii pair<int,int>
int fib[ MAX ][ MAXF ];

void getPrimeFactors( int index , int n ){
    for( int i = 2 ; i * i <= n ; ++i ){
        while( n % i == 0 ){
            fib[ index  ][ i ]++;
            n /= i;
        }
    }
    if( n > 0 )
        fib[ index ][ n ]++;
}

void solve( int n ){
    for( int i = 2 ; i <= n ; ++i ){
        for( int j = 2 ; j < MAXF ; ++j ){
            fib[ i ][ j ] = fib[ i - 1 ][ j ] + fib[ i - 2 ][ j ];
        }
    }
}

int main(){
    int t , n , a , b;
    scanf("%d" , &t );
    while( t-- > 0 && scanf("%d %d %d", &n , &a , &b ) ){
        memset( fib , 0 , sizeof( fib ) );
        getPrimeFactors(0 , a);
        getPrimeFactors(1 , b);
        solve(n);
        for( int i = 2 ; i < MAXF ; ++i ){
            if( fib[ n ][ i ] ){
                printf("%d %d\n" , i , fib[ n ][ i ] );
            }
        }
        printf("\n");
    }
    return 0;
}
