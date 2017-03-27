/*****************************************
 ***Problema: Mother Bear
 ***ID: 10945
 ***Juez: UVA
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <cstring>
#include <ctype.h>
int main(){
    char line[ 1005 ];
    char s[ 1005 ];
    int l , len;
    while( gets( line ) && strcmp( line , "DONE")  ){
        l = strlen( line );
        len = 0;
        for( int i = 0 ; i < l ; ++i ){
            if( ( 'a' <=line[ i ] && line[ i ] <= 'z' ) || ( 'A' <=line[ i ] && line[ i ] <= 'Z' ))
                s[ len++ ] = tolower( line[ i ] );
        }
        s[ len ] = '\0';
        int i;
        for( i = 0 ; i < len ; ++i){
            if( s[ i ] != s[ len - i - 1 ] )break;
        }
        if( i == len )puts("You won't be eaten!");
        else puts("Uh oh..");
    }
    return 0;
}
