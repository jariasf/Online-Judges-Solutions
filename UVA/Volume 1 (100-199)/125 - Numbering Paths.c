/************************************************************************
 ***Problema: Numbering Paths
 ***ID: 125
 ***Juez: UVA
 ***Tipo: Graph Theory, Strongly Connected Components, Transitive Closure
 ***Tiempo: 0.024
 ***Autor: Jhosimar George Arias Figueroa
 ***********************************************************************/
#include <stdio.h>
#include <string.h>

#define MAX 70
int ady[ MAX ][ MAX ][ MAX ] , V , resp[ MAX ][ MAX ][ MAX ];

void CountingPath(){
    int s , i , j , k;
    for( s = 2 ; s <= 64 ; ++s ){
        for( i = 0 ; i < V ; ++i ){
            for( j = 0 ; j < V ; ++j ){
                for( k = 0 ; k < V ; ++k )
                    ady[ i ][ j ][ s ] += ady[ i ][ k ][ s - 1 ] * ady[ k ][ j ][ 1 ];

                resp[ i ][ j ][ s ] = resp[ i ][ j ][ s - 1 ];
                //Si existen rutas mayores al numero de vertices entonces hay ciclo
                if( s > V && ady[ i ][ j ][ s ] != 0 ){
                    resp[ i ][ j ][ s ] = -1;
                }else{
                    resp[ i ][ j ][ s ] += ady[ i ][ j ][ s ];
                }
            }
        }
    }

    for( i = 0 ; i < V ; ++i ){
        for( j = 0 ; j < V ; ++j ){
            ( j == 0 ) ? printf("%d" , resp[ i ][ j ][ 64 ] ) : printf(" %d", resp[ i ][ j ][ 64 ]);
        }
        printf("\n");
    }
}

int max( int a , int b ){ return ( a < b )? b:a ;}

int main(){
    int n, q = 0 , u , v , i , j;
    while( scanf("%d" , &n ) != EOF ){
        V = 0;
        memset( ady , 0 , sizeof( ady ) );
        memset( resp , 0 , sizeof( resp ) );
        for( i = 0 ; i < n && scanf("%d %d" , &u , &v ) == 2 ; ++i ){
            ady[ u ][ v ][ 1 ]++;
            resp[ u ][ v ][ 1 ]++;
            V = max( u , max( v , V ) );
        }
        V++;
        printf("matrix for city %d\n" , q++ );
        CountingPath();
    }
    return 0;
}
