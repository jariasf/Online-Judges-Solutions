/*****************************************
 ***Problema: Code Number
 ***ID: 11946
 ***Juez: UVA
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <cstring>
#include <stdlib.h>
#include <iostream>
char val[ 11 ] = {'O','I','Z','E','A','S','G','T','B','P','\0'};

int main(){
    int t;
    char s[ 90 ];
    scanf("%d\n" , &t );
    for( int q = 0 ; q < t ; ++q ){
        if( q )putchar('\n');
        while( gets( s ) ){
            int l = strlen( s );
            if( l == 0 )break;
            for( int i = 0 ; i < l ; ++i ){
                if( isdigit( s[ i ] ) )putchar( val[ s[ i ] -'0' ] );
                else putchar( s[ i ] );
            }
            putchar('\n');
        }
    }
    return 0;
}
