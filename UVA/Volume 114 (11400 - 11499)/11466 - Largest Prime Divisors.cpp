/*****************************************
 ***Problema: Largest Prime Divisors
 ***ID: 11466
 ***Juez: UVA
 ***Tipo: Number theory
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include<iostream>
#include<stdio.h>

using namespace std;

int main(){
    long long maxi,ini,n;
    bool b;
    while( scanf("%lld" , &n ) && n){
        if( n < 0 ) n *= -1;
        b = false;
        maxi = 1LL;

        for( long long i = 2 ; i * i <=n ; i++ ){
           while( n % i == 0LL ){
               if( !b ) ini = i;
               n /= i;
               maxi = max( maxi , i);
               b = true;
           }
        }

        if( n > 1LL ) maxi = max( maxi , n);
        if( maxi == ini || !b ) printf("-1\n");
        else printf("%lld\n",maxi);
    }

    return 0;
}
