/*****************************************
 ***Problema: Star Grid
 ***ID: 12488
 ***Juez: UVA
 ***Tipo: Counting Inversions
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#define MAX 30
int A[ MAX ];

int insertion_sort( int L ){
    int cont = 0, p;
    for( int j = 1, i ; j < L ; ++j ){
        p = A[ j ];
        i = j - 1;
        while( i >= 0 && A[ i ] > p ){
            A[ i + 1 ] = A[ i ];
            i--;
            cont++;
        }
        A[ i + 1 ] = p;
    }
    return cont;
}

int pos[ MAX ];
int main(){
    int n , i , x;
    while( scanf("%d" , &n ) == 1 ){

        for( i = 0 ; i < n && scanf("%d" , &x ) ; ++i ) pos[ x ] = i;
        for( i = 0 ; i < n && scanf("%d" , &x ) ; ++i ) A[ i ] = pos[ x ];

        printf("%d\n" , insertion_sort( n ) );

    }
    return 0;
}
