/*********************************************
 ***Problema: Gopher II
 ***ID: 10080
 ***Juez: UVA
 ***Tipo: Maximum Bipartite Matching, max flow
 ***Autor: Jhosimar George Arias Figueroa
 ********************************************/

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
struct Point{
    double x, y;
    Point( double xx , double yy ): x(xx), y(yy){}
};

/**
u: nodo origen
v: nodo destino
c: capacidad de nodo u a v
r: indice de arista inversa, ejemplo si arista act 1->2 retorno es 1<-2
**/
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
    ///capadidad 0 si es dirigido
    Edge e2( v , u , ( dirigido )? 0 : c , E.size() - 1 );
    ady[ v ].push_back( E.size() );
    E.push_back( e2 );
}

double d( Point p1, Point p2 ){
    return (p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y);
}

int main(){
    int g, h, s ,u , v , c, dist;
    double x, y;
    while( scanf("%d %d %d %d",&g, &h, &s, &v ) != EOF ){
        E.clear();
        ady = vector< vector<int> > ( g + h + 5 , vector<int>() );
        dist = s * s * v * v;
        vector<Point> p;
        for( int i = 0 ; i < g + h ; ++i ){
             scanf("%lf %lf", &x, &y );
             p.push_back( Point( x , y ) );
        }
        for( int i = 0 ; i < g ; ++i ){
             add( 0 , i + 1 , 1 );

             for( int j = g ; j < g + h ; ++j ){
                  if( d( p[ i ] , p[ j ] ) <= dist ){
                      add( i + 1 , j + 1 , 1 );
                  }
             }
        }

        for( int i = g ; i < g + h ; ++i )add( i + 1 , g + h + 1 , 1 );
        printf("%d\n", g - maxflow( 0 , g + h + 1 ) );


    }

    return 0;
}
