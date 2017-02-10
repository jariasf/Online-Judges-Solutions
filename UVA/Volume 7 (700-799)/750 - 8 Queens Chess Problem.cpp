/*****************************************
 ***Problema: 8 Queen Chess Problem
 ***ID: 750
 ***Juez: UVA
 ***Tipo: Backtracking
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/


#include <stdio.h>
#include <cstring>


int idx, num;
int row[ 10 ];
int rightDiag[ 20 ], leftDiag[ 20 ];
int resp[ 100 ][ 10 ] , tmp[ 8 ];

void generateSolution( int len ){

    if( len == 8 ){

        for( int i = 0 ; i < 8 ; ++i ){
             resp[ idx ][ i ] = tmp[ i ];
        }
        idx++;
        return;
    }

    for( int i = 0 ; i < 8 ; ++i ){ //fila

        if( row[ i ] && leftDiag[ len + i ] && rightDiag[ len - i + 8 ] ){
            row[ i ] = leftDiag[ len + i ] = rightDiag[ len - i + 8 ] = 0;
            tmp[ len ] = i + 1;
            generateSolution( len + 1 );
            row[ i ] = leftDiag[ len + i ] = rightDiag[ len - i + 8 ] = 1;
        }

    }

}

int main(){

    int t , x , y;
    scanf("%d" , &t );

    idx = 0;
    memset ( rightDiag , 1, sizeof (rightDiag));
    memset ( leftDiag , 1 , sizeof (leftDiag));
    memset( row , 1 , sizeof( row ) );
    generateSolution( 0 );


    for( int q = 0 ; q < t ; ++q ){
        if( q )putchar('\n');
        scanf("%d %d" , &x , &y );
        y--;
        printf("SOLN       COLUMN\n");
        printf(" #      1 2 3 4 5 6 7 8\n\n");
        num = 0;
        for( int i = 0 ; i < idx ; ++i ){
            if( resp[ i ][ y ] == x ){

                printf ("%2d      ", ++num);
                printf("%d" , resp[ i ][ 0 ] );
                for( int j = 1 ; j < 8 ; ++j ){
                     printf(" %d" , resp[ i ][ j ] );
                }
                printf("\n");
            }
        }
    }
    return 0;
}
