/*****************************************
 ***Problema: Ingenuous Cubrency
 ***ID: 11137
 ***Juez: UVA
 ***Tipo: DP, Coin Change
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>

#define MAX 10004
long long dp[ MAX ];
void CoinChange(){
    int val;
    dp[ 0 ] = 1;
    for( int i = 1 ; i <= 21 ; ++i ){
        val = i * i * i;
        for( int j = val ; j <= 10000 ; ++j )
            dp[ j ] += dp[ j - val ];
    }
}

int main(){
    CoinChange();
    int n;
    while( scanf("%d" , &n ) != EOF ){
        printf("%lld\n" , dp[ n ] );
    }

    return 0;
}
