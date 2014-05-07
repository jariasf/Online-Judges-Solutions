/**********************************************
 ***Algoritmo: Minimum Spanning Tree - Kruskal
 ***Tipo: Teoria de Grafos
 ***Autor: Jhosimar George Arias Figueroa
 *********************************************/
/*
EJEMPLO DE INPUT
9 14
1 2 4
1 8 9
2 3 9
2 8 11
3 4 7
3 9 2
3 6 4
4 5 10
4 6 15
5 6 11
6 7 2
7 8 1
7 9 6
8 9 7

EJEMPLO VERIFICACION DE MST
9 11
1 2 4
1 8 9
2 3 9
2 8 11
3 9 2
7 8 1
7 9 6
8 9 7

4 5 10
4 6 15
5 6 11
*/

import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class Kruskal {

	static final int MAX = 1005;  //maximo numero de vértices

	///UNION-FIND
	static int padre[] = new int[ MAX ];  //Este arreglo contiene el padre del i-esimo nodo

	//Método de inicialización
	static void MakeSet( int n ){
	    for( int i = 1 ; i <= n ; ++i ) padre[ i ] = i;
	}

	//Método para encontrar la raiz del vértice actual X
	static int Find( int x ){
	    return ( x == padre[ x ] ) ? x : ( padre[ x ] = Find( padre[ x ] ) );
	}

	//Método para unir 2 componentes conexas
	static void Union( int x , int y ){
	    padre[ Find( x ) ] = Find( y );
	}

	//Método que me determina si 2 vértices estan o no en la misma componente conexa
	static boolean sameComponent( int x , int y ){
	    if( Find( x ) == Find( y ) ) return true;
	    return false;
	}
	///FIN UNION-FIND

	static int V , E;      //numero de vertices y aristas
	//Estructura arista( edge )
	static class Edge implements Comparator<Edge>{
	    int origen;     //Vértice origen
	    int destino;    //Vértice destino
	    int peso;       //Peso entre el vértice origen y destino
	    Edge(){}
	    //Comparador por peso, me servira al momento de ordenar lo realizara en orden ascendente
	    //Ordenar de forma descendente para obtener el arbol de expansion maxima
		@Override
		public int compare(Edge e1 , Edge e2 ) {
			//return e2.peso - e1.peso; //Arbol de expansion maxima
			return e1.peso - e2.peso;   //Arbol de expansion minima
		}
	};
	
	static Edge arista[] = new Edge[ MAX ];      //Arreglo de aristas para el uso en kruskal
	static Edge MST[] = new Edge[ MAX ];     //Arreglo de aristas del MST encontrado

	static void KruskalMST(){
	    int origen , destino , peso;
	    int total = 0;          //Peso total del MST
	    int numAristas = 0;     //Numero de Aristas del MST
	    
	    MakeSet( V );           //Inicializamos cada componente
	    Arrays.sort( arista , 0 , E , new Edge() );    //Ordenamos las aristas por su comparador

	    for( int i = 0 ; i < E ; ++i ){     //Recorremos las aristas ya ordenadas por peso
	        origen = arista[ i ].origen;    //Vértice origen de la arista actual
	        destino = arista[ i ].destino;  //Vértice destino de la arista actual
	        peso = arista[ i ].peso;        //Peso de la arista actual

	        //Verificamos si estan o no en la misma componente conexa
	        if( !sameComponent( origen , destino ) ){  //Evito ciclos
	            total += peso;              //Incremento el peso total del MST
	            MST[ numAristas++ ] = arista[ i ];  //Agrego al MST la arista actual
	            Union( origen , destino );  //Union de ambas componentes en una sola
	        }
	    }

	    //Si el MST encontrado no posee todos los vértices mostramos mensaje de error
	    //Para saber si contiene o no todos los vértices basta con que el numero
	    //de aristas sea igual al numero de vertices - 1
	    if( V - 1 != numAristas ){
	        System.out.println("No existe MST valido para el grafo ingresado, el grafo debe ser conexo.");
	        return;
	    }
	    System.out.println( "-----El MST encontrado contiene las siguientes aristas-----");
	    for( int i = 0 ; i < numAristas ; ++i )
	        System.out.printf("( %d , %d ) : %d\n" , MST[ i ].origen , MST[ i ].destino , MST[ i ].peso ); //( vertice u , vertice v ) : peso

	    System.out.printf( "El costo minimo de todas las aristas del MST es : %d\n" , total );
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner( System.in );	   //para lectura de datos
		V = sc.nextInt(); E = sc.nextInt();
		
	    //Realizamos el ingreso del grafo, almacenando las aristas en un arreglo con los datos respectivos
	    for( int i = 0 ; i < E ; ++i ){
	        arista[ i ] = new Edge();
	    	arista[ i ].origen = sc.nextInt();
	        arista[ i ].destino = sc.nextInt();
	        arista[ i ].peso = sc.nextInt();
	        //arista[ i ] = new Arista( sc.nextInt() , );
	    }
	    KruskalMST();
	}
}
