/*****************************************
 ***Problema: Longest Path
 ***ID: 10000
 ***Juez: UVA
 ***Tipo: Graph Theory, Floyd Warshall, DAG
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

#define MAX 105
#define INF 1<<30
int ady[ MAX ][ MAX ];
int V;
void Init(){

    for( int i = 0 ; i <= V ; ++i ){
       for( int j = 0 ; j <= V ; ++j ){
          ady[ i ][ j ] = -1;
       }
    }
}

void Floyd(){
    for( int k = 1 ; k <= V; ++k ){
       for( int i = 1 ; i <= V; ++i ){
          if( ady[ i ][ k ] < 0)continue;
          for( int j = 1; j <= V; ++j ){

              if( ady[ k ][ j ] < 0 || ady[ i ][ k ] + ady[ k ][ j ] <= ady[ i ][ j ]) continue;
              ady[ i ][ j ] = ady[ i ][ k ] + ady[ k ][ j ] ;
          }
       }
    }
}

int main(){
    int inicial, p , q, k, max ,t = 1;
    while ( scanf("%d" ,&V) && V ){
        scanf("%d", &inicial );
        Init();
        while( scanf("%d %d" ,&p ,&q) && (p|q)  ){
            ady[ p ][ q ] = 1;
        }
        Floyd();
        max = ady[ inicial ][ 1 ];
        k = 1;
        for( int i = 2; i<= V ; ++i ){

            if( inicial != i ){
                if( ady[ inicial ][ i ] > max ){
                    max = ady[ inicial ][ i ];
                    k = i;
                }
            }
        }
        printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n", t++ , inicial , ady[ inicial ][ k ] , k);
    }
}
