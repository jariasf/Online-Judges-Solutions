/*****************************************
 ***Problema: Sales
 ***ID: 1260
 ***Juez: UVA
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>

#define MAX  10005
int main(){
    int t , n , a[ MAX ], ans;
    scanf("%d" , &t );
    while( t-- ){
        scanf("%d" , &n );
        ans = 0;
        for( int i = 0 ; i < n ; ++i ) {
            scanf("%d" , &a[ i ] );
            for( int j = 0 ; j < i ; ++j ){
                if( a[ j ] <= a[ i ] ) ans++;
            }
        }
        printf("%d\n" , ans );
    }
    return 0;
}
