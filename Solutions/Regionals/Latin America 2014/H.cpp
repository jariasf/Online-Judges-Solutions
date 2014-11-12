/*****************************************
 ***Problema: Help cupid
 ***Tipo: Greedy
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <algorithm>
#include <cmath>
#define MAX 1005
int a[ MAX ];

int getMin( int val1 , int val2  ){
    int dif1 = abs( val1 - val2 );
    int dif2 = 24 - dif1;
    return std::min( dif1 , dif2 );
}

int main(){
    int ans, dif1 , dif2 , dif , n;
    while( scanf("%d" , &n ) != EOF ){
        for( int i = 0 ; i < n && scanf("%d" , &a[i] ) ; ++i );
        std::sort( a , a + n );

        int s1 = 0 , s2 = 0;
        for( int i = 0 ; i + 1 < n ; i += 2 ){
            s1 += getMin( a[i] , a[i+1] );
        }

        for( int i = 1 ; i + 1 < n ; i += 2 ){
            s2 += getMin( a[i] , a[i+1] );
        }

        s2 += getMin( a[0] , a[ n - 1 ] );

        printf("%d\n" , std::min( s1 , s2 ) );
    }
    return 0;
}
