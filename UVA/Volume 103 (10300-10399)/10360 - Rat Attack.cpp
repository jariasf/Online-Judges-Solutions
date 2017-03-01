/*****************************************
 ***Problema: Rat Attack
 ***ID: 10360
 ***Juez: UVA
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <cstring>

#define MAX 1025
int ady[ MAX ][ MAX ];
int main(){
    int t , d , n , x , y , c , maxi ;
    scanf("%d" , &t );
    while( t-- ){
        scanf("%d %d" , &d ,&n );
        memset( ady , 0 , sizeof( ady ) );
        maxi = 0;
        while( n-- ){
            scanf("%d %d %d" , &x , &y , &c );
            for( int i = x - d ; i <= x + d ; ++i ){
                if( i < 0 )continue;
                if( i >= MAX ) break;
                for( int j = y - d ; j <= y + d ; ++j ){
                    if( j < 0 ) continue;
                    if( j >= MAX )break;
                    ady[ i ][ j ] += c;
                    if( ady[ i ][ j ] > maxi ){
                        maxi = ady[ i ][ j ];
                    }
                }
            }
        }
        for( int i = 0 ; i < MAX ; ++i )
            for( int j = 0 ; j < MAX ; ++j )
                if( ady[ i ][ j ] == maxi ){
                    printf("%d %d %d\n" , i , j , ady[ i ][ j ] );
                    i = MAX;
                    break;
                }
    }
    return 0;
}
