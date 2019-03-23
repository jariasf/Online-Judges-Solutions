/*****************************************
 ***Problema: Musical Loop
 ***ID: 11496
 ***Juez: UVA
 ***Tipo: Ad hoc, iteration
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>

int main(){
    int n, A[ 10005 ] , ans;
    bool up;
    while( scanf("%d" , &n ) , n ){
        ans = 0;
        up = false;
        for( int i = 1 ; i <= n ; ++i ){
            scanf("%d" , &A[ i ] );
        }
        A[ 0 ] = A[ n ];
        A[ n + 1 ] = A[ 1 ];

        if( A[ 1 ] > A[ 0 ] ) up = true;

        for( int i = 1 ; i < n + 2 ; ++i ){
            if( A[ i ] > A[ i - 1 ] ){
                if( !up ){
                    up = true;
                    ans++;
                }
            }
            else{
                if( up ){
                    up = false;
                    ans++;
                }
            }
        }
        printf("%d\n" , ans );

    }
    return 0;
}
