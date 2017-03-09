/*****************************************
 ***Problema: Travelling Salesman
 ***ID: 10702
 ***Juez: UVA
 ***Tipo: DP
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <string.h>

#define MAX 105
#define INF 1<<30

int max( int a , int b ){ return ( a < b )?b:a; }
int V , S , K, end[ MAX ] , ady[ MAX ][ MAX ] , dp[ MAX ][ 1005 ];
int solve( int cur , int k ){
    if( k > K ) return -INF;
    if( k == K && !end[ cur ] ) return -INF;
    if( end[ cur ] && k == K ) return 0;
    if( dp[ cur ][ k ] != -1 ) return dp[ cur ][ k ];
    int ans = 0 , i;
    for( i = 0 ; i < V ; ++i ){
        if( i == cur ) continue;
        ans = max( ans , ady[ cur ][ i ] + solve( i , k + 1 ) );
    }
    return dp[ cur ][ k ] = ans;
}

int main(){
    int T , i , j, x;
    while( scanf("%d %d %d %d" , &V , &S , &T , &K ) , V|S|T|K){

        for( i = 0 ; i < V ; ++i ){
            for( j = 0 ; j < V ; ++j ){
                scanf("%d" , &ady[ i ][ j ] );
            }
        }
        memset( end , 0 , sizeof( end ) );
        while( T-- ){
            scanf("%d" , &x );
            end[ x - 1 ] = 1;
        }
        memset( dp , -1 , sizeof( dp ) );
        printf("%d\n" , solve( S - 1 , 0 ) );
    }
    return 0;
}
