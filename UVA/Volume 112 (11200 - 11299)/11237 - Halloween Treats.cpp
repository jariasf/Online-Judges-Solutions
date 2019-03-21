/*****************************************
 ***Problema: Halloween treats
 ***ID: 11237
 ***Juez: UVA
 ***Tipo: PigeonHole Teorem
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <cstring>

#define MAX 100005
int a[ MAX ] , idx[ MAX ];
int main(){
    int c , n , i , sum , j;
    bool first;
    while( scanf("%d %d" , &c , &n ) , c | n ){
        memset( idx , -1 , sizeof( idx ) );
        for( i = 0 ; i < n && scanf("%d" , &a[ i ] ) ; ++i );
        sum = 0;
        first = false;
        for( i = 0 ; i < n ; ++i ){
            sum = ( sum % c + a[ i ] % c ) % c;
            if( sum == 0 ){
                for( j = 0 ;j <= i ; ++j ){
                    if( first ) printf(" ");
                    printf("%d" ,  j + 1 );
                    first = true;
                }
                printf("\n");
                break;
            }
            if( idx[ sum ] >= 0 ){
                for( j = idx[ sum ] + 1; j <= i ; ++j ){
                    if( first ) printf(" ");
                    printf("%d" , j + 1 );
                    first = true;
                }
                printf("\n");
                break;
            }
            idx[ sum ] = i;
        }
    }
    return 0;
}
