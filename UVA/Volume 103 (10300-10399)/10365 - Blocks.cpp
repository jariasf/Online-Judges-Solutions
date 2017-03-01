/*****************************************
 ***Problema: Blocks
 ***ID: 10365
 ***Juez: UVA
 ***Tipo: Brute force
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#define MAX 1000

int getArea( int x , int y , int z ){
    return ( x * y * 2 + z * y * 2 + x * z * 2 );
}

int main(){
    int t , n , ans, area;
    scanf("%d" , &t );
    while( t-- ){
        scanf("%d" , &n );
        ans = 1<<30;
        for( int i = 1 ; i <= MAX ; ++i ){
            if( i > n )break;
            for( int j = i ; j <= MAX ; ++j ){
                if( i * j > n )break;
                for( int k = j ; k <= MAX ; ++k ){
                    if( i * j * k > n )break;
                    if( i * j * k == n ){
                        area = getArea( i , j , k );
                        if( ans > area ) ans = area;
                    }
                }
            }
        }
        printf("%d\n" , ans );
    }
    return 0;
}
