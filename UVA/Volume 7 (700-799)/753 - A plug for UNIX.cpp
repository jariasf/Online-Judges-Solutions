/*****************************************
 ***Problema: A plug for UNIX
 ***ID: 753
 ***Juez: UVA
 ***Tipo: Graph Theory, Max Flow
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <stdlib.h>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <numeric>
#include <utility>
#include <deque>
#include <stack>
#include <bitset>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <queue>
#include <limits>
#include <fstream>
#include <list>
#include <sstream>
#include <iostream>
#include <iomanip>

using namespace std;
#define INF 1<<30

#define MAX 705
char plug[ MAX ][ 25 ] , plugOnly[ MAX ][ 25 ];
int num_plug;
struct Edge{
    int u;
    int v;
    int c;
    int r;
    Edge( int uu, int vv, int cc, int rr): u(uu), v(vv), c(cc), r(rr){}
};

vector< Edge > E;
vector< vector<int> > ady; //posee indices de aristas

int maxflow( int source , int sink ){

    for( int f = 0; ;){
        ///vector de enlaces previos para ver la ruta recorrida del argumenting path
        ///tiene indices de aristas
        vector<int> prev( ady.size() , -1 );
        queue<int> Q;
        Q.push( source );

        while( !Q.empty() ){
            int u = Q.front(); Q.pop();
            for( int i = 0 ; i < ady[ u ].size(); ++i ){
                 ///indice de arista actual
                 int e = ady[ u ][ i ];
                 int v = E[ e ].v;
                 ///si no puede pasar o si ya fue visitado
                 if( E[ e ].c == 0 || prev[ v ] >= 0 )continue;
                 Q.push( v );
                 prev[ v ] = e;
            }
        }
        ///si ya no hay argumenting paths
        if( prev[ sink ] < 0 )return f;
        ///hallamos minima capacidad de argumentin path
        int c = 0x7fffffff;
        for( int x = sink ; x != source ; x = E[ prev[ x ] ].u ){
            c <?= E[ prev[ x ] ].c;
        }
        ///para nodos de ida 1->2 restamos capacidad minima
        ///para nodos de vuevla 2<-1 sumamos capacidad minima
        for( int x = sink ; x != source ; x = E[ prev[ x ] ].u ){
            E[ prev[ x ] ].c -= c;
            E[ E[ prev[ x ] ].r ].c += c;
        }
        f += c;

    }

}

///indices de aristas comienzan x cero
///si tengo 1->2 su indice es 0, si 1<-2 su indice es 1
///x tanto r de primero es 1, de segundo es 0

void add( int u , int v , int c , bool dirigido = true ){
    Edge e1( u , v , c , E.size() + 1 );
    ady[ u ].push_back( E.size() );
    E.push_back( e1 );
    ///capacidad 0 si es dirigido
    Edge e2( v , u , ( dirigido )? 0 : c , E.size() - 1 );
    ady[ v ].push_back( E.size() );
    E.push_back( e2 );
}

int getId( char *s){

    for( int i = 1 ; i < num_plug ; ++i ) if( strcmp( s , plug[ i ] ) == 0 ) return i;

    strcpy( plug[ num_plug ] , s );
    return num_plug++;

}
int main(){
    int t , n , m , k;
    char u[ 25 ] , v[ 25 ];
    scanf("%d" ,&t );
    for( int q = 0 ; q < t ; ++q ){
        if( q )putchar('\n');
        E.clear();
        ady = vector< vector< int > > ( MAX  , vector<int>() );
        scanf("%d" , &n);
        for( int i = 1 ; i <= n ; ++i ){
            scanf("%s" ,&plug[ i ] );

        }
        num_plug = n + 1;
        scanf("%d" , &m );
        for( int i = 0 ; i < m ; ++i ){
            scanf("%s %s", &u , &v );
            int uu = getId( u );
            add( 0 , uu , 1  );
            add( uu , getId( v ) , 1 );
        }

        scanf("%d" , &k );

        while( k-- ){

            scanf("%s %s" , &u , &v );
            add( getId( u ) , getId( v ) , INF );
        }

        for( int i = 1 ; i <= n ; ++i ){
            add( getId( plug[ i ] ) , MAX - 1 , 1 );
        }
        int flow = maxflow( 0 , MAX - 1 );
        printf("%d\n" , m - flow );
    }
    return 0;
}
