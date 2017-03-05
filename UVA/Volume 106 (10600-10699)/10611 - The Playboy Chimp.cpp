/*****************************************
 ***Problema: The Playboy Chimp
 ***ID: 10611
 ***Juez: UVA
 ***Tipo: Binary Search
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <algorithm>
using namespace std;
#define MAX 50005
int a[ MAX ];
int main(){
    int n , q , h , l , u;
    scanf("%d" , &n );
    for( int i = 0 ; i < n ; ++i ) scanf("%d" , &a[ i ] );
    scanf("%d" , &q );

    while( q-- ){
        scanf("%d" , &h );
        l = lower_bound( a , a + n , h ) - a - 1;
        u = upper_bound( a , a + n , h ) - a;
        if( l < 0 ) putchar('X');
        else printf("%d" , a[ l ] );
        printf(" ");
        if( u == n ) puts("X");
        else printf("%d\n" , a[ u ] );
    }

    return 0;
}
