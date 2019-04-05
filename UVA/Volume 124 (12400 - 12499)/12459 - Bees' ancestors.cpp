/*****************************************
 ***Problema: Bees' ancestors
 ***ID: 12459
 ***Juez: UVA
 ***Tipo: Fibonacci Numbers
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/
#include <stdio.h>

#define MAX 81

long long fib(int n ){
    int i = n - 1;
    long long a = 1, b = 0, c = 0, d = 1, t;
    if ( n <= 0 ) return 0;
    while ( i > 0 ){
        if ( i % 2 == 1 ){
            t = d * ( b + a ) + c * b;
            a = d * b + c * a;
            b = t;
        }
        t = d * ( 2 * c + d );
        c = c * c + d * d;
        d = t;
        i = i / 2;
   }
   return a + b;
}

int main(){
    int n;
    while( scanf("%d" , &n ) && n ){
        printf("%lld\n" , fib( n + 1 ) );
    }
    return 0;
}
