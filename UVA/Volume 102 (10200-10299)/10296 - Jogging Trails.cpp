/*****************************************
 ***Problema: Jogging Trails
 ***ID: 10296
 ***Juez: UVA
 ***Tipo: DP Bitmask , Shortest Path , Euler Cycle
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <cstring>
#define MAX 16
#define INF 1<<30
int min( int a , int b ){ return ( a < b )?a : b ;}
int degree[ MAX ] , V , dist[ MAX ] , prev[ MAX ] , seen[ MAX ];
int ady[ MAX ][ MAX ];

void init(){
    int i ,j;
    for( i = 0 ; i < V ; ++i )
        for( j = 0 ; j < V ; ++j )
         ady[ i ][ j ] = ( i == j )?0:INF;
}
void floyd(){
    int i , j , k;

    for( k = 0 ; k < V ; ++k ){
        for( i = 0 ; i < V ; ++i ){
            if( ady[ i ][ k ] == INF ) continue;
            for( j = 0 ; j < V ; ++j ){
                if( ady[ k ][ j ] != INF && ady[ i ][ j ] > ady[ i ][ k ] + ady[ k ][ j ] ){
                    ady[ i ][ j ] = ady[ i ][ k ] + ady[ k ][ j ];
                }
            }
        }
    }
}

int impar[ MAX ] , len;

int bitcount( int n ){
    int cnt = 0;
    while( n ){
        n = n & ( n - 1 );
        cnt++;
    }
    return cnt;
}
int dp[ 1<<16 ];
int solve( int mask ){
    if( bitcount( mask ) == len ) return 0;
    if( dp[ mask ] != -1 ) return dp[ mask ];
    int mini = INF , i , j;
    for( i = 0 ; i < len ; ++i ){
        if(  mask & 1<<i ) continue;
        for( j = i + 1 ; j < len ; ++j ){
            if( mask & 1<<j ) continue;
            mini = min( mini , ady[ impar[ i ] ][ impar[ j ] ] + solve( mask | 1<<i | 1<<j ) );
        }
    }
    return dp[ mask ] = mini;
}

int main(){
    int t , q , ans , E , i , j , u , v , w , DP;
    while( scanf("%d" , &V ) , V ){
        scanf("%d" , &E );
        memset( degree , 0 , sizeof( degree ) );
        init();
        ans = 0;
        while( E-- > 0 && scanf("%d %d %d" , &u , &v , &w ) ){
            ady[ u - 1 ][ v - 1 ] = ady[ v - 1 ][ u - 1 ] = min( ady[ u - 1 ][ v - 1 ] , w );
            ans += w;
            degree[ u - 1 ]++;
            degree[ v - 1 ]++;
        }
        //Floyd para rutas mas cortas
        floyd();
        len = 0;
        DP = 0;
        memset( dp , -1 , sizeof( dp ) );
        for( i = 0 ; i < V ; ++i ){
            if( degree[ i ] & 1 ){
                //Solo es necesario impares para crear nodos falsos
                impar[ len++ ] = i;
            }
        }
        //Si todos son de ciclo par esa es la respuesta
        //Sino hallo la minima combinacion de crear aristas falsas
        if( len > 0 ) DP = solve( 0 );
        printf("%d\n" , ans + DP );
    }
    return 0;
}
