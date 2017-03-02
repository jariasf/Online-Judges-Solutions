/*****************************************
 ***Problema: Rock, Scissors, Paper
 ***ID: 10443
 ***Juez: UVA
 ***Tipo: Ad hoc, simulation
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <cstring>


#define MAX 105
int ady[ MAX ][ MAX ];
int next[ MAX ][ MAX ];

int dx[ 4 ] = { 1 , -1 , 0 ,  0 };
int dy[ 4 ] = { 0 ,  0 , 1 , -1 };
int main(){

    int t , h , w , it;
    scanf("%d" , &t );
    for( int q = 0 ; q < t ; ++q ){
        if( q )printf("\n");
        scanf("%d %d %d" , &h , &w , &it );
        for( int i = 0 ; i < h ; ++i )
            for( int j = 0 ; j < w ; ++j )
                 scanf(" %c" , &ady[ i ][ j ] );

        while( it-- ){
            memset( next , 0 , sizeof( next ) );
            for( int i = 0 ; i < h ; ++i ){
                for( int j = 0 ; j < w ; ++j ){
                    if( !next[ i ][ j ] )next[ i ][ j ] = ady[ i ][ j ];
                    for( int k = 0 ; k < 4 ; ++k ){
                        int nx = dx[ k ] + i , ny = dy[ k ] + j;
                        if( nx >= 0 && ny >= 0 && nx < h && ny < w ){
                            if( ady[ i ][ j ] == 'R' && ady[ nx ][ ny ] == 'S' )next[ nx ][ ny ] = 'R';
                            if( ady[ i ][ j ] == 'S' && ady[ nx ][ ny ] == 'P' )next[ nx ][ ny ] = 'S';
                            if( ady[ i ][ j ] == 'P' && ady[ nx ][ ny ] == 'R' )next[ nx ][ ny ] = 'P';
                        }

                    }
                }
            }
            memcpy( ady , next , sizeof( next ) );
        }
        for( int i = 0 ; i < h ; ++i ){
            for( int j = 0 ; j < w ; ++j ){
                printf("%c" , ady[ i ][ j ] );
            }
            printf("\n");
        }
    }

    return 0;
}
