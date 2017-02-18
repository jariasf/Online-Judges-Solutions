/*****************************************
 ***Problema: Ocean Deep! Make it shallow!!
 ***ID: 10176
 ***Juez: UVA
 ***Tipo: Number Theory, Modulo, bitwise
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#define MOD 131071

int main(){
    int c, r;
    for(r = 0; ( c = getchar() ) !=EOF; ){
        if( c == '0' ){
            r = ( r << 1 ) % MOD;
        }
        else if( c == '1' ){
            r = ( ( r << 1 ) | 1 ) % MOD;
        }
        else if( c == '#'){
            printf( r ? " NO\n" : "YES\n");
            r = 0;
        }
    }
    return 0;
}
