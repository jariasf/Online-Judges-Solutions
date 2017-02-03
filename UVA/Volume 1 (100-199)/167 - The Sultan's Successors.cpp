/*****************************************
 ***Problema: The Sultan's Successors
 ***ID: 167
 ***Juez: UVA
 ***Tipo: Backtracking
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <cstring>

#define MAX 9
int col[ MAX ] , leftDiag[ 20 ] , rightDiag[ 20 ], tmp[ MAX ], a[ MAX ][ MAX ];
int resp[ 100 ][ MAX ] , len = 0;
void gen( int row ){
    if( row == 8 ){
        for( int i = 0 ; i < 8 ; ++i ) resp[ len ][ i ] = tmp[ i ];
        len++;
        return;
    }
    for( int i = 0 ; i < 8 ; ++i ){
        if( col[ i ] && leftDiag[ i + row ] && rightDiag[ i - row + 8 ] ){
            col[ i ] = leftDiag[ i + row ] = rightDiag[ i - row + 8 ] = 0;
            tmp[ row ] = i;
            gen( row + 1 );
            col[ i ] = leftDiag[ i + row ] = rightDiag[ i - row + 8 ] = 1;
        }
    }
}

int main(){
    len = 0;
    memset( col , 1 ,  sizeof( col ) );
    memset( leftDiag , 1 , sizeof( leftDiag ) );
    memset( rightDiag , 1 , sizeof( rightDiag ) );
    gen( 0 );
    int t, maxi, sum;
    scanf("%d" , &t );
    while( t-- ){
        for( int i = 0 ; i < 8 ; ++i )
            for( int j = 0 ; j < 8 ; ++j ) scanf("%d" , &a[ i ][ j ] );
        maxi = 0;
        for( int i = 0 ; i < len ; ++i ){
            sum = 0;
            for( int j = 0 ; j < 8 ; ++j ){
                sum += a[ j ][ resp[ i ][ j ] ];
            }
            if( sum > maxi ) maxi = sum;
        }
        printf("%5d\n" , maxi );
    }
    return 0;
}
