/*****************************************
 ***Problema: Factorial Products
 ***ID: 12765
 ***Juez: UVA
 ***Tipo: Sieve
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <cstring>


#define MAX 1005
int factors[ MAX ];
int primes[ MAX ] , len;
int is_prime[ MAX ];
void sieve(){
    memset( is_prime , 1 , sizeof( is_prime ) );
    is_prime[ 0 ] = 0;
    is_prime[ 1 ] = 0;

    for(int i = 2 ; i * i <= MAX ; ++i ){
        if( is_prime[ i ] ){
            for(int k = 2 ; k * i <= MAX ; ++k){
                is_prime[ k * i ] = 0;
            }
        }
    }
    len = 0;
    for( int i = 2 ; i < MAX ; ++i ){
        if( is_prime[ i]  )
            primes[ len++ ] = i;
    }
}

int main(){
    sieve();
    int n , m , f;
    while(scanf("%d %d" , &n , &m) && n|m ){
        memset( factors, 0, sizeof(factors) );
        for( int i = 0 ; i < n && scanf("%d" , &f ) ; ++i ){
            for( int j = 0 ; j < len && primes[ j ] <= f ; ++j ){
                for( int k = primes[ j ] ; k <= f ; k *= primes[ j ] ){
                    factors[ primes[ j ] ] += f/k;
                }
            }
        }

        for( int i = 0 ; i < m && scanf("%d" , &f ) ; ++i ){
            for( int j = 0 ; j < len && primes[ j ] <= f ; ++j ){
                for( int k = primes[ j ] ; k <= f ; k *= primes[ j ] ){
                    factors[ primes[ j ] ] -= f/k;
                }
            }
        }

        bool correct = true;
        for( int i = 0 ; i < MAX ; ++i ){
            if( factors[ i ] != 0 ){
                correct = false;
                break;
            }
        }

        if( !correct )
            printf("NO\n");
        else
            puts("YES");
    }
    return 0;
}
