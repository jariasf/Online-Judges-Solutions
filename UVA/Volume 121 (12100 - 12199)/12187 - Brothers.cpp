/*****************************************
 ***Problema: Brothers
 ***ID: 12187
 ***Juez: UVA
 ***Tipo: Simulation
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>

#define MAX 102
int ady[ MAX ][ MAX ], aux[ MAX ][ MAX ] , f, c;
int dx[ ] = { 1 , 0 , 0 , -1 };
int dy[ ] = { 0 , 1 , -1 , 0 };

void copy( ){
    for( int i = 0 ; i < f ; ++i )
        for( int j = 0 ; j < c ; ++j )
            ady[ i ][ j ] = aux[ i ][ j ];
}

int main(){
    int n , b;
    while( scanf("%d %d %d %d" , &n , &f , &c , &b ) && n|f|c|b ){
        for( int i = 0 ; i < f ; ++i )
            for( int j = 0 ; j < c ; ++j ){
                scanf("%d" , &ady[ i ][ j ] );
                aux[ i ][ j ] = ady[ i ][ j ];
            }

        while( b-- ){
            for( int i = 0 ; i < f ; ++i ){
                for( int j = 0 ; j < c ; ++j ){
                    for( int k = 0 ; k < 4 ; ++k ){
                        int nx = dx[ k ] + i, ny = j + dy[ k ];
                        if( nx >= 0 && ny >= 0 && nx < f && ny < c && ( ady[ i ][ j ] + 1 )%n == ady[ nx ][ ny ] ){
                            aux[ nx ][ ny ] = ady[ i ][ j ];
                        }

                    }
                }
            }
            copy();
        }

        for( int i = 0 ; i < f ; ++i ){
            printf("%d" , ady[ i ][ 0 ] );
            for( int j = 1 ; j < c ; ++j )
                printf(" %d" , ady[ i ][ j ] );
            printf("\n");
        }
    }

    return 0;
}
