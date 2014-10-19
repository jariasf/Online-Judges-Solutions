/*****************************************
 ***Algoritmo: Depth First Search usando Stack
 ***Tipo: Teoria de grafos
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

/*
EJEMPLO DE INGRESO

5 5
1 2
1 3
2 4
2 5
1 5
1
5

*/

#include <stdio.h>
#include <stack>
#include <vector>

using namespace std;

#define MAX 500
vector<int> ady[ MAX ];  //lista de adyacencia
bool visitado[ MAX ];    //para nodos visitados
int prev[ MAX ];         //padre de nodo i, para ver recorrido

void dfs(){

    int ini, pasos, maxi , actual, fin;
    printf("Nodo raiz: ");
    scanf("%d" , &ini );
    printf("Nodo final: ");
    scanf("%d" , &fin );

    memset( visitado , 0 , sizeof( visitado ) );           //inicializamos como no visitado
    stack<int> S;
    S.push( ini );
    prev[ ini ] = -1;
    visitado[ ini ] = true;
    pasos = 0; maxi = 0;

    while( !S.empty() ){
       maxi = max( maxi , (int) S.size() );                //simplemente para ver la memoria usada en la pila
       actual = S.top(); S.pop();
       pasos++;

       if( actual == fin )break;

       for(int i = 0 ; i < ady[ actual ].size() ; ++i ){  //vemos adyacentes de nodo actual
          int v = ady[ actual ][ i ];
          if( !visitado[ v ]){                   //si no esta visitado insertamos
             visitado[ v ] = true;
             prev[ v ] = actual;                 //padre de adyacente es el actual
             S.push( v );
          }
       }
    }


    //vemos recorrido de inicial a final
    printf("Recorrido DFS con Stack\n");
    vector<int> path;
    actual = fin;
    while( 1 ){
        path.push_back( actual );
        if( prev[ actual ] == -1 )break;
        actual = prev[ actual ];
    }

    for( int i = path.size() - 1 ; i >= 0 ; --i )
        ( i == path.size() - 1 )?printf("%d" , path[ i ] ): printf("->%d" , path[ i ] );
    printf("\n");


    printf( "Memoria maxima: %d\n" , maxi );
    printf( "Nro Pasos: %d\n" , pasos );

}

int main(){

    int  E , V , x , y;
    scanf("%d %d" , &V , &E ); //Numero de vertices y numero de aristas

    for(int i = 1 ; i <= E ; ++i ){
        scanf("%d %d" , &x , &y );  //Origen y destino
        ady[ x ].push_back( y );
        //ady[ y ].push_back( x );  //Para grafo no dirigido
    }

    dfs();

    return 0;
}
