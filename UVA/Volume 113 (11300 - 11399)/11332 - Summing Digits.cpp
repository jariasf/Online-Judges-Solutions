/*****************************************
 ***Problema: Summing Digits
 ***ID: 11332
 ***Juez: UVA
 ***Tipo: Ad hoc, recursion
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>

int f( int n ){
    return ( n < 10 )? n : n%10 + f( n/10 );
}

int main(){

    int n;
    while( scanf( "%d" ,&n ) && n){
        int x = f( n );
        while( x > 9) x = f( x );
        printf( "%d\n" , x );
    }

    return 0;
}
