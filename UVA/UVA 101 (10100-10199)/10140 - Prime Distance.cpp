/*****************************************
 ***Problema: Prime Distance
 ***ID: 10140
 ***Juez: UVA
 ***Tipo: Segmented Sieve
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

#define DIF 1000005 //L-U
#define MAX 46350   //sqrt( U )
int primes[ MAX ] , isPrime[ MAX ] , len , is_Prime[ DIF ];

void sieve( int n ){
    memset( isPrime , 1 , sizeof( isPrime ) );
    isPrime[ 0 ] = 0;
    isPrime[ 1 ] = 0;
    int i , k ;
    for( i = 2 ; i * i <= n ; ++i ){
        if( isPrime[ i ] ){
            for( k = 2 ; k * i <= n ; ++k){
                isPrime[ k * i ] = 0;
            }
        }
    }
    len = 0;
    if( n >= 2 ) primes[ len++ ] = 2;
    for( i = 3 ; i <= n ; i += 2 ){
        if( isPrime[ i ] ) primes[ len++ ] = i;
    }
}


long long v[ DIF ];
int sz;
void segmentedSieve( int L , int U ){
    if( L < 2 ) L = 2;
    memset( is_Prime , 1 , sizeof( is_Prime ) );
    int root;
    long long j , start , p , i ;
    root = ( int )sqrt( U ) + 1;
    for( i = 0 ; i < len ; ++i ){
        p = primes[ i ];
        if( p >= root ) break;
        start = ( p >= L ) ? p * 2 : ( L + ( p - L % p ) % p );
        for( j = start ; j <= U ; j += p ){
            is_Prime[ j - L ] = false;
        }
    }
    start = ( L % 2 ? L : L + 1 );
    sz = 0;
    if( L == 2 ) v[ sz++ ] = 2;
    for( i = start ; i <= U ; i += 2 )if( is_Prime[ i - L ] ) v[ sz++ ] = i;
}

int main(){
    sieve( MAX );
    int L , U , i;
    long long xmini , ymini , xmaxi , ymaxi , mini , maxi;
    while( scanf("%d %d" , &L , &U ) != EOF ){
        segmentedSieve( L , U );
        if( sz < 2 ){ puts("There are no adjacent primes."); continue; }
        mini = 1LL<<50;
        maxi = -1;
        for( i = 1 ; i < sz ; ++i ){
            if( v[ i ] - v[ i - 1 ] < mini ){
                mini = v[ i ] - v[ i - 1 ];
                xmini = v[ i - 1 ];
                ymini = v[ i ];
            }
            if( v[ i ] - v[ i - 1 ] > maxi ){
                maxi = v[ i ] - v[ i - 1 ];
                xmaxi = v[ i - 1 ];
                ymaxi = v[ i ];
            }
        }
        printf("%lld,%lld are closest, %lld,%lld are most distant.\n" , xmini , ymini , xmaxi , ymaxi );
    }

    return 0;
}
