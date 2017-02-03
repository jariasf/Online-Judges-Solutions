/*****************************************
 ***Problema: Arbitrage
 ***ID: 104
 ***Juez: UVA
 ***Tipo: Floyd Warshall
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <string.h>
#define MAX 25
#define INF 1<<30
int V , path[ MAX ][ MAX ][ MAX ];
double ady[ MAX ][ MAX ][ MAX ];
void init2(){
    int i , j;
    for( i = 0 ; i < V ; ++i ){
        for( j = 0 ; j < V ; ++j ){
            path[ i ][ j ][ 1 ] = i;
        }
    }
}
//FLOYD 3 dimensiones
//i: vertice origen
//j: vertice destino
//s: numero de aristas entre origen y destino
//ady[ i ][ j ][ s ] = maximo o minimo costo entre i y j usando s pasos.
void floydSteps(){
    int i , j , k , s;
    for( s = 2 ; s <= V ; ++s ){
        for( k = 0 ; k < V ; ++k ){
            for( i = 0 ; i < V ; ++i ){
                for( j = 0 ; j < V ; ++j ){
                    if( ady[ i ][ k ][ s - 1 ] * ady[ k ][ j ][ 1 ] > ady[ i ][ j ][ s ] ){
                        ady[ i ][ j ][ s ] = ady[ i ][ k ][ s - 1 ] * ady[ k ][ j ][ 1 ];
                        path[ i ][ j ][ s ] = k;
                    }
                }
            }
        }
    }
}

void print( int x , int y , int s ){
    if( s == 0 ) printf("%d" , x + 1 );
    else{
        print( x , path[ x ][ y ][ s ] , s - 1 );
        printf(" %d" , y + 1 );
    }
    return;
}


int main(){
    int i , j , s;
    double w;
    while( scanf("%d" , &V ) != EOF ){
        memset( ady , 0 , sizeof( ady ) );
        for( i = 0 ; i < V ; ++i ){
            for( j = 0 ; j < V ; ++j ){
                if( i == j ) { ady[ i ][ j ][ 1 ] = 1.0;}
                else{
                    scanf("%lf" , &w );
                    ady[ i ][ j ][ 1 ] = w;
                }
            }
        }
        init2();
        floydSteps();
        for( s = 0 ; s <= V ; ++s ){
            for( i = 0 ; i < V ; ++i ){
                if( ady[ i ][ i ][ s ] > 1.01 ){
                    print( i , i , s );
                    break;
                }
            }
            if( i != V ) break;
        }

        if( s == V + 1 ) printf("no arbitrage sequence exists");
        printf("\n");
    }

    return 0;
}
