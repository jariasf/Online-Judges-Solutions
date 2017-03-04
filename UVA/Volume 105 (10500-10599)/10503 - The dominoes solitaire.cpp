/*****************************************
 ***Problema: The dominoes solitaire
 ***ID: 10503
 ***Juez: UVA
 ***Tipo: Backtracking
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <cstring>

int xini , yini , xfin , yfin, x[ 15 ], y[ 15 ] , m , sz;
bool seen[ 15 ] , finish;

void solve( int len , int yini ){
    if( len == sz ){
        if( xfin == yini )finish = true;
        return;
    }
    for( int i = 0 ; i < m ; ++i ){
        if( !seen[ i ] ){
            if( x[ i ] == yini ){
                seen[ i ] = 1;
                solve( len + 1 , y[ i ] );
                seen[ i ] = 0;
            }
            else if( y[ i ] == yini ) {
                seen[ i ] = 1;
                solve( len + 1 , x[ i ] );
                seen[ i ] = 0;
            }
        }
    }
}

int main(){
    while( scanf("%d" , &sz ) , sz ){
        scanf("%d%d%d%d%d" , &m , &xini , &yini , &xfin , &yfin );
        for( int i = 0 ; i < m ; ++i ) scanf("%d %d" , &x[ i ] , &y[ i ] );
        finish = false;
        for( int i = 0 ; i < m ; ++i ){
        	memset( seen , 0 , sizeof( seen ) );
            seen[ i ] = 1;
            solve( 0 , yini );
            if( finish ) break;
        }
        if( finish ) puts("YES");
        else puts("NO");
    }

    return 0;
}
