/*****************************************
 ***Problema: Collecting Beepers
 ***ID: 10496
 ***Juez: UVA
 ***Tipo: Backtracking , DP + bitwise
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <cstdio>
#include <cstring>
#include <cstdlib>

#define MAX 30
int min( int a , int b ){return ( a < b )? a : b ;}

struct Point{
    int x;
    int y;
}V[ MAX ];

int dist[ MAX ][ MAX ], memo[ MAX ][ 1<<11 ] , k , h,  w;

///ciudad representada x el bit actual posicion
///mask ciudades visitadas representada x bits 11111 5 ciudades
int solve( int city , int mask ){
    if( memo[ city ][ mask ] >= 0 ) return memo[ city ][ mask ];
    ///si visite todas las ciudades excepto la inicial
    if( mask == 1 ) return memo[ city ][ mask ] = dist[ city ][ 0 ];
    memo[ city ][ mask ] = 1<<30;
    for( int i = 1 ; i < k ; ++i ){
         ///if no visitado
         if( mask & (1<<i) ){
             ///como mi maskara de no visitados es puro 1111 para marcarlo como visitado
             ///necesito convertirlo a 0 x ello uso xor
             memo[ city ][ mask ] = min( memo[ city ][ mask ] , 
									dist[ city ][ i ] + solve( i , mask ^( 1<< i ) ) );
         }
    }
    return memo[ city ][ mask ];

}

int main(){
    int t , x , y , p , q;
    scanf("%d" , &t );
    while( t-- ){
        scanf("%d %d %d %d %d" , &h ,&w , &V[ 0 ].x , &V[ 0 ].y , &k );
        k++;
        for( int i = 1 ; i < k ; ++i ){
            scanf("%d %d" , &V[ i ].x , &V[ i ].y );
        }
        for( int i = 0 ; i < k ; ++i ){
            for( int j = 0 ; j < k ; ++j ){
                 dist[ i ][ j ] =  abs( V[ i ].x - V[ j ].x ) + abs( V[ i ].y - V[ j ].y );
            }
        }
        memset( memo , 0xff , sizeof( memo ) );

        printf("The shortest path has length %d\n" , solve( 0 , (1<<k) - 1 ) );
    }


    return 0;
}
