/*****************************************
 ***Problema: Componentes Conexas
 ***Tipo: Teoria de Grafos , DFS
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

/*
EJEMPLO DE INGRESO

5 3
1 2
2 3
4 5

*/

#include <stdio.h>
#include <vector>
#include <cstring>
using namespace std;
#define MAX 10001
vector<int> ady[ MAX ];
bool visitado[ MAX ]; //para todo el recorrido
bool visitado_componente[ MAX ]; //para saber que nodos pertenecen a que componente
//algoritmo estandar de DFS
void dfs( int u ){
    visitado[ u ] = true;
    visitado_componente[ u ] = true;
    for( int v = 0 ; v < ady[ u ].size(); ++v ){
        if( !visitado[ ady[ u ][ v ] ] ){
            dfs( ady[ u ][ v ] );
        }
    }
}

int main(){
    ///enumerar vertices desde 1 hasta V
    int V, E , u ,v;
    scanf("%d %d" , &V , &E );
    while( E-- ){
        scanf("%d %d" , &u ,&v );
        ady[ u ].push_back( v );
        ady[ v ].push_back( u );

    }
    printf("Cantidad de Componentes Conexas\n");
    int total = 0;
    memset( visitado , 0 , sizeof( visitado ) );
    for( int i = 1 ; i <= V ; ++i ){    //recorremos todos los posibles vertices
         if( !visitado[ i ] ){          //si alguno no fue visitado tenemos una componente a partir de ese nodo
             memset( visitado_componente , 0 , sizeof( visitado_componente ) );
             dfs( i );                  //recorremos a partir de nodo i todo el grafo que se forma
             printf("Componente %d:" , total + 1 ); //imprimo vertices de cada componente
             for( int j = 1 ; j <= V ; ++j ){
                if( visitado_componente[ j ] ){
                    printf(" %d" , j );
                }
             }
             printf("\n\n");
             total++;                   //incrementamos cantidad de componentes
         }
    }
    printf("%d\n" , total );

    return 0;
}
