/*****************************************
 ***Problema: Bafana Bafana
 ***ID: 11805
 ***Juez: UVA
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>

int main(){

    int t,  n , k , p, ans;
    scanf("%d" , &t );
    for( int q = 1 ; q <= t; ++q ){
        scanf("%d %d %d" , &n , &k , &p );
        k = ( k + p ) %n ;
        k = ( k == 0 )?n:k;
        printf("Case %d: %d\n" , q , k );
    }

    return 0;
}
