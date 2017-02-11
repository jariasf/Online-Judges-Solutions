/*****************************************
 ***Problema: Walking on the Safe Side
 ***ID: 825
 ***Juez: UVA
 ***Tipo: DAG Longest Path DP
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 105
int h , w;
int ady[ MAX ][ MAX ];
int dp[ MAX ][ MAX ];
int dx[] = { 0 , 1 };
int dy[] = { 1 , 0 };
void solve(){
    int i , j , ans ,ny , nx , k;
    memset( dp , 0 , sizeof( dp ) );
    dp[ 0 ][ 0 ] = 1;
    for( i = 0 ; i < h ; ++i ){
        for( j = 0 ; j < w ; ++j ){
            if( ady[ i ][ j ] ) continue;
            for( k = 0 ; k < 2 ; ++k ){
                nx = dx[ k ] + i; ny = dy[ k ] + j;
                if( nx >= 0 && ny >= 0 && nx < h && ny < w && !ady[ nx ][ ny ]  ){
                    dp[ nx ][ ny ] += dp[ i ][ j ];
                }
            }
        }
    }
    printf("%d\n" , dp[ h - 1 ][ w - 1 ] );
}

char s[ MAX ];
int main(){
    int t , y ,i , q , b;
    scanf("%d" , &t );
    for( q = 0 ; q < t ; ++q ){
        if( q ) printf("\n");
        scanf("%d %d" , &h , &w );
        getchar();
        memset( ady , 0 , sizeof( ady ) );
        for( i = 0 ; i < h && gets( s ) ; ++i ){
            b = 1;
            char *p = strtok( s , " " );
            while( p != NULL ){
                if( !b )ady[ i ][ atoi( p ) - 1 ] = 1;
                p = strtok( NULL , " ");
                b = 0;
            }
        }
        solve();
    }
    return 0;
}
