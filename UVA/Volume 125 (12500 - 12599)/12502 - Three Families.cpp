/*****************************************
 ***Problema: Three Families
 ***ID: 12502
 ***Juez: UVa
 ***Tipo: Math
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
int main(){
    int t , a , b , z;
    scanf("%d" , &t );
    while( t-- > 0 && scanf("%d %d %d" , &a , &b , &z ) ){
        printf("%d\n" , z * ( 2 * a - b ) /( a + b ) );
    }
    return 0;
}
