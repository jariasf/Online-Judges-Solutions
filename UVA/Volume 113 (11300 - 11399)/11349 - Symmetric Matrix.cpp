/*****************************************
 ***Problema: Symmetric Matrix
 ***ID: 11349
 ***Juez: UVA
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>

long long a[ 105 ][ 105 ] , n;
bool isSimetrica(){
    int len = ( n & 1 )? ( n + 1 ) /2: n/2;
    for( int i = 0 ; i < len ; ++i ){
        for( int j = 0 ; j < n ; ++j ){
            if( a[ i ][ j ] != a[ n - i - 1 ][ n - j - 1 ] || a[ i ][ j ] < 0 )return false;
        }
    }
    return true;
}

int main(){
    int t;
    char c;
    scanf( "%d" , &t );

    for( int q = 1 ; q <= t ; ++q ){
        scanf(" %c %c %d" , &c , &c , &n );

        for( int i = 0 ; i < n ; ++i )
            for( int j = 0 ; j < n ; ++j ){
                scanf( "%lld" , &a[ i ][ j ] );
            }

        printf("Test #%d: " , q );
        if( isSimetrica() ) printf("Symmetric.\n");
        else printf("Non-symmetric.\n");
    }

    return 0;
}
