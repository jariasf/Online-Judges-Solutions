/*****************************************
 ***Problema: Traditional BINGO
 ***ID: 10813
 ***Juez: UVA
 ***Tipo: Ad hoc, Simulation
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>


int card[ 5 ][ 5 ];
int bingo[ 75 ];

bool Bingo(){
    int r , c , di = 0, dd = 0;
    for( int i = 0 ; i < 5 ; ++i ){
        r = c = 0;
        for( int j = 0 ; j < 5 ; ++j ){
            r += card[ i ][ j ];
            c += card[ j ][ i ];
        }
        if( !r || !c )return true;
        di += card[ i ][ i ];
        dd += card[ 4 - i  ][ i ];
    }
    if( !di || !dd )return true;
    return false;
}

int main(){

    int t;
    scanf("%d" , &t );
    while( t-- ){
        for( int i = 0 ; i < 5 ; ++i ){
            for( int j = 0 ; j < 5 ; ++j ){
                if( i == 2 && j == 2 ){
                    card[ i ][ j ] = 0; continue;
                }
                scanf("%d" , &card[ i ][ j ] );
            }
        }

        for( int i = 0 ; i < 75 ; ++i ) scanf("%d" , &bingo[ i ] );
        int i = 0;
        for(  ; i < 75 ; ++i ){

            for( int j = 0 ; j < 5 ; ++j ){
                for( int k = 0 ; k < 5 ; ++k ){
                    if( card[ j ][ k ] == bingo[ i ] ) card[ j ][ k ] = 0;
                }
            }

            if( Bingo() )break;

        }
        printf("BINGO after %d numbers announced\n" , i + 1 );
    }

    return 0;
}
