/*****************************************
 ***Problema: Cheapest Base
 ***ID: 11005
 ***Juez: UVA
 ***Tipo: Number Theory
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>

int min( int a , int b ){ return ( a < b ) ? a : b; }
int cost[ 400  ];
int toBaseN( int n , int base ){
    int sum = 0;
    while( n > 0 ){
        if( n % base > 9 ) sum += cost[ ( n % base - 10 ) + 'A' ];
        else sum += cost[ n % base + '0' ];
        n /= base;
    }
    return sum;
}

int main(){
    int t , Q , n , mini, a[ 40 ];
    scanf("%d" , &t );

    for( int q = 1 ; q <= t ; ++q ){
        if( q - 1 )putchar('\n');
        for( int i = 0 ; i < 10 ; ++i ) scanf("%d" , &cost[ i + '0'] );
        for( int i = 0 ; i < 26 ; ++i ) scanf("%d" , &cost[ i + 'A' ] );
        scanf("%d" , &Q );
        printf("Case %d:\n" , q );
        while( Q-- ){
            scanf("%d" , &n );
            mini = 1<<30;
            for( int i = 2 ; i < 37 ; ++i ){
                a[ i ] = toBaseN( n , i );
                mini = min( mini , a[ i ] );
            }
            printf("Cheapest base(s) for number %d:" , n );
            for( int i = 2 ; i < 37 ; ++i ){
                if( a[ i ] == mini )printf(" %d" , i );
            }
            printf("\n");
        }
    }

    return 0;
}
