/*****************************************
 ***Problema: Fix the Pond
 ***ID: 12529
 ***Juez: UVA
 ***Tipo: Flood Fill
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#define MAX 705
struct Cell{
    int right , left , up , down , x , y;
}table[ MAX ][ MAX ], Q[ 1024 * 1024 ];

char ady[ MAX ][ MAX ] ;
int h , w , seen[ MAX ][ MAX ];
int dx[ 4 ] = { 1 , -1 , 0 ,  0 };
int dy[ 4 ] = { 0 ,  0 , 1 , -1 };

void flood( int x , int y ){
    int head = 0 , tail = 0 , i , nx , ny;
    Q[ tail ].x = x;
    Q[ tail++ ].y = y;
    seen[ x ][ y ] = 1;
    while( head != tail ){
        x = Q[ head ].x; y = Q[ head++ ].y;
        for( i = 0 ; i < 4 ; ++i ){
            nx = dx[ i ] + x , ny = dy[ i ] + y;
            if( nx >= 0 && ny >= 0 && nx < h && ny < w && !seen[ nx ][ ny ] ){
                if( ( i == 0 && !table[ x ][ y ].down ) || ( i == 1 && !table[ x ][ y ].up ) || ( i == 2 && !table[ x ][ y ].right )
                    || ( i == 3 && !table[ x ][ y ].left ) ){
                    Q[ tail ].x = nx; Q[ tail++ ].y = ny;
                    seen[ nx ][ ny ] = 1;
                }
            }
        }
    }
}

int main(){
    int n , i , j , k ,a , b , ans;
    while( scanf("%d" , &n ) != EOF ){
        for( i = 0 ; i < 2 * n - 1 && scanf("%s" , ady[ i ] ) == 1 ; ++i );
        h = 2 * n;
        w = 2 * n + 1;
        for( i = 0 ; i < h ; ++i ){
            for( j = 0 ; j < w ; ++j ){
                seen[ i ][ j ] = 0;
                table[ i ][ j ].right = table[ i ][ j ].left = table[ i ][ j ].down = table[ i ][ j ].up = 0;
            }
        }

        for( i = 0 , a = 1 ; i < 2 * n - 1 ; ++i , ++a ){
            b = 1;
            if( a % 2 == 0 ) b = 2;
            for( j = 0 ; j < n ; ++j , b += 2 ){
                if( ady[ i ][ j ] == 'H' ){
                    table[ a - 1 ][ b - 1 ].down = 1;
                    table[ a - 1 ][ b ].down = 1;
                    table[ a ][ b - 1 ].up = 1;
                    table[ a ][ b ].up = 1;
                }
                else{
                    table[ a - 1 ][ b - 1 ].right = 1;
                    table[ a ][ b - 1 ].right = 1;
                    table[ a - 1 ][ b  ].left = 1;
                    table[ a ][ b ].left = 1;
                }
            }
        }

        ans = 0;
        for( i = 0 ; i < h ; ++i ){
            for( j = 0 ; j < w ; ++j ){
                if( !seen[ i ][ j ] ){
                    flood( i , j );
                    ans++;
                }
            }
        }
        printf("%d\n" , ans - 1 );
    }
    return 0;
}
