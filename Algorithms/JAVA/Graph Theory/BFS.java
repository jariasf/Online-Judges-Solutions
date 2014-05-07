/*****************************************
 ***Algoritmo: Breadth First Search( BFS )
 ***Tipo: Graph Theory
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

/*
Vertices son numerados entre 1 y V
Ejemplo de ingreso:

22 21

1 2
1 3
1 4
2 5
2 6
5 11
11 18
11 19
11 20
3 7
3 8
7 12
7 13
8 14
4 9
4 10
10 15
10 16
10 17
17 21
17 22
*/

import java.util.*;

public class BFS {
	static final int MAX = 500;
	static int ady[][] = new int[ MAX ][ MAX ];     //matriz de adyacencia
	static Scanner sc = new Scanner( System.in );
	static int V, prev[] = new int[ MAX ];

	public static void bfs(){
		int ini , fin , pasos = 0, max = 0, actual;
		boolean visitado[ ] = new boolean[ MAX ];
		Arrays.fill( visitado , false );
		System.out.println("Nodo raiz: ");
		ini = sc.nextInt();
		System.out.println("Nodo final: ");
		fin = sc.nextInt();		
		prev[ ini ] = -1;
		visitado[ ini ] = true;
		Queue<Integer> Q = new LinkedList<Integer>();
		Q.add( ini );
		while( !Q.isEmpty() ){
			max = Math.max( max , Q.size() );				//ver memoria usada en cola
			actual = Q.remove();
			pasos++;										//numero de vertices que estoy visitando
			if( actual == fin )break;						//si se llego al destino
			for( int i = 1 ; i <= V ; ++i ){	    	        //vemos adyacentes a nodo actual
				int v = ady[ actual ][ i ];
				if( v != 0 && !visitado[ i ] ){				//no visitado agregamos a cola
					System.out.println( actual +" -> "+ i); //vemos recorrido de todo BFS
					prev[ i ] = actual;						//para ver recorrido mas corto de nodo inicio a fin
					visitado[ i ] = true;
					Q.add( i );
				}
			}
		}
		System.out.println("Memoria maxima: " + max );
		System.out.println("Nro Pasos: " + pasos);
		PrintRecorrido( ini , fin );
	}
	
	//Imprimimos recorrido para llegar de nodo ini a fin
	static void PrintRecorrido( int ini , int fin ){

		System.out.println("Recorrido de nodos para llegar de nodo "+ini+" a " +fin);
		List<Integer> path = new ArrayList<Integer>();

		for( ;; ){
			path.add( fin );
			if( prev[ fin ] == -1 )break;
			fin = prev[ fin ];
		}

		for( int i = path.size() - 1 , k = 0 ; i >= 0 ; --i ){
			if( k != 0 ) System.out.print( "->");
			System.out.print( path.get( i ) );
			k = 1;
		}
		System.out.println();
	}
	
	public static void main( String args[] ){
		int E , u , v;
		V = sc.nextInt();   //Numero de vertices
		E = sc.nextInt();	//Numero de aristas

		for( int i = 0 ; i < E ; ++i ){
			u = sc.nextInt(); v = sc.nextInt(); //enlace origen - destino
			ady[ u ][ v ] = 1;
		}
		bfs();
	}
}
