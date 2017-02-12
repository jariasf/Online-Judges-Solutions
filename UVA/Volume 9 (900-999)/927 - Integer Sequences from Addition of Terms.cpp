/******************************************************
 ***Problema: Integer Sequences from Addition of Terms
 ***ID: 927
 ***Juez: UVA
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************************/

#include <stdio.h>
#include <cstring>

long long pow( int a , int b ){
    long long ans = 1;
    for( int i = 1 ; i <= b ; ++i ) ans *= a;
    return ans;
}
#define MAX 100005
long long a[ MAX ], ini[ MAX ] , fin[ MAX ], sum , ant, c[ 55 ], d ;
int main(){

    int t, l,  n , k;
    scanf("%d" , &t );
    while( t-- ){
        scanf("%d" , &n );
        for( int i = 0 ; i <= n ; ++i ) scanf("%lld" , &c[ i ] );
        scanf("%d %d" , &d , &k );
        l = 1;
        sum = 0;
        ant = 1;
        memset( a , 0LL , sizeof( a ) );
        for(  ;  ; ++l ){
            for( int j = 0 ; j <= n ; ++j ){
                a[ l ] += c[ j ] * pow( l , j );
            }
            sum += d * l;
            ini[ l ] = ant;
            fin[ l ] = sum;
            ant = fin[ l ] + 1;
            if( sum > 1000000LL )break;
        }

        for( int i = 1 ; i <= l ; ++i ){
            if( k >= ini[ i ] && k <= fin[ i ] ){
                printf("%lld\n" , a[ i ] );
                break;
            }
        }
    }
    return 0;
}
