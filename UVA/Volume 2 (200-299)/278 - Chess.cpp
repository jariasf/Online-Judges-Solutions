/*****************************************
 ***Problema: Chess
 ***ID: 278
 ***Juez: UVA
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
int min( int x , int y ){ return ( x < y )? x : y; }
int main(){
    int t , n , m;
    char c;
    scanf("%d" , &t );
    while( t-- ){
        scanf(" %c %d %d" , &c , &m , &n );
        if( c == 'k' ) printf("%d\n" ,( ( m * n ) + 1)/2 ); //((m+1)/2) * ((n+1)/2) + (m/2) * (n/2)
        else if( c == 'r' ) printf("%d\n" , min( m , n ) );
        else if( c == 'Q' ) printf("%d\n" , min( m , n ) );
        else printf("%d\n"  , ( ( m + 1 )/2 ) * ( ( n + 1 )/2 )  );
    }
    return 0;
}
