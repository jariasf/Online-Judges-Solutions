/*****************************************
 ***Problema: Longest Run on a Snowboard
 ***ID: 10285
 ***Juez: UVA
 ***Tipo: Backtracking, DP
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <cstring>

#define MAX 105

int max( int a , int b ){ return ( a > b )? a : b; }

int r , c , ady[ MAX ][ MAX ] , maxi , dx[ 4 ] = { 0 , 0 , 1 , -1 } , dy[ 4 ] = { 1 , -1 , 0 , 0 } , dist;
bool seen[ MAX ][ MAX ];
int dp[ MAX ][ MAX ];
void dfs( int x , int y ){
    dist++;
    maxi = max( maxi , dist );
    seen[ x ][ y ] = 1;
    for( int i = 0 ; i < 4 ; ++i ){
        int nx = x + dx[ i ], ny = y + dy[ i ];
        if( nx >= 0 && ny >= 0 && nx < r && ny < c && seen[ nx ][ ny ] == 0 && ady[ nx ][ ny ] < ady[ x ][ y ] ){
            dfs( nx , ny );
            dist--;
            seen[ nx ][ ny ] = 0;
        }
    }
}

int main(){
    int t;
    char s[ 205 ];
    scanf("%d" , &t );
    while( t-- ){

        scanf("%s %d %d" , &s , &r , &c );

        for( int i = 0 ; i < r ; ++i ){
             for( int j = 0 ; j < c ; ++j ){
                 scanf("%d" , &ady[ i ][ j ] );
             }
        }
        maxi = 0;
        dist = 0;

        for( int i = 0 ; i < r ; ++i ){
             for( int j = 0 ; j < c ; ++j ){
                 memset( seen , 0 , sizeof( seen ) );
                 dist = 0;
                 dfs( i , j );
             }
        }

        printf("%s: %d\n" , s , maxi );
    }

    return 0;
}
