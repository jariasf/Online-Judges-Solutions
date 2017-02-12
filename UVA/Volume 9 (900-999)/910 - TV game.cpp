/*****************************************
 ***Problema: TV game
 ***ID: 910
 ***Juez: UVA
 ***Tipo: DP
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <string.h>

#define MAX 27
int V , m, final[ MAX ];
int ady[ MAX ][ 2 ];
long long dp[ MAX ][ 35 ];
long long solve( int cur , int len ){
    if( len == m ){
        if( final[ cur ] ) return 1;
        return 0;
    }
    if( dp[ cur ][ len ] != -1  ) return dp[ cur ][ len ];
    return dp[ cur ][ len ] = solve( ady[ cur ][ 0 ] , len + 1 ) + solve( ady[ cur ][ 1 ] , len + 1 );
}

int main(){
    char u , v0 , v1 , x , i;
    while( scanf("%d" , &V ) != EOF ){
        memset( ady , 0 , sizeof( ady ) );
        for( i = 0 ; i < V && scanf(" %c %c %c %c" , &u , &v0 , &v1 , &x ) == 4 ; ++i ){
            ady[ u - 'A' ][ 0 ] = v0 - 'A';
            ady[ u - 'A' ][ 1 ] = v1 - 'A';
            ( x == 'x' )?final[ u - 'A' ] = 1:final[ u - 'A'] = 0;
        }
        scanf("%d" , &m );
        memset( dp , -1 , sizeof( dp ) );
        printf( "%lld\n" , solve( 0 , 0 ) );
    }
    return 0;
}
