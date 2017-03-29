/*****************************************
 ***Problema: Add bricks in the wall
 ***ID: 11040
 ***Juez: UVA
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <cstring>

#define MAX 10
int ady[ MAX ][ MAX ];
int a[ MAX ][ MAX ];
int main(){

    int t;
    scanf("%d" , &t );
    while( t-- ){
        memset( ady , 0 , sizeof( ady ) );
        for( int i = 0 ; i < 9 ; i += 2 ){
            for( int j = 0 ; j <= i; j += 2 ){
                scanf("%d" , &ady[ i ][ j ] );
            }
        }
        //impares
        for( int i = 2 ; i < 9 ; i += 2 ){
            for( int j = 1 ; j <=i ; j += 2 ){
                ady[ i ][ j ] = ( ady[ i - 2 ][ j - 1 ] - ady[ i ][ j - 1 ] - ady[ i ][ j + 1 ])/2;
            }
        }
        //pares
        for( int i = 1 ; i < 9 ; i += 2 ){
            for( int j = 0 ; j <= i ; j ++ ){
                ady[ i ][ j ] = ady[ i + 1 ][ j ] + ady[ i + 1 ][ j + 1 ];
            }
        }
        for( int i = 0 ; i < 9 ; ++i ){
            for( int j = 0 ; j <= i ; ++j ){
                if( j )printf(" ");
                printf("%d" , ady[ i ][ j ] );
            }
            printf("\n");
        }

    }

    return 0;
}
