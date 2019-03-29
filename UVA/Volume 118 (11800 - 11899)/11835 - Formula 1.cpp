/*****************************************
 ***Problema: Formula 1
 ***ID: 11835
 ***Juez: UVA
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <cstring>

#define MAX 108
int main(){

    int g , n , s , k;
    int a[ MAX ] , position[ 105 ][ MAX ] , points[ MAX ];
    while( scanf("%d %d" , &g , &n ) , g|n ){
                for( int j = 0 ; j < g ; ++j ){
            for( int i = 0 ; i < n ; ++i ){
                scanf("%d" , &position[ j ][ i ] );
            }
        }
        scanf("%d" , &s );
        while( s-- ){
            scanf("%d" , &k );
            memset( points , 0 , sizeof( points ) );
            memset( a , 0 , sizeof( a ) );
            for( int i = 0 ; i < k ; ++i ) scanf("%d" , &points[ i ]);
            for( int i = 0 ; i < g ; ++i ){
                for( int j = 0 ; j < n ; ++j ){
                    a[ j ] += points[ position[ i ][ j ] - 1 ];
                }
            }
            int maxi = 0;
            for( int i = 0 ; i < n ; ++i ){
                if( a[ i ] > maxi ) maxi = a[ i ];
            }
            bool first = true;
            for( int i = 0 ; i < n ; ++i ){
                if( a[ i ] == maxi ){
                    if( !first ) printf(" ");
                    printf("%d" , i + 1 );
                    first = false;
                }
            }
            printf("\n");
        }

    }

    return 0;
}
