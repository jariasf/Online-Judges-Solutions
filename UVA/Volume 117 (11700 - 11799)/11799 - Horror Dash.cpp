/*****************************************
 ***Problema: Horror Dash
 ***ID: 11799
 ***Juez: UVA
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>

int main(){
    int t, k , n , maxi;
    scanf("%d" , &t );
    for( int q = 1 ; q <= t ; ++q ){
        scanf("%d" , &k );
        maxi = 0;
        while( k-- ){
            scanf("%d" , &n );
            if( n > maxi ) maxi = n;
        }
        printf("Case %d: %d\n" , q , maxi);
    }

    return 0;
}
