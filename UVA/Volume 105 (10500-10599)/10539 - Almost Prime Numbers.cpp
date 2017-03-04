/*********************************************
 ***Problema: Almost Prime Numbers
 ***ID: 10539
 ***Juez: UVA
 ***Tipo: Number Theory, sieve, binary search
 ***Autor: Jhosimar George Arias Figueroa
 ********************************************/

#include <stdio.h>
#include <algorithm>

using namespace std;
#define MAX 1000005
int prime[ MAX ];
int primes[ MAX ];
int idx;
void sieve(){
    prime[ 0 ] = 0;
    for( int i = 1 ; i<= MAX ; ++i ) prime[ i ] = 1;
    for( int i = 2 ; i*i <= MAX ;++i ){
        if( prime[ i ] ){
            for( int j = i ; j * i <= MAX ; ++j ){
                prime[ j * i ] = false;
            }
        }
    }
}

long long dp[ MAX ];

void almost(){
    idx = 0;
    for( int i = 2 ; i <= MAX ; ++i ){
        if( prime[ i ] ){
            long long ini = i;
            for( long long j = ini * ini ; j <= (1000000000000LL); j *= ini ){
                 dp[ idx++ ] = j;
            }
        }
    }
}

int main(){
    int t, index, cont;
    long long low, high;
    sieve();

    almost();
    sort( dp , dp + idx );

    scanf("%d", &t );
    while( t-- ){
        cont = 0;
        scanf("%lld %lld",&low, &high);

        index = (int)( lower_bound( dp , dp + idx , low ) - dp );

        for( int i = index ; ; ++i ){
            if( dp[ i ] <= high ){
                if( dp[ i ] >= low )cont++;
            }
            else break;
        }
        printf("%d\n", cont );
    }
    return 0;
}
