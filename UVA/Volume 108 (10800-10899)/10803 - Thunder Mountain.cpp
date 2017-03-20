/*****************************************
 ***Problema: Thunder Mountain
 ***ID: 10803
 ***Juez: UVA
 ***Tipo: Graph Theory, Floyd Warshall
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <cmath>

#define MAX 128

double ady[ MAX ][ MAX ];
int V , x[ MAX ] , y[ MAX];
int seen[ MAX ][ MAX ];

double dist( int x , int y , int x1 , int y1 ){
    return sqrt( ( x - x1 ) * ( x - x1 ) + ( y - y1 ) * ( y - y1 ) );
}

void Floyd(){
    for( int k = 0 ; k < V ; ++k ){
        for( int i = 0 ; i < V ; ++i ){
            if( i == k || seen[ i ][ k ] == 0 )continue;
            for( int j = 0 ; j < i ; ++j ){
                if( seen[ k ][ j ] == 0 )continue;
                if( seen[ i ][ j ] == 1 && ady[ i ][ j ] < ady[ i ][ k ] + ady[ k ][ j ] )continue;

                ady[ i ][ j ] = ady[ j ][ i ] = ady[ i ][ k ] + ady[ k ][ j ];
                seen[ i ][ j ] = seen[ j ][ i ] = 1;
            }
        }
    }
}


int main(){
    int t;
    scanf("%d" ,&t );
    for( int q = 1 ; q <= t; ++q ){
        scanf("%d" ,&V );

        for( int i = 0 ; i < V ; ++i ){
            scanf("%d %d" , &x[ i ] , &y[ i ] );
        }

        for( int i = 0 ; i < V ; ++i ){
            for( int j = 0 ; j < i ; ++j ){

                 ady[ i ][ j ] = ady[ j ][ i ] = dist( x[ i ] , y[ i ] , x[ j ] , y[ j ] );
                 if( ady[ i ][ j ] < ( 10.0 + 10e-9 ) ){
                     seen[ i ][ j ] = seen[ j ][ i ] = 1;
                 }
                 else seen[ i ][ j ] = seen[ j ][ i ] = 0;

            }
            ady[ i ][ i ] = 0;
            seen[ i ][ i ] = 1;
        }

        Floyd();
        int i , j;
        double r;
        for( i = 0 , r = 0 ; i < V ; ++i ){
            for( j = 0 ; j < i ; ++j ){
                if( seen[ i ][ j ] == 0 )break;
                if( ady[ i ][ j ] > r ) r = ady[ i ][ j ];
            }
            if( j < i )break;
        }

        printf("Case #%d:\n" , q);
        if( i < V )
            printf("Send Kurdy\n\n");
        else
            printf("%.4f\n\n", r);
    }

    return 0;
}

