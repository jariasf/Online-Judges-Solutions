/*****************************************
 ***Problema: Google is Feeling Lucky
 ***ID: 12015
 ***Juez: UVA
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <cstring>

int main(){

    int t;
    char web[ 11 ][ 105 ];
    int val[ 11 ] , max;
    scanf("%d" , &t );
    for( int q = 1 ; q <= t ; ++q ){
        max = 0;
        for( int i = 0 ; i < 10 ; ++i ){
            scanf("%s %d" , web[ i ] , &val[ i ] );
            max = ( val[ i ] > max )? val[ i ] : max;
        }
        printf("Case #%d:\n" , q);
        for( int i = 0 ; i < 10 ; ++i ){
            if( val[ i ] == max )printf("%s\n" , web[ i ] );
        }

    }

    return 0;
}
