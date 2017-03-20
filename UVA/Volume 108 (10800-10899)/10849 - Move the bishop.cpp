/*****************************************
 ***Problema: Move the bishop
 ***ID: 10849
 ***Juez: UVA
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>

int abs( int x ){
    if( x < 0 ) x = -x;
    return x;
}
bool par( int x ){
    if( x & 1 ) return 0;
    return 1;
}

bool colorWhite( int x1 , int y1 , int x2 , int y2 ){
    if( ( par( x1 ) && !par( y1 ) ) || ( !par( x1 ) && par( y1 ) ) ){
        if(( par( x2 ) && !par( y2 ) ) || ( !par( x2 ) && par( y2) ))return true;
    }
    return false;
}

bool colorBlack( int x1 , int y1 , int x2 , int y2 ){
    if( ( par( x1 ) && par( y1 ) ) || ( !par( x1 ) && !par( y1 ) ) ){
        if( ( par( x2 ) && par( y2 ) ) || ( !par( x2 ) && !par( y2) ))return true;
    }
    return false;
}


int main(){
    int t , n, xini , yini , xfin , yfin, q ,dif1 , dif2;
    scanf("%d" , &t );
    while( t-- ){
        scanf("%d %d" , &q , &n );
        while( q-- ){
            scanf("%d %d %d %d" , &xini , &yini , &xfin  ,&yfin );
            if( xini <= 0 || xini > n || yini <= 0 || yini > n || xfin <= 0 || xfin >n || yfin <= 0 || yfin > n ){
                puts("no move");
                continue;
            }

            if( xini == xfin && yini == yfin )puts("0");
            else if( abs( xini - xfin ) == abs( yini - yfin ) )puts("1");
            else if( ( xini + yini ) == ( xfin + yfin ) )puts("1");
            else if( colorWhite( xini , yini , xfin , yfin ) || colorBlack( xini , yini , xfin , yfin ) )puts("2");
            else puts("no move");
        }
    }

    return 0;
}
