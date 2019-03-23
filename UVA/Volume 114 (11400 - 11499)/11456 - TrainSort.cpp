/*****************************************
 ***Problema: TrainSort
 ***ID: 11456
 ***Juez: UVA
 ***Tipo: DP, LIS, LDS
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>

#define MAX 2005
int a[ MAX ], lds[ MAX ], incr[ MAX ] , decr[ MAX ];
int n;

int maximo( int a , int b ){ return ( a > b )? a:b; }
int LIS(){
    int len, j , i, t;
    ///LDS de atras hacia adelante
    lds[ incr [ n - 1 ] = len = 1 ] = -a[ n - 1 ];
    for( int p = n - 2 ; p >= 0  ; --p ){
        if( -a[ p ] > lds[ len ] ){
            lds[ incr[ p ] = ++len ] = -a[ p ];
            continue;
        }

        for( i = 1 , j = len ; i < j ; ){
             if( lds[ t = (i + j )>>1 ] < -a[ p ] ) i = t + 1; else j = t;
        }
        incr[ p ] = i;
        lds[ i ] = -a[ p ];
    }

    ///LIS de atras hacia adelante
    lds[ decr[ n - 1 ] = len = 1 ] = a[ n - 1 ];
    for( int p = n - 2 ; p >= 0 ; --p ){
        if( a[ p ] > lds[ len ] ){
            lds[ decr[ p ] = ++len ] = a[ p ];
            continue;
        }

        for( i = 1 , j = len ; i < j ; ){
             if( lds[ t = (i + j )>>1 ] < a[ p ] ) i = t + 1; else j = t;
        }
        decr[ p ] = i;
        lds[ i ] = a[ p ];
    }

    len = 0;
    for( int i = 0 ; i < n ; ++i ){
        len = maximo( len , incr[ i ] + decr[ i ] - 1 );
    }

    return len;
}


int main(){
    int q;
    scanf("%d" , &q );
    while( q-- ){
        scanf("%d" , &n );
        for( int i = 0 ; i < n ; ++i )
            scanf("%d" , &a[ i ] );
        printf("%d\n" , LIS() );
    }

    return 0;
}
