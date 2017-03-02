/*****************************************
 ***Problema: Die Game
 ***ID: 10409
 ***Juez: UVA
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>

char s[ 7 ];

int dice[ 3 ][ 4 ];

int main(){

    int q , tmp;

    while( scanf("%d" , &q ) , q ){
        dice[ 0 ][ 1 ] = 2;
        dice[ 1 ][ 0 ] = 3;
        dice[ 1 ][ 1 ] = 1;
        dice[ 1 ][ 2 ] = 4;
        dice[ 2 ][ 1 ] = 5;
        dice[ 3 ][ 1 ] = 6;
        while( q-- ){


            scanf("%s" , &s );

            if( s[ 0 ] == 'n' ){
                tmp = dice[ 0 ][ 1 ];
                dice[ 0 ][ 1 ] = dice[ 1 ][ 1 ];
                dice[ 1 ][ 1 ] = dice[ 2 ][ 1 ];
                dice[ 2 ][ 1 ] = dice[ 3 ][ 1 ];
                dice[ 3 ][ 1 ] = tmp;
            }
            else if( s[ 0 ] == 's' ){
                tmp = dice[ 3 ][ 1 ];
                dice[ 3 ][ 1 ] = dice[ 2 ][ 1 ];
                dice[ 2 ][ 1 ] = dice[ 1 ][ 1 ];
                dice[ 1 ][ 1 ] = dice[ 0 ][ 1 ];
                dice[ 0 ][ 1 ] = tmp;
            }
            else if( s[ 0 ] == 'w' ){
                tmp = dice[ 1 ][ 0 ];
                dice[ 1 ][ 0 ] = dice[ 1 ][ 1 ];
                dice[ 1 ][ 1 ] = dice[ 1 ][ 2 ];
                dice[ 1 ][ 2 ] = dice[ 3 ][ 1 ];
                dice[ 3 ][ 1 ] = tmp;
            }
            else if( s[ 0 ] == 'e' ){
                tmp = dice[ 1 ][ 2 ];
                dice[ 1 ][ 2 ] = dice[ 1 ][ 1 ];
                dice[ 1 ][ 1 ] = dice[ 1 ][ 0 ];
                dice[ 1 ][ 0 ] = dice[ 3 ][ 1 ];
                dice[ 3 ][ 1 ] = tmp;

            }

        }
        printf("%d\n" , dice[ 1 ][ 1 ] );
    }

    return 0;
}
