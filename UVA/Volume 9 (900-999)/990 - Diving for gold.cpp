/*****************************************
 ***Problema: Diving for gold
 ***ID: 990
 ***Juez: UVA
 ***Tipo: DP, Knapsack
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <cstring>

#define MAX 2005
int dp[ MAX ], dep[ MAX ] , v[ MAX ], seen[ 35 ][ 1005 ];
int main(){

    int t , w , n, c;
    bool b = false;
    while( ~scanf("%d %d" , &t , &w ) ){
        if( b )putchar('\n');
        b = true;
        memset( dp , 0 , sizeof( dp ) );
        memset( seen , 0 , sizeof( seen ) );
        scanf("%d" , &n );
        for( int i = 0 ; i < n  ; ++i )
            scanf("%d %d" , &dep[ i ] , &v[ i ] );

        for( int i = n - 1 ; i >= 0 ; --i ){
            c = 3 * w * dep[ i ];
            for( int j  = t ; j >= c ; --j ){
               if( dp[ j ] < dp[ j - c ] + v[ i ] ){
                   dp[ j ] = dp[ j - c ] + v[ i ];
                   seen[ i ][ j ] = 1;
               }
            }
        }
        printf("%d\n" , dp[ t ] );
        int cnt = 0;
        for( int i = 0 , j = t ; i < n ; ++i ){
            if( seen[ i ][ j ] ){
                cnt++;
                j -= ( dep[ i ] * 3 * w );
            }
        }
        printf("%d\n" , cnt );
        for( int i = 0 , j = t ; i < n ; ++i ){
            if( seen[ i ][ j ] ){
                printf("%d %d\n" , dep[ i ] , v[ i ] );
                j -= ( dep[ i ] * 3 * w );
            }
        }
    }

    return 0;
}
