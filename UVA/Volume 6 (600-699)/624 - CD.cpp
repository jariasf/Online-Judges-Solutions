/*****************************************
 ***Problema: CD
 ***ID: 624
 ***Juez: UVA
 ***Tipo: Backtracking
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <cstring>

#define MAX 32
int N , k, maxi;
int seen[ MAX ], resp[ MAX ], a[ MAX ];
void solve( int len , int u ){

    if( u > N )return;
    if( u > maxi ){
        maxi = u;
        for( int i = 0 ; i < MAX ; ++i ){
            resp[ i ] = seen[ i ];
        }
    }

    for( ; len < k ; ++len ){
        seen[ len ] = 1;
        solve( len + 1 , u + a[ len ] );
        seen[ len ] = 0;
    }
}

int main(){

    while( scanf("%d" , &N ) == 1 ){

        scanf("%d" , &k );

        for( int i = 0 ; i < k ; ++i ){
            scanf("%d" , &a[ i ] );
        }
        maxi = 0;
        memset( seen , 0 , sizeof( seen ) );
        solve( 0 , 0 );
        for( int i = 0 ; i < k ; ++i ){
            if( resp[ i ] == 1 ){
                printf("%d " , a[ i ] );
            }
        }
        printf("sum:%d\n" , maxi );
    }

    return 0;
}
