/*****************************************
 ***Problema: Hanoi Tower Troubles Again!
 ***ID: 10276
 ***Juez: UVA
 ***Tipo: Brute force, Backtracking
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <cstring>
#include <cmath>
#define MAX 51
int a[ MAX ];

bool isInt( double n ){
    if( (int) n == n ){
        return true;
    }
    return false;
}

int main(){
    int i, j, n, t;
	scanf("%d" , &t );
    while( t-- > 0 && scanf("%d", &n) == 1 ) {
        memset( a , 0 , sizeof( a ) );
        for( i = 1 ; ; ++i ) {
            for( j = 0 ; j < n ; ++j )
                if( a[ j ] == 0 || isInt( sqrt( a[ j ] + i ) ) ) break;
            if ( j < n ) a[ j ] = i;
            else break;
        }
        printf("%d\n", i - 1);
    }
    return 0;
}

