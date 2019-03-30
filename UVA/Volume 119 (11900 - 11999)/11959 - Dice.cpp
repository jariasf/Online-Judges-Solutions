/*****************************************
 ***Problema: Dice
 ***ID: 11959
 ***Juez: UVA
 ***Tipo: Ad hoc similar 253
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

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
    int t , i ;
    scanf("%d" , &t );
    while( t-- ){
        scanf("%s" , &s );
        a[ 0 ] = s[ 0 ];
        a[ 1 ] = s[ 2 ];
        a[ 2 ] = s[ 3 ];
        a[ 3 ] = s[ 5 ];
        a[ 4 ] = s[ 4 ];
        a[ 5 ] = s[ 1 ];
        scanf("%s" , &s );
        b[ 0 ] = s[ 0 ];
        b[ 1 ] = s[ 2 ];
        b[ 2 ] = s[ 3 ];
        b[ 3 ] = s[ 5 ];
        b[ 4 ] = s[ 4 ];
        b[ 5 ] = s[ 1 ];
        a[ 6 ] = '\0'; b[ 6 ] = a[ 6 ];
        if( rotate() ) puts("Equal");
        else puts("Not Equal");
    }
    return 0;
}
