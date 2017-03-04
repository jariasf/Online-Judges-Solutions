/*****************************************
 ***Problema: Combination Lock
 ***ID: 10550
 ***Juez: UVA
 ***Tipo: Simulation
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>

int main(){
    int d , a , b , c , ans, aux;
    while( scanf("%d %d %d %d" , &d , &a , &b , &c ) && a|b|c|d ){
        ans = 1080;
        if( d < a )  ans += ( d + 40 - a ) * 9;
        else ans += ( d - a ) * 9;
        if( b >= a ) ans += ( b - a ) * 9;
        else ans += ( 40 - a  + b ) * 9;
        if( b < c ) ans += ( b + 40 - c ) * 9;
        else ans += ( b - c ) * 9;
        printf("%d\n" , ans );
    }
    return 0;
}
