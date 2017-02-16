/*********************************************
 ***Problema: The Tourist Guide
 ***ID: 10099
 ***Juez: UVA
 ***Tipo: Graph Theory, Floyd Warshall, Maxmin
 ***Autor: Jhosimar George Arias Figueroa
 *********************************************/

#include <stdio.h>

#define MAX 101
int ady[ MAX ][ MAX ] , V;

void Init(){
   for( int i = 0 ; i < V ; ++i ){
       for( int j = 0 ; j < V ; ++j ){
           ady[ i ][ j ] = -1;
       }
       ady[ i ][ i ] = 0;
   }
}

int min(int a, int b){
    return (a < b) ? a: b;
}

int max(int a, int b){
    return (a > b) ? a: b;
}


void MaxMin(){
    for( int k = 0 ; k < V ; ++k ){
         for( int i = 0 ; i < V ; ++i ){
             for( int j = 0 ; j < V ; ++j ){
                  ady[ i ][ j ] = max( ady[ i ][j ] , min( ady[ i ][k ] , ady[ k ][ j ] ) );
             }
         }
    }
}

int main(){
    int E , u , v , w, q = 1 , ans;
    while( scanf( "%d %d" , &V , &E ) && V|E ){
        Init();
        while( E-- ){
            scanf("%d %d %d" , &u , &v , &w );
            u--; v--;
            ady[ u ][ v ] = ady[ v ][ u ] = w;
        }
        scanf("%d %d %d" ,&u ,&v ,&w );
        u--; v--;
        MaxMin();
        ady[ u ][ v ]--;
        printf("Scenario #%d\n" , q++ );
        ans = w/ady[ u ][ v ];

        if( w % ady[ u ][ v ] != 0 )ans++;

        printf("Minimum Number of Trips = %d\n\n" , ans );

    }

    return 0;
}
