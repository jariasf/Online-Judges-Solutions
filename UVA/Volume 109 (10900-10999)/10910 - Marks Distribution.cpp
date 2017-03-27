/*****************************************
 ***Problema: Marks Distribution
 ***ID: 10910
 ***Juez: UVA
 ***Tipo: DP
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <cstring>
#define MAX 75

int n , p, dp[ MAX ][ MAX ] , t;

int solve( int sum , int k ){
    if( sum < 0 ) return 0;
    if( k == n ){
        if( sum == 0 ) return 1;
        return 0;
    }
    if( dp[ sum ][ k ] != -1 ) return dp[ sum ][ k ];
    int ans = 0;
    for( int i = p ; i <= t ; ++i ){
        ans += solve( sum - i , k + 1 );
    }
    return dp[ sum ][ k ] = ans;
}

int main(){
    int k;
    scanf("%d" , &k );
    while( k-- ){
        scanf("%d %d %d" , &n , &t , &p );
        memset( dp , -1 , sizeof( dp ) );
        printf("%d\n" , solve( t , 0 ) );
    }
    return 0;
}
