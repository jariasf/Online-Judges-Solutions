/*****************************************
 ***Problema: Diagonal
 ***ID: 10784
 ***Juez: UVA
 ***Tipo: Ad hoc, math
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

///numero de diagonales es n(n-3)/2
///n*(n-3)/2 >= N
///n^2 - 3*n - 2*N >= 0 usamos formula general
#include <stdio.h>
#include <cmath>

int main(){
    long long N, n, a = 1 , b = -3 , c;
    int t = 1;
    while( scanf("%lld", &N ) ){
        if( N == 0LL )break;
        c = -2*N;
        n = (long long) ceil((-b + sqrt(b*b - 4*a*c)) / 2*a);
        printf("Case %d: %lld\n", t++ , n );
    }

    return 0;
}
