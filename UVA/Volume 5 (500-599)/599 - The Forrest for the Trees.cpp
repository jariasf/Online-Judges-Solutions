/*****************************************
 ***Problema: The Forrest for the Trees
 ***ID: 599
 ***Juez: UVA
 ***Tipo: Graph Theory, Union Find
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <cstring>

#define MAX 27
int uf[ MAX ];

int Find( int x ){
    return ( uf[ x ] == x ) ? x : uf[ x ] = Find( uf[ x ] );
}

void Union( int x , int y ){
    uf[ Find( x ) ] = Find( y );
}

int main(){
    int t , l, num_c, acorn;
    char s[ 55 ];
    bool seen[ 27 ];
    scanf("%d" , &t );
    gets( s );
    while( t-- ){
        memset( seen , 0 , sizeof( seen ) );
        acorn = 0;
        for( int i = 0 ; i < 26 ; ++i )uf[ i ] = i;
        while( gets( s ), s[ 0 ] != '*' ){
            Union( s[ 1 ] - 'A' , s[ 3 ] - 'A' );
            seen[ s[ 1 ] - 'A' ] = seen[ s[ 3 ] - 'A' ] = 1;
        }
        gets( s );
        l = strlen( s );
        num_c = 0;
        for( int i = 0 ; i < l ; ++i ){
            if( s[ i ] != ',' && !seen[ s[ i ] - 'A' ] ){
                acorn++;
            }
        }

        for( int i = 0 ; i < 26 ; ++i ){
            if( seen[ i ] && Find( i ) == i ){
                num_c++;
            }
        }
        printf("There are %d tree(s) and %d acorn(s).\n" , num_c , acorn );

    }

    return 0;
}
