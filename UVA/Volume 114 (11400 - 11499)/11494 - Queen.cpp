/*****************************************
 ***Problema: Queen
 ***ID: 11494
 ***Juez: UVA
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>

int abs( int x ){
    if( x < 0 ) x = -x;
    return x;
}

int main(){
    int x1 , y1 , x2 , y2;
    while( scanf("%d %d %d %d" , &x1 , &y1 , &x2 , &y2 ) , x1|x2|y1|y2){
        if( x1 == x2 && y1 == y2 ) puts("0");
        else if( x1 == x2 || y1 == y2 || abs( x1 - x2 ) == abs( y1 - y2 ) )puts("1");
        else puts("2");
    }
    return 0;
}
