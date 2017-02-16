/*****************************************
 ***Problema: Take the land
 ***ID: 10074
 ***Juez: UVA
 ***Tipo: DP, Maximum 2D sum
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#define MAX 105
int h , w;
int a[ MAX ][ MAX ], sum , s , maxi, n;
int pr[ MAX ];
int Kadane2D(){
    maxi = 0;
    int resp = 0;
    int k, l , x1 = 0 , x2 = 0 , y1 = 0, y2 = 0, j;
    for( int z = 0 ; z < h; ++z ){
         for( int i = 0 ; i < w ; ++i ) pr[ i ] = 0;
         for( int x = z ; x < h ; ++x ){
             s = 1<<31;
             sum = 0;
             for( int i = 0 ; i < w ; ++i ){

                 pr[ i ] += a[ x ][ i ];
                 sum += pr[ i ];
                 if( sum > s ){
                     s = sum;
                 }
                 if( sum < 0 ){
                     sum = 0;
                 }
             }
             if( s > maxi ){
                 maxi = s;
             }
         }

    }
    return maxi;
}

int main(){
    int x;
    while( scanf("%d %d" , &h , &w ) && h|w ){
        for( int i = 0 ; i < h ; ++i ){
            for( int j = 0 ; j < w ; ++j ){
                scanf("%d" , &x );
                if( x == 1 ) a[ i ][ j ] = -10050;
                else a[ i ][ j ] = 1;
            }
        }
        printf("%d\n" , Kadane2D() );

    }
	return 0;
}

