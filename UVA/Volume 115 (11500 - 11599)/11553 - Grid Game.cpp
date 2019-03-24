/*****************************************
 ***Problema: Grid Game
 ***ID: 11553
 ***Juez: UVA
 ***Tipo: Brute Force
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/
#include <stdio.h>
#include <cstring>
#include <iostream>
using namespace std;

#define MAX 9
int ady[ MAX ][ MAX ] , seen[ MAX ] , n;
int solve( int row ){
    if( row >= n ){
        return 0;
    }
    int r = 1<<30;
    for( int i = 0 ; i < n ; ++i ){
        if( !seen[ i ] ){
            seen[ i ] = 1;
            r = min( r , ady[ row ][ i ] + solve( row + 1 ) );
            seen[ i ] = 0;
        }
    }
    return r;
}

int main(){
    int t;
    scanf("%d" , &t );
    while( t-- ){
        scanf("%d" , &n );
        for( int i = 0 ; i < n ; ++i )
            for( int j = 0 ; j < n ; ++j ) scanf("%d" , &ady[ i ][ j ] );
        memset( seen , 0 , sizeof( seen ) );
        printf("%d\n" , solve( 0 )  );
    }
    return 0;
}
