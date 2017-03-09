/*****************************************
 ***Problema: New Rule in Euphomia
 ***ID: 10742
 ***Juez: UVA
 ***Tipo: Sieve, Binary Search
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

#define MAX 1000005
int prime[ MAX ] , p[ MAX ], len;
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
    len = 0;
    for( int i = 2 ; i <= MAX ; ++i ){
        if( prime[ i ] ) p[ len++ ] = i;
    }
}

int main(){
    sieve();
    int n , idx , q = 1;
    long long ans;
    while( scanf("%d" , &n ) , n ){
        ans = 0;
        for( int i = 0 ; i < len ; ++i ){
            if( p[ i ] > n || n <= p[ i ] * 2 ) break;
            idx = lower_bound( p + i + 1 , p + len , n - p[ i ] ) - p;
            if( !prime[ n - p[ i ] ] ) idx--;
            ans += idx - i;
        }
        printf("Case %d: %lld\n" , q++ , ans );
    }

    return 0;
}
