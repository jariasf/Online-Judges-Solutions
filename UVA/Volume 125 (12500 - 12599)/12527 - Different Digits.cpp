/*****************************************
 ***Problema: Different Digits
 ***ID: 12527
 ***Juez: UVA
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <cstring>
#define MAX 5005

int a[ MAX ] , dp[ MAX ];

bool equal( int n ){
    int a[ 10 ] = { 0 };
    while( n > 0 ){
        if( a[ n % 10 ] ) return true;
        a[ n % 10 ]++;
        n /= 10;
    }
    return false;
}

int main(){
    int a , b , i;
    memset( dp , 0 , sizeof( dp ) );
    for( i = 1 ; i < MAX ; ++i ){
        if( !equal( i ) ) dp[ i ] = dp[ i - 1 ] + 1;
        else dp[ i ] = dp[ i - 1 ];
    }

    while( scanf("%d %d" , &a , &b ) != EOF ){
        printf("%d\n" , dp[ b ] - dp[ a - 1 ] );
    }

    return 0;
}
