/*****************************************
 ***Problema: Egypt
 ***ID: 11854
 ***Juez: UVA
 ***Tipo: Geometry
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>

int main(){
    int a , b , c;
    while( scanf("%d %d %d" , &a , &b , &c ) && ( a|b|c ) ){
        if( a < b + c && b < a + c && c < a + b ){
            if( a * a - c * c == b * b || b * b - c * c == a * a || c * c - b * b == a * a )puts("right");
            else puts("wrong");
        }
        else puts("wrong");
    }
    return 0;
}
