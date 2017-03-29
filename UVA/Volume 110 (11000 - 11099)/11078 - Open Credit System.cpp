/*****************************************
 ***Problema: Open Credit System
 ***ID: 11078
 ***Juez: UVA
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
int MIN( int a , int b ){ return ( a < b ) ? a : b; }
int MAX( int a , int b ){ return ( a < b ) ? b : a; }
int main(){

    int t , n , x , maxi, ant, aux , m, a[ 100005 ],b[100005];
    scanf("%d" , &t );
    while( t-- ){
        scanf("%d" , &n );
        maxi = -10000000;
        ant = 0;
        aux = maxi;
        m = maxi;
        for( int i = 0 ; i < n ; ++i ){
            scanf("%d" , &a[ i ] );
        }
        b[ n - 1 ] = a[ n - 1 ];
        for( int i = n - 2 ; i >= 0 ; --i ){
            b[ i ] = MIN( a[ i ] , b[ i + 1 ] );
        }
        for( int i = 0 ; i < n - 1 ; ++i ) maxi = MAX( maxi , a[ i ] - b[ i + 1 ] );
        printf("%d\n" , maxi );
    }

    return 0;
}
