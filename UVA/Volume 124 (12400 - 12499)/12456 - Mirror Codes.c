/*****************************************
 ***Problema: Mirror Codes
 ***ID: 12456
 ***Juez: UVA
 ***Tipo: Combinatorias
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

/*
idea
si tengo
2 4 3 2 3 4 2
los posibles seran
0 0 0 0 0 0 0
1 1 1 1 1 1 1
  2 2   2 2
  3       3

2*4*3*2

respuesta = posibles combinaciones - 2 * 4 * 3 * 2
*/
#include <stdio.h>
int main(){
    int n , mitad, x , i;
    long long total, duplicados;
    while( scanf("%d" , &n ) && n ){
        mitad = ( n + 1 )/2; duplicados = total = 1;
        for( i = 0 ; i < n ; ++i ){
            scanf("%d" , &x );
            total *= x;
            if( i < mitad ) duplicados *= x;
        }
        printf("%lld\n" , total - duplicados );
    }
    return 0;
}
