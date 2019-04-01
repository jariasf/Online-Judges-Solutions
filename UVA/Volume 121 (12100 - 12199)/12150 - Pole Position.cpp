/*****************************************
 ***Problema: Pole Position
 ***ID: 12150
 ***Juez: UVA
 ***Tipo: Simulation
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <cstring>

int main(){
    int n, pos[ 1005 ], C , P, idx;
    bool ok;
    while( scanf("%d" , &n ) , n ){
        memset( pos , 0 , sizeof( pos ) );
        ok = true;
        for( int i = 0 ; i < n ; ++i ){
            scanf("%d %d" , &C , &P );
            idx = i + P;
            if( idx >= 0 && idx < n && !pos[ idx ] ) pos[ idx ] = C;
            else ok = false;
        }
        if( !ok )printf("-1\n");
        else{
            printf("%d" , pos[ 0 ] );
            for( int i = 1 ; i < n ; ++i ) printf(" %d" , pos[ i ] );
            printf("\n");
        }
    }
    return 0;
}
