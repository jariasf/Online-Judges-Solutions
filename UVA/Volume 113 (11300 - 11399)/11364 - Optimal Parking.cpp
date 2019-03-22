/*****************************************
 ***Problema: Optimal Parking
 ***ID: 11364
 ***Juez: UVA
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>

int main(){
    int t , n , max , min , x;
    scanf("%d" , &t );
    while( t-- ){
        scanf("%d" , &n );
        max = -1; min = 100;
        while( n-- ){
            scanf("%d" , &x );
            max = ( x > max )? x: max;
            min = ( x < min )? x : min;
        }
        printf("%d\n" , 2 * ( max - min ) );
    }

    return 0;
}
