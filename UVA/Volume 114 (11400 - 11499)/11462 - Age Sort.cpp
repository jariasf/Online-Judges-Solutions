/*****************************************
 ***Problema: Age Sort
 ***ID: 11462
 ***Juez: UVA
 ***Tipo: Sorting
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <algorithm>

using namespace std;

int main(){
    int n;
    while( scanf( "%d" , &n) && n ){
        int a[n];
        for( int i = 0 ; i < n ; ++i ){
           scanf( "%d" , &a[i] );
        }
        sort( a, a + n );
        printf( "%d" , a[0] );
        for( int i = 1 ; i < n ; ++i ){
           printf( " %d" , a[i] );
        }
        putchar('\n');
    }

    return 0;
}
