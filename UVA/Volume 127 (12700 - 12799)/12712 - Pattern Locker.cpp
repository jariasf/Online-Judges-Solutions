/*****************************************
 ***Problema: Pattern Locker
 ***ID: 12712
 ***Juez: UVA
 ***Tipo: Math
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>

#define MAX 10005
#define MOD 10000000000007
long long prod[ MAX ];

int main(){
    int t , L , M , N;
    scanf("%d" , &t );

    for( int q = 1 ; q <= t && scanf("%d %d %d" , &L , &M , &N ) ; ++q ){
        long long ans = 0;
        L *= L;
        prod[ L ] = L;
        for( int i = L - 1 ; i >= 1 ; --i ){
            prod[ i ] = (prod[ i + 1 ] % MOD * i % MOD) % MOD;
        }

        for( int i = M ; i <= N ; ++i ){
            ans += prod[ L - i + 1 ] % MOD;
        }
        printf("Case %d: %lld\n" , q , ans % MOD );
    }
    return 0;
}

