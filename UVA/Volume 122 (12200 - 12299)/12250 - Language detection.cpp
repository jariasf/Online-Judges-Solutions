/*****************************************
 ***Problema: Language Detection
 ***ID: 12250
 ***Juez: UVA
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <cstring>
int main(){
    int q = 1;
    char s[ 15 ];
    while( gets( s )  && s[ 0 ] != '#' ){

        printf("Case %d: " , q++ );
        if( !strcmp( s , "HELLO") ) puts("ENGLISH");
        else if( !strcmp( s , "HOLA") ) puts("SPANISH");
        else if( !strcmp( s , "HALLO" ) ) puts("GERMAN");
        else if( !strcmp( s , "BONJOUR") ) puts("FRENCH");
        else if( !strcmp( s , "CIAO") ) puts("ITALIAN");
        else if( !strcmp( s , "ZDRAVSTVUJTE"))puts("RUSSIAN");
        else puts("UNKNOWN");
    }

    return 0;
}
