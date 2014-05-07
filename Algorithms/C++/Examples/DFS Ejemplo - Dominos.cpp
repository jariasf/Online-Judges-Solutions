/*****************************************
 ***Problema: Dominos
 ***Tipo: Teoria de Grafos, DFS
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

/*
EJEMPLO DE INGRESO

9 6 3
1 2
2 5
5 3
4 3
6 7
7 8
1
6
4

*/

#include <stdio.h>
#include <vector>
using namespace std;

#define MAX 10001
vector<int> ady[ MAX ];                     //lista de adyacencia
int total;                                  //la cantidad total de dominos que caerán
bool visitado[ MAX ];                       //arreglo de domino caido
void dfs( int u ){                          //domino origen
    total++;                                //aumento en mi respuesta la caida de un domino
    visitado[ u ] = true;                   //domino "u" cayo
    for( int v = 0 ; v < ady[ u ].size(); ++v ){ //verifico los demas posibles domino que caeran si impulso "u"
         if( !visitado[ ady[ u ][ v ] ] ){         //si el domino adyacente no cayó entonces es el siguiente a evaluar
             dfs( ady[ u ][ v ] );               //recursivamente veo que dominos caeran a partir del adyacente de "u"
         }
    }
}

int main(){

    int V, M , Q, x , y , origen;            //numero de dominos, cantidad de enlaces, consultas
    scanf("%d %d %d" ,&V ,&M , &Q );
    while( M-- ){
        scanf("%d %d" ,&x ,&y );            //domino x hace caer a domino y
        ady[ x ].push_back( y );
    }
    while( Q-- ){
        scanf("%d" , &origen );             //domino origen
        total = 0;
        memset( visitado , 0 , sizeof( visitado ) );  //inicializo arreglo de visitados para cada consulta
        dfs( origen );
        printf("%d\n" , total );
    }

    return 0;
}
