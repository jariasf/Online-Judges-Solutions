/*****************************************
 ***Problema: Cube Painting
 ***ID: 253
 ***Juez: UVA
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/


//viendo un dado nos damos cuenta d las rotaciones
//el dado q se otorga es:
/*
    1
  4 2 3
    5
    6

se comprubea cada dado y su inverso
    6
  3 5 4   -> aqui tenemos que invertir los lados xq sino no corresponderia al dado inicial x ello intercambiamos
    2
    1

    6
  4 5 3
    2
    1
*/

#include <stdio.h>
#include <string.h>
char cube[ 20 ] , a[ 10 ] , b[ 10 ] , s[ 10 ];
int rot[ 30 ][ 10 ] = { { 1 , 2 , 3 , 4 , 5 , 6 } , { 1 , 3 , 5 , 2 , 4 , 6 } , { 1 , 4 , 2 , 5 , 3 , 6 } , { 1 , 5 , 4 , 3 , 2 , 6 } ,
                        { 2 , 1 , 4 , 3 , 6 , 5 } , { 2 , 3 , 1 , 6 , 4 , 5 } , { 2 , 4 , 6 , 1 , 3 , 5 } , { 2 , 6 , 3 , 4 , 1 , 5 } ,
                        { 3 , 1 , 2 , 5 , 6 , 4 } , { 3 , 2 , 6 , 1 , 5 , 4 } , { 3 , 5 , 1 , 6 , 2 , 4 } , { 3 , 6 , 5 , 2 , 1 , 4 } };

bool rotate(){
    char tmp;
    for( int i = 0 ; i < 12 ; ++i ){
        for( int j = 0 ; j < 6 ; ++j ) s[ j ] = a[ rot[ i ][ j ] - 1 ];
        s[ 6 ] = '\0';
        if( !strcmp( s , b ) ) return true;
        for( int j = 5 ; j >= 0 ; --j ) s[ 5 - j ] = a[ rot[ i ][ j ] - 1 ];
        tmp = s[ 2 ]; s[ 2 ] = s[ 3 ]; s[ 3 ] = tmp;
        if( !strcmp( s , b ) ) return true;
    }
    return false;
}

int main(){
    while( scanf("%s" , &s ) == 1 ){
        int i = 0;
        for( ; i < 6 ; ++i )  a[ i ] = s[ i ];
        for( ; i < 12 ; ++i ) b[ i - 6 ] = s[ i ];
        a[ 6 ] = '\0'; b[ 6 ] = a[ 6 ];
        if( rotate() ) puts("TRUE");
        else puts("FALSE");
    }
    return 0;
}
