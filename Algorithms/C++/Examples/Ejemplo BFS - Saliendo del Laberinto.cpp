/****************************************************
 ***Problema: SALIENDO DEL LABERINTO
 ***Algoritmo: BFS (BUSQUEDA POR ANCHURA EN UN GRAFO)
 ***Autor: Jhosimar George Arias Figueroa
 ****************************************************/

/* Ejemplo de ingreso
8 8

.......I
.#######
.#......
.#.S...S
.###.#.#
.#...#.#
.#.###.#
........

*/

#include<cstdio>
#include <cstring>
#include <queue>
using namespace std;
#define MAX 100 //máximo número de filas y columnas del laberinto

char ady[ MAX ][ MAX ];   //laberinto
bool visitado[ MAX ][ MAX ]; //arreglo de estados visitados
int dx[ 4 ] = {0, 0, 1, -1 };  //incremento en coordenada x
int dy[ 4 ] = {1, -1, 0, 0 };  //incremento en coordanada y
int h , w;                  //altura y ancho del laberinto

struct Estado{
    int x;  // Fila del estado
    int y;  // Columna del estado
    int d;  // Distancia del estado
    Estado(int x1 , int y1 , int d1) : x(x1), y(y1), d(d1){}  // Constructor
    Estado(){}
};

Estado prev[ MAX ][ MAX ];     //Arreglo para mostrar la ruta que se siguio

//Funcion para imprimir la ruta encontrada
//Ingresan las coordenadas del nodo final
void print( int x , int y ){
    //El arreglo prev posee las coordenadas del nodo anterior, por ello empezamos desde el final
    //El proceso termina al momento de preguntar por el anterior del nodo inicial, como pusimos -1
    //Preguntamos hasta que nuestro anterior sea diferente de -1
    for( int i = x , j = y  ; prev[ i ][ j ].d != -1 ; i = prev[ x ][ y ].x , j = prev[ x ][ y ].y ){
        ady[ i ][ j ] = '*'; x = i; y = j;
    }

    printf("Camino con menor numero de pasos\n" );
    for( int i = 0 ; i < h ; ++i ){
        for( int j = 0 ; j < w ; ++j ){
            printf("%c" , ady[ i ][ j ] );
        }
        printf("\n");
    }
}

int BFS( int x , int y , int h , int w ){   //coordenadas de inicial "I" y dimensiones de laberinto

    Estado inicial( x , y , 0 ) ; //Estado inicial, distancia = 0
    queue<Estado> Q;   //Cola de todos los posibles Estados por los que se pase para llegar al destino
    Q.push( inicial ); //Insertamos el estado inicial en la Cola.
    memset( visitado , false , sizeof( visitado ) ); //marcamos como no visitado

    prev[ x ][ y ] = Estado( -1 , -1 , -1 );  //el inicial no tiene una ruta anterior puesto que es el primero

    while( !Q.empty() ){                  //Mientras cola no este vacia
       Estado actual = Q.front();         //Obtengo de la cola el estado actual, en un comienzo será el inicial
       Q.pop();                           //Saco el elemento de la cola
       if( ady[actual.x][actual.y]== 'S'){//Si se llego al destino (punto final)
         print( actual.x , actual.y );    //imprimo la ruta del camino mas corto
         return actual.d;                 //Retornamos distancia recorrida hasta ese momento
       }
       visitado[actual.x][actual.y]=true; //Marco como visitado dicho estado para no volver a recorrerlo
       for( int i = 0; i < 4; ++i ){      //Recorremos hasta 4 porque tenemos 4 posibles adyacentes
          int nx = dx[ i ] + actual.x;    //nx y ny tendran la coordenada adyacente
          int ny = dy[ i ] + actual.y;    //ejemplo en i=0 y actual (3,4) -> 3+dx[0]=3+0=3, 4+dy[0]=4+1=5, nueva coordenada (3,5)
          //aqui comprobamos que la coordenada adyacente no sobrepase las dimensiones del laberinto
          //ademas comprobamos que no sea pared "#" y no este visitado
          if( nx >= 0 && nx < h && ny >= 0 && ny < w && ady[nx][ny] != '#' && !visitado[nx][ny] ){
             Estado adyacente( nx , ny , actual.d + 1 );  //Creamos estado adyacente aumento en 1 la distancia recorrida
             Q.push( adyacente );                     //Agregamos adyacente a la cola
             prev[ nx ][ ny ] = actual;               //El previo del nuevo nodo es el actual.
          }
       }
    }
    return -1;
}


int main(){
    int x , y;
    puts("Ingrese altura del laberinto: ");
    scanf("%d" , &h );

    puts("Ingrese ancho del laberinto: ");
    scanf("%d" , &w );
    printf("\nIngrese el laberinto, con un solo valor inicial I, valor final sera S: \n");
    for( int i = 0 ; i < h ; ++i ){
        for( int j = 0 ; j < w ; ++j ){
            scanf(" %c" , &ady[ i ][ j ] );
            if( ady[ i ][ j ] == 'I' ){  //obtengo coordenada de valor inicial
               x = i; y = j;
            }
        }
    }

    /*
    //MOSTRAMOS LABERINTO
    for( int i = 0 ; i < h ; ++i ){
       for( int j = 0 ; j < w ; ++j ){
         printf("%c" , ady[ i ][ j ] );
       }
       printf("\n");
    }*/
    int min = BFS( x , y , h , w );
    if( min != -1 ) printf("Menor numero de pasos: %d\n" , min );
    else puts("No se pudo llegar al destino");

    return 0;
}
