/*****************************************
 ***Problema: Feynman
 ***ID: 12149
 ***Juez: UVA
 ***Tipo: Math
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>

int main(){
    int n;
    while( scanf("%d" , &n ) , n ){
        printf("%d\n" , n * ( n + 1 ) * ( 2 * n + 1 )/6 );
    }
    return 0;
}
