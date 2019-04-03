/*****************************************
 ***Problema: One-Two-Three
 ***ID: 12289
 ***Juez: UVA
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <cstring>

int main(){
    int t , cnt;
    scanf("%d" , &t );
    char s[ 6 ];
    while( t-- ){
        cnt = 0;
        scanf("%s" , &s );
        if( strlen( s ) == 3 ){
            if( s[ 0 ] == 'o' )cnt++;
            if( s[ 1 ] == 'n' ) cnt++;
            if( s[ 2 ] == 'e' )cnt++;
            if( cnt >= 2 )puts("1");
            else puts("2");
        }
        else puts("3");
    }
    return 0;
}
