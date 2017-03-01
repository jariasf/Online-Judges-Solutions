/***************************************************
 ***Problema: Goldbatch and Euler
 ***ID: 10311
 ***Juez: UVA
 ***Tipo: Number Theory, sieve, goldbatch conjecture
 ***Autor: Jhosimar George Arias Figueroa
 ***************************************************/

/// MAX la raiz del limite maximo porque 10000* 10000 nos da el total
/// y para saber si es primo es necesario solo iterar hasta i * i <= MAX
#include <cmath>
#include <stdio.h>
#define MAX 10001

bool used[MAX];
int N;
int prime[2000],count_p=0;

void sieve(){
    prime[ count_p++ ] = 2;
    for(int i = 3 ; i <= (MAX) ; i += 2){
        if( !used[ i ] ){
            prime[ count_p++ ] = i;
            for(int j = i ; j <= MAX/i ; j += 2 )
                used[ (j * i) ] = true;
        }
    }
}


bool is_prime( int n ){
    if( n < MAX ) return !used[ n ];
    int len = (int)sqrt( n );
    for( int i = 0 ; i < count_p && prime[ i ] <= sqrt( n ) ; ++i ){
         if( n % prime[ i ] == 0 )return false;
    }
    return true;

}

int main(){
    int n;
    sieve();
    while ( scanf( "%d", &n ) != EOF ){

        if( n < 3 ){
            printf("%d is not the sum of two primes!\n",n);
            continue;
        }

        if( n&1 && n > 4){

            if( is_prime( n - 2 ) ){
                printf("%d is the sum of 2 and %d.\n", n , n-2);
            }
            else printf("%d is not the sum of two primes!\n",n);
            continue;
        }
        int start = n/2 - 1;
        ///si es par obviamente no es primo x eso le resto uno
        start -= ( start & 1 ) < 1;
        ///start es impar por lo q si resto en unidades tendre par q nunca sera primo
        ///por eso resto de dos en dos
        bool b = false;
        int i = start;
        for( ; i >=3 ; i -= 2 ){
            if( is_prime( i ) && is_prime( n - i ) ){
               b = true;
               break;
            }
        }
        if( b )printf("%d is the sum of %d and %d.\n",n, i , n - i );
        else printf("%d is not the sum of two primes!\n",n);
    }

}
