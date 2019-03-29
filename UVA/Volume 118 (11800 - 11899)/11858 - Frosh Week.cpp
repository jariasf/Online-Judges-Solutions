/*****************************************
 ***Problema: Frosh Week
 ***ID: 11858
 ***Juez: UVA
 ***Tipo: Sorting , Counting Inversions
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>

int A[ 1000001 ];
int a[ 500002 ];
int b[ 500002 ];

long long merge_sort( int p , int r ) {
    long long count = 0;
    if( p + 1 == r ) return count;
    int q = ( p + r )/2;
    count += merge_sort( p , q ) + merge_sort( q , r );

    int a_size = q - p;
    int b_size = r - q;
    for( int i = 0; i < a_size; ++i ) a[ i ] = A[ p + i ];
    for( int j = 0; j < b_size; ++j ) b[ j ] = A[ q + j ];
    a[ a_size ] = 1<<30;
    b[ b_size ] = 1<<30;

    for( int k = p , i = 0, j = 0 ; k < r ; ++k ) {
        if( a[ i ] < b[ j ] ) {
            A[ k ] = a[ i ];
            ++i;
        }
        else {
            A[ k ] = b[ j ];
            count += a_size - i;
            ++j;
        }
    }
    return count;
}

int main(){
    int n;
    while( scanf("%d" , &n ) != EOF ){
        for( int i = 0 ; i < n  ;++i )scanf("%lld" , &A[ i ] );
        printf("%lld\n" , merge_sort( 0 , n ) );
    }

    return 0;
}
