/*****************************************
 ***Problema: Do Your Own Homework
 ***ID: 11917
 ***Juez: UVA
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <cstring>

int main(){
    int t , n , D;
    scanf("%d" , &t );
    char s[ 21 ];
    char subject[ 105 ][ 21 ] , days[ 105 ];
    for( int q = 1 ; q <= t ; ++q ){
        scanf("%d" , &n );
        for( int i = 0 ; i < n ; ++i ){
            scanf("%s %d" , &subject[ i ] , &days[ i ] );
        }
        scanf("%d %s" , &D , &s );
        int i = 0;
        for( ; i < n ; ++i ){
            if( !strcmp( subject[ i ] , s ) ){
                break;
            }
        }
        printf("Case %d: " , q );
        if( i == n || days[ i ] > D + 5 ) puts("Do your own homework!");
        else if( days[ i ] <= D ) puts("Yesss");
        else puts("Late");
    }

    return 0;
}
