/*****************************************
 ***Problema: No Problem!
 ***ID: 11608
 ***Juez: UVA
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>

int main(){
    int n , m[ 13 ] , r[ 13 ] , q = 1;
    while( scanf("%d" , &n ) , n >= 0 ){
        for( int i = 0 ; i < 12 ; ++i ) scanf("%d" , &m[ i ] );
        for( int i = 0 ; i < 12 ; ++i ) scanf("%d" , &r[ i ] );
        printf("Case %d:\n" , q++ );
        for( int i = 0 ; i < 12 ; ++i ){
            if( n >= r[ i ] ){
                puts("No problem! :D");
                n -= r[ i ];
            }
            else puts("No problem. :(");
            n += m[ i ];
        }
    }
    return 0;
}
