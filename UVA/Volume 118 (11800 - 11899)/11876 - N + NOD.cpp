/*****************************************
 ***Problema: N + NOD(N)
 ***ID: 11876
 ***Juez: UVA
 ***Tipo: Binary Search, Complete Search
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <algorithm>
using namespace std;
#define MAX 1000005
int len;
long long dp[ MAX ];
void gen(){
    int aux, cnt;
    long long p;
    dp[ 0 ] = 1LL;
    for( len = 1 ; ; ++len ){
        aux = dp[ len - 1 ];
        p = 1;
        for( int j = 2 ; j * j <= aux; ++j ){
            if( aux % j == 0 ){
                cnt = 0;
                while( aux % j == 0 ){
                    cnt++;
                    aux /= j;
                }
                p *= ( cnt + 1 );
            }
        }
        if( aux > 1 ) p *= 2;
        dp[ len ] = dp[ len - 1 ] + p;
        if( dp[ len ] > 1000000 )break;
    }
}

int main(){
    gen();
    int t , l ,u;
    scanf("%d" , &t );
    for( int q = 1 ; q <= t ; ++q ){
        scanf("%d %d" , &l , &u );
        u = upper_bound( dp , dp + len , u ) - dp;
        l = lower_bound( dp , dp + len , l ) - dp;
        printf("Case %d: %d\n" , q , u - l  );
    }

    return 0;
}
