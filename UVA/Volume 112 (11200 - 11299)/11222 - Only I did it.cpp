/*****************************************
 ***Problema: Only I did it!
 ***ID: 11222
 ***Juez: UVA
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <cstring>
#include <algorithm>
#define MAX 1005
int main(){
    int a[ 3 ][ MAX ], len[ 3 ], seen[ 10005 ], cnt[ 3 ];
    int t , k ;
    scanf("%d" , &t );
    for( int q = 1 ; q <= t ; ++q ){
        memset( seen , 0 , sizeof( seen ) );
        memset( a , 0 , sizeof( a ) );
        for( int i = 0 ; i < 3 ; ++i ){
            scanf("%d" , &len[ i ] );
            for( int j = 0 ; j < len[ i ] ; ++j ){
                scanf("%d" , &a[ i ][ j ] );
                seen[ a[ i ][ j ] ]++;
            }
        }
        int maxi = -1;
        for( int i = 0 ; i < 3 ; ++i ){
            cnt[ i ] = 0;
            for( int j = 0 ; j < len[ i ] ; ++j ){
                if( seen[ a[ i ][ j ] ] == 1 ){
                    cnt[ i ]++;
                }
            }
            if( cnt[ i ] > maxi ) maxi = cnt[ i ];
        }

        printf("Case #%d:\n" , q );
        for( int i = 0 ; i < 3 ; ++i ){
            if( cnt[ i ] == maxi ){
                printf("%d %d" , i + 1 , cnt[ i ]);
                std::sort( a[ i ] , a[ i ] + len[ i ] );
                for( int j = 0 ; j < len[ i ] ; ++j ){
                    if( seen[ a[ i ][ j ] ] == 1 )printf(" %d" , a[ i ][ j ] );
                }
                printf("\n");
            }
        }
    }
    return 0;
}
