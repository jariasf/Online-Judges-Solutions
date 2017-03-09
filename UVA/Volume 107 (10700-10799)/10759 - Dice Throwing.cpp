/*****************************************
 ***Problema: Dice Throwing
 ***ID: 10759
 ***Juez: UVA
 ***Tipo: Probabilidad
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
#include <climits>
#include <fstream>
#include <list>
#include <sstream>
#include <iostream>
#include <iomanip>

using namespace std;
#define MAX 25
long long d[ MAX ];
long long gcd( long long a , long long b ){
    if( b == 0 )return a;
    return gcd( b , a % b );
}

#define MAXN 160
long long dp[ MAXN ][ MAXN ];

long long solve( int n , int x ){

    if( n == 0 ){
        if( x <= 0 )return 1;
        return 0;
    }
    if( dp[ n ][ x ] != -1 ) return dp[ n ][ x ];
    long long ans = 0;
    for( int i = 1 ; i <= 6 ; ++i ){
        ans += solve( n - 1 , x - i );
    }
    return dp[ n ][ x ] = ans;
}

int main(){

    int n , x , i;
    d[ 0 ] = 1;
    for( i = 1 ; i < MAX ; ++i ) d[ i ] = d[ i - 1 ] * 6;
    long long gc , num;
    while( scanf("%d %d" , &n , &x ) , n | x ){
        memset( dp , -1 , sizeof( dp ) );
        num = solve( n , x );
        gc = gcd( num , d[ n ] );
        if( d[ n ]/gc == 1 ) printf("%lld\n" , num/gc );
        else printf("%lld/%lld\n" , num/gc , d[ n ]/gc );
    }

    return 0;
}
