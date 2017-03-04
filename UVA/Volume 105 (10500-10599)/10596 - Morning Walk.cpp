/*****************************************
 ***Problema: Morning Walk
 ***ID: 10596
 ***Juez: UVA
 ***Tipo: Graph Theory, Euler Tour
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <cstring>

#define MAX 205
int V;
int main(){
    int E, u , v;
    int degree[ MAX ];
    while( scanf("%d %d", &V ,&E)  == 2 ){
        memset( degree , 0 , sizeof( degree ) );
        while( E-- ){
            scanf("%d %d", &u ,&v );
            degree[ u ]++; degree[ v ]++;
        }
        bool possible = true;
        for( int i = 0 ; i < V ;++i ){
            if( degree[ i ] & 1 || degree[ 0 ] == 0){
                possible = false;
                break;
            }
        }
        if( !possible )printf("Not Possible\n");
        else{
            printf("Possible\n");
        }
    }
    return 0;
}
