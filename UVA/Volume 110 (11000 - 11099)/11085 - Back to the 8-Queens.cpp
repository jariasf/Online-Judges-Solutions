/*****************************************
 ***Problema: Back to the 8-Queens
 ***ID: 11085
 ***Juez: UVA
 ***Tipo: Backtracking
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <cstring>

#define MAX 25
int row[ MAX ], leftDiag[ MAX ] , rightDiag[ MAX ], resp[ 100 ][ 10 ] , ans[ MAX ] , len;
void gen( int col ){

    if( col == 8 ){
        for( int i = 0 ; i < 8 ; ++i ) resp[ len ][ i ] = ans[ i ];
        len++;
        return;
    }
    for( int i = 0 ; i < 8 ; ++i ){
        if( row[ i ] && leftDiag[ i + col ] && rightDiag[ col - i + 8 ] ){
            row[ i ] = leftDiag[ i + col ] = rightDiag[ col - i + 8 ] = 0;
            ans[ col ] = i + 1;
            gen( col + 1 );
            row[ i ] = leftDiag[ i + col ] = rightDiag[ col - i + 8 ] = 1;
        }
    }
}

int main(){
    len = 0;
    memset( row , 1 , sizeof( row ) );
    memset( leftDiag , 1 , sizeof( leftDiag ) );
    memset( rightDiag , 1 , sizeof( rightDiag ) );
    gen( 0 );
    int a[ 9 ], sum , mini , q = 1;
    while( scanf("%d%d%d%d%d%d%d%d" , &a[0] ,&a[1] , &a[2] , &a[3] , &a[4],&a[5],&a[6],&a[7] ) != EOF ){
        mini = 1<<30;
        for( int i = 0 ; i < len ; ++i ){
            sum = 0;
            for( int j = 0 ; j < 8 ; ++j )
                sum += ( a[ j ] == resp[ i ][ j ] )?0:1;
            if( sum < mini ) mini = sum;
        }
        printf("Case %d: %d\n" , q++ , mini );
    }

    return 0;
}
