/*****************************************
 ***Problema: Digit Coutning
 ***ID: 1225
 ***Juez: UVA
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>

int main(){
    int n , t;
    int a[ 10005 ][ 10 ];
    for( int i = 1 ; i <= 10000 ; ++i ){
        int aux = i;
        for( int j = 0 ; j < 10 ; ++j ){
            a[ i ][ j ] = a[ i - 1 ][ j ];
        }
        while( aux > 0 ){
            a[ i ][ aux % 10 ]++;
            aux /= 10;
        }

    }
    scanf("%d" , &t );
    while( t-- ){
        scanf("%d" , &n );
        printf("%d" , a[ n ][ 0 ] );
        for( int i = 1 ; i < 10 ; ++i ){
            printf(" %d" , a[ n ][ i ] );
        }
        putchar('\n');
    }

    return 0;
}
