/*****************************************
 ***Problema: A graph Problem
 ***ID: 11069
 ***Juez: UVA
 ***Tipo: Simple DP, recurrences
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>

#define MAX 80
long long dp[ MAX ];
void Solve(){
    dp[ 1 ] = 1;
    dp[ 2 ] = 2;
    dp[ 3 ] = 2;
    dp[ 4 ] = 3;
    dp[ 5 ] = 4;
    for( int i = 6 ; i < MAX ; ++i ){
        dp[ i ] = dp[ i - 1 ] + dp [ i - 5 ];
    }
}

int main(){
    Solve();
    int n;
    while( scanf("%d", &n) != EOF ){
        printf("%lld\n", dp[ n ]);
    }

    return 0;
}
