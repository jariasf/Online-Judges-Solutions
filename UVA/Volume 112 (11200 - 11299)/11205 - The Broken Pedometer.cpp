/*****************************************
 ***Problema: The Broken Pedometer
 ***ID: 11205
 ***Juez: UVA
 ***Tipo: Brute Force
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <cstring>
#define MAX 105
int aux[ MAX ];
bool seen[ 100005 ];
int bit[ MAX ];
int main(){
    int t, mini , p , n , x, sum;
    scanf("%d" , &t );
    while( t-- ){
        memset( bit , 0 , sizeof( bit ) );
        scanf("%d%d" , &p , &n );
        for( int i = 0 ; i < n ; ++i ){
            for( int j = 0 ; j < p ; ++j ) {
                scanf("%d" , &x );
                if( x ){
                    bit[ i ] |= 1<<( p - j - 1 );
                }
            }
        }
        mini = p;
        for( int i = 0 ; i < (1<<p) ; ++i ){
            memcpy( aux , bit , sizeof( bit ) );
            memset( seen , 0 , sizeof( seen ) );
            sum = 0;
            for( int j = 0 ; j < p ; ++j ) if( ( i & ( 1<<j ) ) ) sum++;
            int j = 0;
            for( ; j < n ; ++j ) { aux[ j ] &= i; if( seen[ aux[ j ] ] )break; else seen[ aux[ j ] ] = 1;}
            if( j == n && mini > sum ) mini = sum;
        }
        printf("%d\n" , mini );
    }
    return 0;
}
