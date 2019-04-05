/*****************************************
 ***Problema: Perfect Choir
 ***ID: 12485
 ***Juez: UVA
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#define MAX 10005
int a[ MAX ];
int main(){
    int n , i;
    long long sum , positive , negative;
    while( scanf("%d" , &n ) != EOF ){
        sum = 0;
        for( i = 0 ; i < n && scanf("%d" , &a[ i ] ) == 1 ; ++i ) sum += a[ i ];

        sum /= n;
        positive = negative = 0;
        for( i = 0 ; i < n ; ++i ){
            if( a[ i ] < sum ) positive += sum - a[ i ];
            else negative += ( a[ i ] - sum );
        }
        if( positive == negative ) printf("%lld\n" , positive + 1 );
        else puts("-1");
    }
    return 0;
}
