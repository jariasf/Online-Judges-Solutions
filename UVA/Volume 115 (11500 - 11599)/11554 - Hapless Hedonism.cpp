/*****************************************
 ***Problema: Hapless Hedonism
 ***ID: 11554
 ***Juez: UVA
 ***Tipo: Math
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
int main(){
    int t , n , i;
    scanf("%d" , &t );
    long long ans , p;
    while( t-- > 0 && scanf("%d" , &n ) ){
        ans = 0;
        for( i = 1 ; i <= n ; ++i ){
            p = n - ( i + i + 1 );
            if( p > 0 ) ans += ( p * ( p + 1 ) )/2;
        }
        printf("%lld\n" , ans );
    }

    return 0;
}
