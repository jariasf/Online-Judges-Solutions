/*****************************************
 ***Problema: Jupiter Attack
 ***ID: 12365
 ***Juez: UVA
 ***Tipo: Segment Tree
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
#define MAX 100050
long long MOD;
int n;
long long tree[ 4 * MAX ];
long long B[ MAX ];


void update( int pos , int by , int left = 0 , int right = n - 1 , int node = 0 ){
    if( left == right ){
        tree[ node ] = by % MOD;
        return;
    }

    int mid = ( left + right )>>1;
    if( pos > mid ){
        update( pos , by , mid + 1 , right , 2 * node + 2 );
    }
    else{
        update( pos , by , left , mid , 2 * node + 1 );
    }
    tree[ node ] = tree[ 2 * node + 1 ] % MOD + ( tree[ 2 * node + 2 ] * B[ mid - left + 1 ] % MOD ) % MOD;
    tree[ node ] %= MOD;
}

long long query( int from , int to , int left = 0 , int right = n - 1 , int node = 0 ){

    if( left >= from && right <= to ){
        return tree[ node ] % MOD;
    }
    int mid = ( left + right )>>1;
    long long sum = 0, l = 0 , r = 0;
    if( from <= mid ){
        l = query( from , to , left , mid , 2 * node + 1 ) % MOD;
    }
    if( to > mid ){
        r = query( from , to , mid + 1 , right , 2 * node + 2 ) % MOD;
    }
    int bpow = ( mid - max( left , from ) + 1 );
    if( bpow < 0 ) bpow = 0;
    sum = ( l % MOD + ( r % MOD * B[ bpow ] %MOD ) % MOD ) % MOD;
    return sum % MOD ;
}

void init(){
    for( int i = 0 ; i < 4 * MAX ; ++i ) tree[ i ] = 0;
}

int main(){
    int Q , x , y;
    long long b;
    char c;
    while( scanf("%lld %lld %d %d" , &b , &MOD , &n , &Q ) , b | MOD | n | Q ){
        B[ 0 ] = 1;
        for( int i = 1 ; i <= n ; ++i ){
            B[ i ] = ( B[ i - 1 ] % MOD * b % MOD ) % MOD;
            B[ i ] %= MOD;
        }
        init();
        while( Q-- ){
            scanf(" %c %d %d" , &c , &x , &y );
            if( c == 'E' ) update( n - x , y );
            else printf("%lld\n" , query( n - y , n - x ) );
        }
        puts("-");
    }

    return 0;
}
