/*****************************************
 ***Problema: Less Prime
 ***ID: 10852
 ***Juez: UVA
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <math.h>
#define MAX 10005

int primes[MAX];
int idx;
void Sieve(){
    idx=0;
    primes[idx++] = 2;
    for (int i = 3; i <= MAX; i+=2) {
         bool isprime = true;
         int cap = (int)sqrt(i)+1;
         for (int j = 0; j < idx; j++) {
             if (primes[j] >= cap) break;
             if (i % primes[j] == 0) {
                 isprime = false;
                 break;
             }
         }
         if (isprime) primes[idx++] = i;
    }
}

int main(){
    int t , n, p, i;
    scanf("%d", &t );
    Sieve();
    while( t-- ){
        scanf("%d", &n);
        for( i = 0; i < idx ; ++i ){
            if( 2* primes[ i ] > n) break;
        }
        printf("%d\n", primes[ i ]);
    }

    return 0;
}
