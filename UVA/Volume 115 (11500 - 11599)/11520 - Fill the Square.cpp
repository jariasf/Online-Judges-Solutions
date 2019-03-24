/*****************************************
 ***Problema: Fill the Square
 ***ID: 11520
 ***Juez: UVA
 ***Tipo: Greedy
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <cstring>

#define MAX 15
char ady[ MAX ][ MAX ];
int dx[ 4 ] = { 1 , -1 , 0 ,  0 };
int dy[ 4 ] = { 0 ,  0 , 1 , -1 };
int n;
int seen[ 27 ];
void paint( int x , int y ){
    int nx , ny;
    memset( seen , 0 , sizeof( seen ) );
    for( int i = 0 ; i < 4 ; ++i ){
        nx = dx[ i ] + x; ny = dy[ i ] + y;
        if( nx >= 0 && ny >= 0 && nx < n && ny < n && ady[ nx ][ ny ] != '.' ){
            seen[ ady[ nx ][ ny ] - 'A' ] = 1;
        }
    }

    for( int i = 0 ; i < 26 ; ++i ){
        if( !seen[ i ] ){
            ady[ x ][ y ] = (char) ( i + 'A');
            break;
        }
    }
}

int main(){
    int t;
    scanf("%d" , &t );
    for( int q = 1 ; q <= t ; ++q ){
        scanf("%d" , &n );
        for( int i = 0 ; i < n ; ++i ) scanf("%s" , &ady[ i ] );
        for( int i = 0 ; i < n ; ++i )
            for( int j = 0 ; j < n; ++j )
                if( ady[ i ][ j ] == '.' )paint( i , j );

        printf("Case %d:\n" , q );
        for( int i = 0 ; i < n ; ++i ){
            printf("%s\n" , ady[ i ] );
        }
    }
    return 0;
}
