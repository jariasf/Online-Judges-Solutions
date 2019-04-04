/*****************************************
 ***Problema: NumPuzz I
 ***ID: 12398
 ***Juez: UVA
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <cstring>
int dx[ 5 ] = { 0 , 1 , -1 , 0 ,  0 };
int dy[ 5 ] = { 0 , 0 ,  0 , 1 , -1 };
int main(){
    char s[ 205 ];
    int coor[ 9 ][ 2 ] = { { 0 , 0 } , { 0 , 1 } , { 0 , 2 } , { 1,  0} , { 1 , 1 } , { 1 , 2 } , { 2 , 0 } , { 2 , 1 } , { 2 , 2 } };
    int ady[ 4 ][ 4 ], q = 1 , nx , ny;
    while( gets( s ) ){
        memset( ady , 0 , sizeof( ady ) );
        for( int i = 0 ; s[ i ] ; ++i ){
            for( int j = 0 ; j < 5 ; ++j ){
                nx = dx[ j ] + coor[ s[ i ] - 'a' ][ 0 ];
                ny = dy[ j ] + coor[ s[ i ] - 'a' ][ 1 ];
                if( nx >= 0 &&  ny >= 0 && nx < 3 && ny < 3  ){
                    ady[ nx ][ ny ] = ( ady[ nx ][ ny ] + 1 ) % 10;
                }
            }
        }
        printf("Case #%d:\n" , q++ );
        for( int i = 0 ; i < 3 ; ++i ){
            for( int j = 0 ; j < 3 ; ++j ){
                if( j ) printf(" ");
                printf("%d" , ady[ i ][ j ] );
            }
            putchar('\n');
        }
    }
    return 0;
}
