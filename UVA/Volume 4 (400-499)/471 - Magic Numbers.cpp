/*****************************************
 ***Problema: Magic Numbers
 ***ID: 471
 ***Juez: UVA
 ***Tipo: Brute Force
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>

bool unique( long long n ){
    bool seen[ 10 ] = { 0 };
    while( n > 0 ){
        if( seen[ n % 10 ] )return false;
        seen[ n % 10 ] = 1;
        n /= 10;
    }
    return true;
}

int main(){
    long long n , s2 , s1;
    int t;
    scanf("%d" , &t );
    for( int q = 0 ; q < t ; ++q ){
        if( q )putchar('\n');
        scanf("%lld" , &n );
        s2 = 1;
        for( ; ; ++s2 ){
            s1 = s2 * n;
            if( s1 > 9876543210LL ) break;
            if( unique( s1 ) && unique( s2 ) ){
                printf("%lld / %lld = %lld\n" , s1 , s2 , n );
            }
        }
    }
    return 0;
}
