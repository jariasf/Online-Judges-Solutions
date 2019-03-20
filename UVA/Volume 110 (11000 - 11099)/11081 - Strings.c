/*****************************************
 ***Problema: Strings
 ***ID: 11081
 ***Juez: UVA
 ***Tipo: DP - Memoization
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <string.h>

#define MAX 65
#define MOD 10007

char a[ MAX ] , b[ MAX ] , c[ MAX ];
long long dp[ MAX ][ MAX ][ MAX ];
int la , lb , lc;

long long solve( int lenA , int lenB , int lenC  ){
    if( lenC == lc ) return dp[ lenA ][ lenB ][ lenC ] = 1;
    if( dp[ lenA ][ lenB ][ lenC ] != -1 ) return dp[ lenA ][ lenB ][ lenC ];
    int i;
    dp[ lenA ][ lenB ][ lenC ] = 0;
    for( i = lenA ; i < la ; ++i ){
        if( la - i + lb - lenB < lc - lenC  ) break;
        if( a[ i ] == c[ lenC ] ){
            dp[ lenA ][ lenB ][ lenC ] += solve( i + 1 , lenB , lenC + 1 );
            dp[ lenA ][ lenB ][ lenC ] %= MOD;
        }
    }

    for( i = lenB ; i < lb ; ++i ){
        if( la - lenA + lb - i < lc - lenC  ) break;
        if( b[ i ] == c[ lenC ] ){
            dp[ lenA ][ lenB ][ lenC ] +=  solve( lenA , i + 1 , lenC + 1 );
            dp[ lenA ][ lenB ][ lenC ] %= MOD;
        }
    }
    return dp[ lenA ][ lenB ][ lenC ];
}

int main(){
    int t , ans;
    scanf("%d" , &t );
    while( t-- > 0 && scanf("%s %s %s" , &a , &b , &c ) ){
        la = strlen( a ); lb = strlen( b ) ; lc = strlen( c );
        memset( dp , -1 , sizeof( dp ) );
        printf("%lld\n" , solve( 0 , 0 , 0  ) % MOD );
    }
    return 0;
}
