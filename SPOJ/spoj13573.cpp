/*****************************************
 ***Problema: Amazing Prime Sequence
 ***ID: 13573
 ***Juez: SPOJ
 ***Tipo: Sieve
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#define MAX 10000005
int prime[ MAX ];
long long a[ MAX] , p[ MAX ];
void sieve(){
    for( int i = 1 ; i < MAX ; ++i ){
        prime[ i ] = 1;
        p[ i ] = 0;
    }
    prime[ 1 ] = prime[ 0 ] = 0;
    for(int i = 2 ; i <= MAX ; ++i ){
        if( prime[ i ] ){
            p[ i ] = i;
            for(int k = 2 ; k * i <= MAX ; ++k){
                prime[ k * i ] = 0;
                if( !p[ k * i ] ){
                    p[ k *i ] = i;
                }
            }
        }
    }
}

int main(){
    sieve();
    a[ 0 ] = 0;
    for( int i = 1 ; i < MAX ; ++i ){
        a[ i ] = a[ i - 1 ] + p[ i ];
    }

    int t , n;
    scanf("%d" , &t );
    while( t-- > 0 && scanf("%d" , &n ) ){
        printf("%lld\n" , a[ n ] );
    }

    return 0;
}
