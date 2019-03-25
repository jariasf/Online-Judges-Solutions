/*****************************************
 ***Problema: Etruscan Warriors Never Play Chess
 ***ID: 11614
 ***Juez: UVA
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <cmath>
int main(){
    int t;
    long long n;
    scanf("%d" , &t );
    while( t-- > 0 && scanf("%lld" , &n ) ){
        printf("%lld\n" , (long long)( sqrt( 1 + 4 * 2 * n ) - 1 )/2 );
    }
    return 0;
}
