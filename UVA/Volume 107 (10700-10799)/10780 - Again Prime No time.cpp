/*****************************************
 ***Problema: Again Prime! No Time
 ***ID: 10780
 ***Juez: UVA
 ***Tipo: Number Theory, Prime Factorization
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <iostream>

using namespace std;
#define MAX 10005
int factors[ MAX ];

int main(){
    int t, m , n, idx, cont, min, num;
    scanf( "%d" , &t );

    for( int q = 1 ; q <= t; ++q ){

        scanf( "%d %d" , &m, &n );
        idx = 0;
        int time[ MAX ] = { 0 };
        for( int i = 2 ; i*i <= m ; ++i ){
           if( m%i == 0 )factors[ idx++ ] = i;
           while( m%i == 0){
               time[ idx - 1 ]++;
               m /= i;
           }
        }
        if( m > 1 ) { factors[ idx++ ] = m; time[ idx - 1 ]++;}

        min = 1<<30;
        for( int  j = 0 ; j < idx ; ++j ){
            cont = 0;
            int cont2 = 0;

            for( int i = 2; i <= n ; ++i ){
               num = i;
               if( num % factors[ j ] == 0)cont2++;
               while( num % factors[ j ] == 0 ){
                   cont++;
                   num /= factors[ j ];
               }
            }
            min = std::min( min , cont/time[ j ] );
        }
        printf( "Case %d:\n" , q );
        if( min == 1<<30 || min == 0 )printf("Impossible to divide\n");
        else printf( "%d\n", min );
    }

    return 0;
}
