/**********************************************
 ***Problema: Binomial Showdown
 ***ID: 530
 ***Juez: UVA
 ***Tipo: Number theory, gcd, binomial theorem.
 ***Autor: Jhosimar George Arias Figueroa
 **********************************************/

#include<iostream>
#include<stdio.h>
using namespace std;


int main() {
    int n, k;
    unsigned long long r;

    while(cin >> n >> k && ((n != 0) || (k != 0))) {
        r = 1;

        /* Si k es mas de la mitad usamos complemento */
        if(k > (n / 2)) {
            k = n - k;
        }

        /*
         * C(n,k) = n! / (k!(n-k)!) =
         * (n)(n-1)(...)(n-k+1) / 2*3*4*(...)*k
         */
        for (int i=0; i<k; i++) {
            r = r * (n - i);   /* (n)(n-1)(...)(n-k+1) */
            r = r / (1 + i);   /* 2*3*4*(...)*k */
        }
        cout << r << endl;
    }
}
