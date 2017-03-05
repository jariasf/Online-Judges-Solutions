/*****************************************
 ***Problema: Divisible Group Sums
 ***ID: 10616
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
#define MAX 205
long long a[ MAX ];
int d , m , n;
long long dp[ 25 ][ MAX ][ MAX ][ 2 ];
long long solve( int sum , int len , int last ){
    if( len == m ){
        if( sum % d == 0 ) return 1;
        return 0;
    }
    if( sum < 0 ){
        if( dp[ -sum ][ len ][ last ][ 1 ] != -1 ) return dp[ -sum ][ len ][ last ][ 1 ];
    }
    else if( dp[ sum ][ len ][ last ][ 0 ] != -1 ) return dp[ sum ][ len ][ last ][ 0 ];

    long long ans = 0;
    for( int i = last ; i < n ; ++i ){
        ans += solve( ( sum % d + a[ i ] % d ) %d , len + 1 , i + 1 );
    }
    if( sum < 0 ) return dp[ -sum ][ len ][ last ][ 1 ] = ans;
    else return dp[ sum ][ len ][ last ][ 0 ] = ans;
}

int main(){
    int q , t = 1;
    while( scanf("%d %d" , &n , &q ) , n | q ){
        for( int i = 0 ; i < n ; ++i ) scanf("%lld" , &a[ i ] );
        printf("SET %d:\n" , t++ );
        for( int i = 1 ; i <= q ; ++i ){
            scanf("%d %d" , &d , &m );
            memset( dp , -1LL , sizeof( dp ) );
            printf("QUERY %d: %lld\n" , i , solve( 0 , 0 , 0 ) );
        }
    }
    return 0;
}
