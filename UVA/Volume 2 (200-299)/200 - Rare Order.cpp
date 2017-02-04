/*****************************************
 ***Problema: Rare Order
 ***ID: 200
 ***Juez: UVA
 ***Tipo: Graph Theory, Topological Sort
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <algorithm>
#include <sstream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 35
int used[ MAX ];
///reglas representadas con entero a < b -> [ 0 ][ 1 ] = true
int inDegree[MAX];

vector <int> ady[ MAX];
char let[ MAX ];
int idx;
char output[ MAX + 5 ];

void TopologicalSort(){
    queue <int> Q;

    for ( int i = 0; let[ i ] ; ++i ) {
        if ( inDegree [ let[ i ] -'A' ] == 0 )
            Q.push ( let[ i ] -'A' );
    }

    vector <int> sortedList;

    while ( !Q.empty () ) {
        int pop = Q.front ();
        Q.pop ();

        sortedList.push_back (pop);
        //para adyacentes de nodo actual
        for ( unsigned int i = 0; i < ady[pop].size (); ++i ) {
            //reducimos grado de adyacentes luego de haber eliminado nodo q los apuntaba
            inDegree [ ady[ pop ] [ i ] ]--;
            if ( inDegree [ ady[ pop ] [ i ] ] == 0 )
                Q.push ( ady[ pop ][ i ]);
        }
    }

    for ( int i = sortedList.size() - 1 ; i >= 0 ; --i )
        printf("%c",sortedList[ i ] + 'A' );
    printf("\n");
}

int main(){

    char s[ MAX ], line[ MAX ];

    memset( used, 0, sizeof( used ) );
    memset (inDegree, 0, sizeof( inDegree) );
    scanf("%s", s );

    if( !strcmp( s, "#") )return 0;

    for( int i = 0 ; s[ i ] ; ++i )
             used[ s[ i ] - 'A' ] = 1;


    while( scanf("%s", line) && strcmp( line, "#") ){

        for( int i = 0 ; s[ i ] && line[ i ] ; ++i ){
             used[ line[ i ] - 'A' ] = 1;
             if( s[ i ] != line[ i ]){
                 ady[ line[ i ] -'A' ].push_back( s[ i ] -'A');
                 inDegree[ s[ i ] - 'A' ]++;
                 break;
             }
        }
        strcpy( s , line );
    }

    idx = 0;
    for( int i = 0 ; i < MAX ; ++i )
         if( used[ i ] ) { let[ idx ] = i + 'A' ; used[ idx++ ] = 0;}

    TopologicalSort();
    return 0;
}
