/*****************************************
 ***Problema: Murcia's Skyline
 ***ID: 11790
 ***Juez: UVA
 ***Tipo: DP , LIS , LDS
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#define MAX 2005
int h[ MAX ] , w[ MAX ] , dp[ MAX ];
int n , w_lis , w_lds , i , j;
int maximo( int a , int b ){ return ( a > b )? a : b; }

void LDS(){
    w_lds = 0;
    for( i = 0 ; i < n ; ++i ){
        dp[ i ] = w[ i ];
        for( j = 0 ; j < i ; ++j ){
            if( h[ j ] > h[ i ] ){
                dp[ i ] = maximo( dp[ i ] , dp[ j ] + w[ i ] );
            }
        }
        w_lds = maximo( w_lds , dp[ i ] );
    }
}

void LIS(){
    w_lis = 0;
    for( i = 0 ; i < n ; ++i ){
        dp[ i ] = w[ i ];
        for( j = 0 ; j < i ; ++j ){
            if( h[ j ] < h[ i ] ){
                dp[ i ] = maximo( dp[ i ] , dp[ j ] + w[ i ] );
            }
        }
        w_lis = maximo( w_lis , dp[ i ] );
    }
}

int main(){
    int q , t;
    scanf("%d" , &q );
    for( t = 1 ; t <= q && scanf("%d" , &n ) ; ++t ){
        for( i = 0 ; i < n && scanf("%d" , &h[ i ] ) ; ++i );
        for( i = 0 ; i < n && scanf("%d" , &w[ i ] ) ; ++i );
        LIS();
        LDS();
        if( w_lis >= w_lds )printf("Case %d. Increasing (%d). Decreasing (%d).\n" , t , w_lis , w_lds );
        else printf("Case %d. Decreasing (%d). Increasing (%d).\n" , t , w_lds , w_lis );
    }
    return 0;
}
