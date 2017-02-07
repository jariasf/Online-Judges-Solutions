/*****************************************
 ***Problema: Station Balance
 ***ID: 410
 ***Juez: UVA
 ***Tipo: Greedy
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
#define MAX 20
int a[ MAX ];
int main(){
    int C, N, alone , q = 1, T , ini;
    double IMB, prom;
    while( scanf("%d %d" , &C , &N ) == 2 ){
        memset( a , 0 , sizeof( a ) );

        IMB = 0.0;
        prom = 0.0;
        ini = (C<<1) - N;
        for( int i = ini ; i < (C<<1) ; ++i ){
            scanf("%d" , &a[ i ] );
            prom += a[ i ];
        }

        sort( a , a + ( C<<1 ) );

        printf("Set #%d\n" , q++ );

        for( int i = 0 ; i < C; ++i ){
             printf(" %d:" , i );
             IMB += fabs( C * a[ i ] + C * a[ ( C<<1 ) - i - 1 ] - prom );
             if( a[ i ] ){
                 printf(" %d" , a[ i ] );
             }
             if( a[ ( C<<1 ) - i - 1 ] )printf(" %d" , a[ ( C<<1 ) - i - 1 ] );
             printf("\n");
        }

        printf("IMBALANCE = %.5lf\n\n" , IMB/(double)C );

    }

    return 0;
}
