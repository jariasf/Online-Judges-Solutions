/***************************************************
 ***Estructura de Datos: Union-Find ( Disjoint-Sets)
 ***Implementación: Disjoint-Sets Forests
 ***Autor: Jhosimar George Arias Figueroa
 ***************************************************/

/*
INPUT
9 7
2 0
7 0
3 1
1 0
6 4
8 5
4 5
*/
import java.util.*;

public class UnionFind {

	static final int MAX = 10005;  //maximo numero de vértices
	static int padre[] = new int[ MAX ];   //Este arreglo contiene el padre del i-esimo nodo
	static int rango[] = new int[ MAX ];   //profundidad de cada vértice

	//Método de inicialización
	static void MakeSet( int n ){
	    for( int i = 0 ; i < n ; ++i ){
	        padre[ i ] = i;      //Inicialmente el padre de cada vértice es el mismo vértice
	        rango[ i ] = 0;      //Altura o rango de cada vértice es 0
	    }
	}

	//Método para encontrar la raiz del vértice actual X
	static int Find( int x ){
	    if( x == padre[ x ] ){          //Si estoy en la raiz
	        return x;                   //Retorno la raiz
	    }
	    //else return Find( padre[ x ] ); //De otro modo busco el padre del vértice actual, hasta llegar a la raiz.
	    else return padre[ x ] = Find( padre[ x ] ); //Compresion de caminos
	}

	//Método para unir 2 componentes conexas
	static void Union( int x , int y ){
	    int xRoot = Find( x );    //Obtengo la raiz de la componente del vértice X
	    int yRoot = Find( y );    //Obtengo la raiz de la componente del vértice Y
	    padre[ xRoot ] = yRoot;   //Mezclo ambos arboles o conjuntos, actualizando su padre de alguno de ellos como la raiz de otro
	}

	//Método para unir 2 componentes conexas usando sus alturas (rangos)
	static void UnionbyRank( int x , int y ){
	    int xRoot = Find( x );    //Obtengo la raiz de la componente del vértice X
	    int yRoot = Find( y );    //Obtengo la raiz de la componente del vértice Y
	    if( rango[ xRoot ] > rango[ yRoot ] ){ //en este caso la altura de la componente del vértice X es
	                                           //mayor que la altura de la componente del vértice Y.
	        padre[ yRoot ] = xRoot;            //el padre de ambas componentes será el de mayor altura
	    }
	    else{                    //en este caso la altura de la componente del vértice Y es mayor o igual que la de X
	        padre[ xRoot ] = yRoot;            //el padre de ambas componentes será el de mayor altura
	        if( rango[ xRoot ] == rango[ yRoot ] ){ //si poseen la misma altura
	            rango[ yRoot ]++;              //incremento el rango de la nueva raíz
	        }
	    }
	}

	static int root[] = new int[ MAX ]; //tendra las raices de las componentes conexas luego de aplicar el método
	static int numComponentes; //variable para el numero total de componentes conexas
	//Método para obtener el numero de componentes conexas luego de realizar las conexiones respectivas
	static int getNumberConnectedComponents( int n ){
	    numComponentes = 0;
	    for( int i = 0 ; i < n ; ++i ){
	        if( padre[ i ] == i ){    //Si el padre del vértice i es el mismo vértice entonces es raíz
	        //if( Find( i ) == i ){   //podemos usamos find para el mismo proposito y
	                                  //para que se realice compresion de caminos
	            root[ numComponentes++ ] = i;  //almaceno la raiz de cada nueva componente
	           // numComponentes++;
	        }
	    }
	    return numComponentes;
	}

	static int numVertices[] = new int[ MAX ];   //almacenara la cantidad de vértices para la i-esima raiz.
	//Método para obtener la raiz y el numero de vértices de cada componente conexa
	//será necesario primero tener la cantidad de componentes conexas
	//podemos llamar 1ero al metodo getNumberConnectedComponents o incluir porcion de su codigo en este
	static void getNumberNodes( int n ){
	    Arrays.fill( numVertices, 0 );     //inicializo mi contador de vértices
	    for( int i = 0 ; i < n ; ++i ){
	        numVertices[ Find( i ) ]++;    //incremento la raíz del vértice i
	    }
	    for( int i = 0 ; i < numComponentes ; ++i ){
	        System.out.printf("Componente %d: Raiz = %d , Nro nodos = %d.\n" , i + 1 , root[ i ] , numVertices[ root[ i ] ] );
	    }
	}

	//Método que me determina si 2 vértices estan o no en la misma componente conexa
	static boolean sameComponent( int x , int y ){
	    if( Find( x ) == Find( y ) ) return true;   //si poseen la misma raíz
	    return false;
	}

	public static void main(String[] args) {
	    int V , E , origen , destino;

	    Scanner sc = new Scanner( System.in );  
	    V = sc.nextInt(); E = sc.nextInt();    //tengamos numero de vertices y aristas
	    MakeSet( V );                          //inicializamos los conjuntos
	    for( int i = 0 ; i < E ; ++i ){
	        origen = sc.nextInt(); destino = sc.nextInt();
	        UnionbyRank( origen , destino );  //union de elementos
	    }

	    System.out.printf("El numero de componentes conexas es: %d\n" , getNumberConnectedComponents( V ) );
	    getNumberNodes( V );

	}

}
