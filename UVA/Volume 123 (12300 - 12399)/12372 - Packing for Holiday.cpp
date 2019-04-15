/*****************************************
 ***Problema: Packing for Holiday
 ***ID: 12372
 ***Juez: UVA
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
int main(){
    int t , l , w ,h, q ;
    scanf("%d" , &t );
    for( q = 1 ; q <= t && scanf("%d %d %d" , &l , &w , &h ) ; ++q){
        printf("Case %d: " , q );
        if( l <= 20 && w <= 20  && h <= 20 ) puts("good");
        else puts("bad");
    }
    return 0;
}
