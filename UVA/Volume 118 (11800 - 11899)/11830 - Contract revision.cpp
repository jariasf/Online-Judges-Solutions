/*****************************************
 ***Problema: Contract revision
 ***ID: 11830
 ***Juez: UVA
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <cstring>

int main(){
    char c;
    char s[ 1005 ] , s2[ 1005 ];
    int l, zeros, len;
    while( scanf("\n%c %s" , &c , &s ) == 2 ){
        if( c == '0' && strcmp( s , "0") == 0 )break;
        l = strlen( s );
        len = 0;
        zeros = 1;
        for( int i = 0 ; i < l ; ++i ){
            if( s[ i ] == c )continue;
            if( s[ i ] != '0' )zeros = 0;
            if( !zeros )s2[ len++ ] = s[ i ];

        }
        s2[ len ] = '\0';
        if( zeros )puts("0");
        else printf("%s\n" , s2 );
    }

    return 0;
}
