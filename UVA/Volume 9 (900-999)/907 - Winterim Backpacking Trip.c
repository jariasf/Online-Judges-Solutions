/*****************************************
 ***Problema: Winterim Backpacking Trip
 ***ID: 907
 ***Juez: UVA
 ***Tipo: Binary Search | DP
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <string.h>

#define MAX 610
int d[ MAX ] , n , k;

int possible( int val ){
    int i, sum = 0 , days = 0;
    for( i = 0 ; i <= n ; ++i ){
        if( d[ i ] > val ) return 0;
        if( sum + d[ i ] > val ){
            sum = 0;
            days++;
        }
        sum += d[ i ];
    }
    return days <= k;

}

int main(){
    int left , right , mid , ans, aux , i;
    while( scanf("%d %d" , &n , &k ) == 2 ){
        for( i = 0 ; i <= n && scanf("%d" , &d[ i ] ) == 1 ; ++i );
        left = 0;
        right = 1<<30;
        while( left < right ){
            mid = ( left + right )>>1;
            if( possible( mid ) ){
                right = mid;
            }
            else left = mid + 1;
        }
        printf("%d\n" , right );

    }

    return 0;
}
