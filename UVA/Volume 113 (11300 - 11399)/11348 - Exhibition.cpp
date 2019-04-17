/*****************************************
 ***Problema: Exhibition
 ***ID: 11348
 ***Juez: UVA
 ***Tipo: Map
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <stdlib.h>
#include <cctype>
#include <cmath>
#include <cstdio>
#define MAX 55
#define MAXN 10005
int n , cnt[ MAX ] , a[ MAX ][ MAX ] , cum[ MAXN ] , num[ MAX ] , seen[ MAXN ];
int main(){
    int t , q , i , j , tot;
    scanf("%d" , &t );
    for( q = 1 ; q <= t && scanf("%d" , &n ) ; ++q ){
        memset( cum , 0 , sizeof( cum ) );
        memset( num , 0 , sizeof( num ) );
        for( i = 0 ; i < n && scanf("%d" , &cnt[ i ] ) ; ++i ){
            memset( seen , 0 , sizeof( seen ) );
            for( j = 0 ; j < cnt[ i ] && scanf("%d" , &a[ i ][ j ] ); ++j ){
                if( !seen[ a[ i ][ j ] ]){
                    cum[ a[ i ][ j ] ]++;
                }
                seen[ a[ i ][ j ] ] = 1;
            }
        }

        tot = 0;
        for( i = 0 ; i < n ; ++i ){
            memset( seen , 0 , sizeof( seen ) );
            for( j = 0 ; j < cnt[ i ] ; ++j ){
                if( !seen[ a[ i ][ j ] ] && cum[ a[ i ][ j ] ] == 1 ){
                    tot++;
                    num[ i ]++;
                }
                seen[ a[ i ][ j ] ] = 1;
            }
        }
        printf("Case %d:" , q );
        for( i = 0 ; i < n ; ++i ){
            printf(" %.6lf%s" , num[ i ] * 100.0/(double)( tot ) , "%" );
        }
        printf("\n");
    }
    return 0;
}
