/*****************************************
 ***Problema: Lunch in Grid City
 ***ID: 885
 ***Juez: UVA
 ***Tipo: Sorting
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <stdlib.h>

#define MAX 50005

int cmp (const void * a, const void * b){
  return ( *(int*)a - *(int*)b );
}

int main(){
    int t , h , w , k , x[ MAX ] , y[ MAX ];
    scanf("%d" , &t );
    while( t-- ){
        scanf("%d %d %d" , &h , &w  , &k );
        for( int i = 0 ; i < k ; ++i )
            scanf("%d %d" , &x[ i ] , &y[ i ] );
        qsort( x , k , sizeof( int ) , cmp );
        qsort( y , k , sizeof( int ) , cmp );
        if( k % 2 == 0 ){
            printf("(Street: %d, Avenue: %d)\n" ,x[ ( k/ 2 ) - 1] , y[ ( k / 2 ) - 1 ] );
        }
        else{
            printf("(Street: %d, Avenue: %d)\n" ,x[ ( ( k + 1 )/ 2 ) - 1] , y[ ( ( k + 1 ) / 2 ) - 1 ] );
        }
    }
    return 0;
}
