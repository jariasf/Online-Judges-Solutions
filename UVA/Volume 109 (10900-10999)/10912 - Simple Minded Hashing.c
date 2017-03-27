/*****************************************
 ***Problema: Simple Minded Hashing
 ***ID: 10912
 ***Juez: UVA
 ***Tipo: DP
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <string.h>

#define MAX 10004
int n, s, dp[ MAX ][ 29 ][ 29 ];

int solve( int sum , int k , int last ){
    if( sum > 351 || k > 26 || sum > s ) return 0;
    if( n == k  ){
        if( sum == s ) return 1;
        return 0;
    }
    if( dp[ sum ][ k ][ last ] != -1 ) return dp[ sum ][ k ][ last ];
    int ans = 0, i;
    for( i = last + 1 ; i <= 26 ; ++i ){
        ans += solve( sum + i , k + 1 , i  );
    }
    return dp[ sum ][ k ][ last ] = ans;
}

int main(){
    int q = 1 , i , j , k;
    while( scanf("%d %d" , &n , &s ) , n | s ){
        if( n > 26 || s > 351 ){
            printf("Case %d: 0\n" , q++ );
            continue;
        }
        for( i = 0 ; i < s + 5 ; ++i )
            for( j = 0 ; j < 27 ; ++j )
                for( k = 0 ; k < 27 ; ++k )
                    dp[ i ][ j ][ k ] = -1;
        printf("Case %d: %d\n" , q++ , solve( 0 , 0 , 0 ) );
    }
    return 0;
}
