/**********************************************************************
 ***Algoritmo: Bellman-Ford (One Source Shortest Path - Negative Cyle)
 ***Tipo: Grafos
 ***Autor: Jhosimar George Arias Figueroa
 *********************************************************************/

/*
EJEMPLO DE INPUT
5 9
1 2 7
1 4 2
2 3 1
2 4 2
3 5 4
4 2 3
4 3 8
4 5 5
5 3 5
1

CICLO NEGATIVO
3 3
1 2 500
2 3 5
3 2 -10
1
*/

#include <stdio.h>
#include <vector>

using namespace std;
#define MAX 105  //Maximo numero de vértices
#define Node pair< int , int > //definimos el nodo como un par( first , second ) donde first es el vertice adyacente y second el peso de la arista
#define INF 1<<30 //Definimos un valor grande que represente la distancia infinita inicial

int previo[ MAX ];  //Para la impresion de caminos
int distancia[ MAX ];      //distancia[ u ] distancia de vértice inicial a vértice con ID = u
int V;  //Número total de Vértices del grafo
vector< Node > ady[ MAX ]; //lista de adyacencia

//Función de inicialización
void init(){
    for( int i = 0 ; i <= V ; ++i ){
        distancia[ i ] = INF;  //inicializamos todas las distancias con valor infinito
        previo[ i ] = -1;      //inicializamos el previo del vertice i con -1
    }
}

//Impresion del camino mas corto desde el vertice inicial y final ingresados
void print( int destino ){
    if( previo[ destino ] != -1 )    //si aun poseo un vertice previo
        print( previo[ destino ] );  //recursivamente sigo explorando
    printf("%d " , destino );        //terminada la recursion imprimo los vertices recorridos
}

//Paso de relajacion, retornamos valor booleano para la parte de detección de ciclos
bool relajacion( int actual , int adyacente , int peso ){
    //Si la distancia del origen al vertice actual + peso de su arista es menor a la distancia del origen al vertice adyacente
    if( distancia[ actual ] + peso < distancia[ adyacente ] ){
        distancia[ adyacente ] = distancia[ actual ] + peso;  //relajamos el vertice actualizando la distancia
        previo[ adyacente ] = actual;                         //a su vez actualizamos el vertice previo
        return true;                                          //se pudo realizar paso de relajacion
    }
    return false; //no se pudo realizar paso de relajacion
}

//Algoritmo de BellmanFord para hallar la ruta más corta desde vértice inicial
//a todos los demás y detectar la presencia de un ciclo negativo
void bellmanFord( int inicial ){
    init(); //inicializamos nuestros arreglos
    distancia[ inicial ] = 0;      //Este paso es importante, inicializamos la distancia del inicial como 0

    //O( V * E )
    for( int i = 1 ; i <= V - 1 ; ++i ){ //Iteramos |V| - 1 veces
        for( int actual = 1 ; actual <= V ; ++actual ){  //Estos dos for = O(E)
            for( int j = 0 ; j < ady[ actual ].size() ; ++j ){ //reviso sus adyacentes del vertice actual
                int adyacente = ady[ actual ][ j ].first;    //id del vertice adyacente
                int peso = ady[ actual ][ j ].second;        //peso de la arista que une actual con adyacente ( actual , adyacente )
                //Realizamos paso de relajacion para la arista actual
                relajacion( actual , adyacente , peso );
            }
        }
    }

    //Comprobamos si hay ciclo negativo en el grafo ingresado
    for( int actual = 1 ; actual <= V ; ++actual ){  //Estos dos for = O(E)
        for( int j = 0 ; j < ady[ actual ].size() ; ++j ){ //reviso sus adyacentes del vertice actual
            int adyacente = ady[ actual ][ j ].first;    //id del vertice adyacente
            int peso = ady[ actual ][ j ].second;       //peso de la arista que une actual con adyacente ( origen , destino )
            //Si aun es posible relajar la arista actual entonces tenemos ciclo negativo
            if( relajacion( actual , adyacente , peso ) ){
                puts("Existe Ciclo Negativo");
                return;
            }
        }
    }

    puts("No Existe Ciclo Negativo");

    printf( "Distancias mas cortas iniciando en vertice %d\n" , inicial );
    for( int i = 1 ; i <= V ; ++i ){
        printf("Vertice %d , distancia mas corta = %d\n" , i , distancia[ i ] );
    }

    puts("\n**************Impresion de camino mas corto**************");
    printf("Ingrese vertice destino: ");
    int destino;
    scanf("%d" , &destino );
    print( destino );
    printf("\n");
}

int main(){
    int E, origen, destino , peso , inicial;
    scanf("%d %d" , &V , &E );

    while( E-- ){
        scanf("%d %d %d" , &origen , &destino , &peso );
        ady[ origen ].push_back( Node( destino , peso ) ); //consideremos grafo dirigido
        //ady[ destino ].push_back( Node( origen , peso ) ); //grafo no dirigido
    }
    printf("Ingrese el vertice inicial: ");
    scanf("%d" , &inicial );
    bellmanFord( inicial );
    return 0;
}
