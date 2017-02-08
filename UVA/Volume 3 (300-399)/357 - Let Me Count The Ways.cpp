/*****************************************
 ***Problema: Let Me Count The Ways
 ***ID: 357
 ***Juez: UVA
 ***Tipo: DP, Coin Change
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>

#define MAX 30005
long long dp[ MAX ];
int a[ 5 ] = { 1 , 5 , 10 , 25 , 50 };

void CoinChange(){
    dp[ 0 ] = 1;
    for( int i = 0 ; i < 5 ; ++i )
        for( int j = a[ i ] ; j < MAX ; ++j )
            dp[ j ] += dp[ j - a[ i ] ];
}

int main(){
    CoinChange();
    int n;
    while( scanf("%d" , &n ) != EOF ){
        if( dp[ n ] == 1 ) printf("There is only 1 way to produce %d cents change.\n" , n );
        else printf("There are %lld ways to produce %d cents change.\n" , dp[ n ] , n );
    }

    return 0;
}
