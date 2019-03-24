/*****************************************
 ***Problema: Image Coding
 ***ID: 11588
 ***Juez: UVA
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <cstring>

int main(){
    int t, r , c , m , n , a[ 26 ] , resp , maxi;
    char cc;
    scanf("%d" , &t );
    for( int q = 1 ; q <= t ; ++q ){

        scanf("%d %d %d %d" , &r , &c , &m , &n );
        memset( a , 0 , sizeof( a ) );
        for( int i = 0 ; i < r ; ++i ){
            for( int j = 0 ; j < c ; ++j ){
                scanf(" %c" , &cc );
                a[ cc - 'A' ]++;
            }
        }
        maxi = 0;
        for( int i = 0 ; i < 26 ; ++i ){
            if( a[ i ] > maxi ){
                maxi = a[ i ];
            }
        }
        resp = 0;
        for( int i = 0 ; i < 26 ; ++i ){
            if( a[ i ] == maxi ) resp += a[ i ] * m;
            else resp += a[ i ] * n;
        }

        printf("Case %d: %d\n" , q , resp );
    }

    return 0;
}
