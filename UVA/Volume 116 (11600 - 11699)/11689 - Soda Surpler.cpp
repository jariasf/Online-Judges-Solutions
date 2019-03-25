/*****************************************
 ***Problema: Soda Surpler
 ***ID: 11689
 ***Juez: UVA
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
	int b , b1 , b2 , c , d , t;
	scanf("%d" , &t );
    while( t-- ){
        scanf("%d %d %d" , &b1 , &b2 , &c );
        b = b1 + b2;
        d = 0;
        if( b1 == b2 && b2 == c ){ printf("0\n"); continue; }
        while ( b >= c ) {
            b -= c;
            b++;
            d++;
        }
        printf( "%d\n" , d );
	}
	return 0;
}
