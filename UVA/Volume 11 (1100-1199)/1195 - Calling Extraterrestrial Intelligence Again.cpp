/*********************************************************
 ***Problema: Calling Extraterrestrial Intelligence Again
 ***ID: 1195
 ***Juez: UVA
 ***Tipo: Primes
 ***Autor: Jhosimar George Arias Figueroa
 *********************************************************/

#include <stdio.h>
#include <cstring>

#define MAX 10000
int prime[ MAX ] , primes[ MAX ], len = 0;
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

    for( int i = 2 ; i <= MAX ; ++i ){
        if( prime[ i ] ) primes[ len++ ] = i;
    }
}


int main(){
    int m , a, b, p1 , p2, pp1 , pp2;
    long long maxi;
    sieve();
    while( scanf("%d %d %d" , &m , &a , &b ) , m | a | b ){
        maxi = 0;
        for( int i = len - 1 ; i >= 0 ; --i ){
            for( int j = i ; j < len ; ++j ){
                p1 = primes[ i ];
                p2 = primes[ j ];
                if( p1 * p2 >  m || p1/( double)p2 < a/(double) b ) break;
                if( p1  <= m/(double)p2 && p1/(double)p2 <= 1 && p1/(double)p2 >= a/(double)b ){
                   if( maxi < p1 * p2 ){
                        maxi = p1 * p2;
                        pp1 = p1;
                        pp2 = p2;
                   }
                }
            }

        }
        printf("%d %d\n" , pp1 , pp2 );
    }

    return 0;
}
