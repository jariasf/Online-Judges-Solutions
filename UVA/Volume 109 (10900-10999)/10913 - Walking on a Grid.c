/*****************************************
 ***Problema: Walking on a Grid
 ***ID: 10913
 ***Juez: UVA
 ***Tipo: DP
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <string.h>

#define MAX 76
#define INF 1LL<<50
int n , k, ady[ MAX ][ MAX ];
long long max( long long a , long long b ){ return ( a < b )? b : a;}
long long dp[ MAX ][ MAX ][ 5 ][ 6 ];
int dx[ 3 ] = { 0 , 0 , 1};
int dy[ 3 ] = { -1 , 1 , 0};

long long solve( int x , int y , int K , int ant , int px , int py ){
    if( K > k ) return -INF;
    if( x == n - 1 && y == n - 1 ){
        if( K <= k )return 0;
        return -INF;
    }

   if( dp[ x ][ y ][ ant ][ K ] != -1LL<<60 ) return dp[ x ][ y ][ ant ][ K ];
    long long ans = -INF , aux;
    int i , nx , ny;
    for( i = 0 ; i < 3 ; ++i ){
        nx = dx[ i ] + x;
        ny = dy[ i ] + y;
        if( nx >= 0 && ny >= 0 && nx < n && ny < n && ( nx != px || ny != py ) ){
            aux = solve( nx , ny , K +( ( ady[ nx ][ ny ] < 0 )?1:0 ) , i , x , y );
            if( aux != -INF )
                ans = max( ans , ady[ nx ][ ny ] + aux );
        }
    }
    return dp[ x ][ y ][ ant ][ K ] = ans;
}

int main(){
    int i , j , q = 1 , kk , jj;
    long long ans;
    while( scanf("%d %d" , &n , &k ) , n | k ){

        for( i = 0 ; i < n ; ++i )
            for( j = 0 ; j < n && scanf("%d" , &ady[ i ][ j ] ) == 1 ; ++j );

        for( i = 0 ; i < n ; ++i ){
            for( j = 0 ; j < n ; ++j ){
                for( kk = 0 ; kk <= k ; ++kk ){
                    dp[ i ][ j ][ 0 ][ kk ] = -1LL<<60;
                    dp[ i ][ j ][ 1 ][ kk ] = -1LL<<60;
                    dp[ i ][ j ][ 2 ][ kk ] = -1LL<<60;
                }
            }
        }

        ans = solve( 0 , 0 , ( ady[ 0 ][ 0 ] < 0 )?1:0 , 0 , 0 , 0 );
        printf("Case %d: " , q++ );
        if( ans == -INF ) puts("impossible");
        else printf("%lld\n" , ans + ady[ 0 ][ 0 ] );
    }
    return 0;
}
