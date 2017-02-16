/*****************************************
 ***Problema: Joseph's Cousin
 ***ID: UVA
 ***Juez: 10015
 ***Tipo: joseph problem, simulation
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <math.h>
#define MAX 32768

int primes[MAX];

void Sieve(){
    int idx=0;
    primes[idx++] = 2;
    for (int i = 3; i < MAX; i += 2) {
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

int survivor(int n){
   int i, s;
   for (s = 0, i = 1; i <= n; i++) {s = (s + primes[ n- i]) % i;  }
   return (s + 1);
}


int main(){
    Sieve();
    int n;
    while ( scanf("%d",&n) && n ){
        printf("%d\n",survivor(n));
    }

    return 0;
}
