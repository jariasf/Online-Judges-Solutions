/*****************************************
 ***Problema: The falling leaves
 ***ID: 699
 ***Juez: UVA
 ***Tipo: Tree traversal, recursion
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <cstring>
#define MAX 1005
int tree[ MAX ];

void Solve( int pos , int value ){
    tree[ pos ] += value;
    int n;

    ///hijo izquierdo
    scanf("%d",&n);
    if( n != -1 ) Solve( pos - 1 , n );

    ///hijo derecho
    scanf("%d",&n);
    if( n != -1 ) Solve( pos + 1 , n );

    return;
}

int main(){
    int n, t = 1;
    bool first;
    while( scanf("%d" ,&n) ){
        if( n == -1 )break;

        memset( tree, 0 , sizeof( tree ) );
        Solve( 500 , n );
        first = true;

        printf("Case %d:\n", t++);

        for( int i = 0 ; i < MAX; ++i ){
            if( tree[ i ] ){
               if( first ){
                  printf( "%d" , tree[ i ] );
                  first = false;
               }
               else{
                  printf(" %d", tree[ i ] );
               }
            }
        }
        printf("\n\n");

    }

    return 0;
}
