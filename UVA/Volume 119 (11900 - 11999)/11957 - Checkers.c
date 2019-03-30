/*****************************************
 ***Problema: Checkers
 ***ID: 11957
 ***Juez: UVA
 ***Tipo: DP Counting Paths
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <string.h>

#define MAX 105
#define MOD 1000007
int n , xini , yini;
char ady[ MAX ][ MAX ];
int dp[ MAX ][ MAX ] , degree[ MAX ][ MAX ];
int dx[ 2 ] = { -1 , -1 };
int dy[ 2 ] = { -1 ,  1 };
void solve(){
    int nx , ny , i;
    int x , y;
    memset( dp , 0 , sizeof( dp ) );
    dp[ xini ][ yini ] = 1;
    for( x = xini ; x >= 0 ; --x ){
        for( y = 0 ; y < n ; ++y ){
            for( i = 0 ; i < 2 ; ++i ){
                nx = dx[ i ] + x;
                ny = dy[ i ] + y;
                if( nx >= 0 && ny >= 0 && nx < n && ny < n ){
                    if( ady[ nx ][ ny ] == '.' ){
                        dp[ nx ][ ny ] = ( dp[ nx ][ ny ] % MOD + dp[ x ][ y ] % MOD ) % MOD;
                    }else{
                        nx = dx[ i ] + nx;
                        ny = dy[ i ] + ny;
                        if( nx >= 0 && ny >= 0 && nx < n && ny < n && ady[ nx ][ ny ] == '.'){
                            dp[ nx ][ ny ] = ( dp[ nx ][ ny ] % MOD + dp[ x ][ y ] % MOD ) % MOD;
                        }
                    }
                }
            }
        }
    }
    int ans = 0;
    for( i = 0 ; i < n ; ++i )
        ans = ( ans % MOD + dp[ 0 ][ i ] % MOD ) % MOD;
    printf("%d\n" , ans );
}

int main(){
    int t , q , i , j;
    scanf("%d" , &t );
    for( q = 1 ; q <= t && scanf("%d" , &n ) == 1 ; ++q ){
        for( i = 0 ; i < n ; ++i ){
            for( j = 0 ; j < n && scanf(" %c" , &ady[ i ][ j ] ) == 1 ; ++j ){
                if( ady[ i ][ j ] == 'W' ) xini = i , yini = j;
            }
        }
        printf("Case %d: " , q );
        solve();
    }
    return 0;
}
