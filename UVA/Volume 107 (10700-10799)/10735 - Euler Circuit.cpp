/**********************************************
 ***Problema: Euler Circuit
 ***ID: 10735
 ***Juez: UVA
 ***Tipo: Graph Theory, max flow, euler circuit
 ***Autor: Jhosimar George Arias Figueroa
 **********************************************/

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

#define MAX 505
struct Edge{
    int u;
    int v;
    int c;
    int r;
    Edge( int uu, int vv, int cc, int rr): u(uu), v(vv), c(cc), r(rr){}
};

vector< Edge > E;
vector< vector<int> > ady; 

int maxflow( int source , int sink ){

    for( int f = 0; ;){
        vector<int> prev( ady.size() , -1 );
        queue<int> Q;
        Q.push( source );

        while( !Q.empty() ){
            int u = Q.front(); Q.pop();
            for( int i = 0 ; i < ady[ u ].size(); ++i ){
                 int e = ady[ u ][ i ];
                 int v = E[ e ].v;
                 if( E[ e ].c == 0 || prev[ v ] >= 0 )continue;
                 Q.push( v );
                 prev[ v ] = e;
            }
        }

        if( prev[ sink ] < 0 )return f;
        int c = 99999999;
        for( int x = sink ; x != source ; x = E[ prev[ x ] ].u ){
            c = std::min( c , E[ prev[ x ] ].c );

        for( int x = sink ; x != source ; x = E[ prev[ x ] ].u ){
            E[ prev[ x ] ].c -= c;
            E[ E[ prev[ x ] ].r ].c += c;
        }
        f += c;

    }

}

void add( int u , int v , int c , bool dirigido = true ){
    Edge e1( u , v , c , E.size() + 1 );
    ady[ u ].push_back( E.size() );
    E.push_back( e1 );
    Edge e2( v , u , ( dirigido )? 0 : c , E.size() - 1 );
    ady[ v ].push_back( E.size() );
    E.push_back( e2 );
}


vector<int> graph[MAX ];
int V;
int m;
void tour(int x)
{
    while ( graph[ x ].size() > 0) {
        int y = graph[ x ].back();
        graph[ x ].pop_back();
        tour( y );
    }
    printf(m++ ? " %d" : "%d", x);
}

int main(){

    int t, A , u , v ;
    char c;
    scanf("%d", &t );
    int degree[ MAX ];
    for( int q = 0 ; q < t ; ++q ){

        if( q )printf("\n");

        scanf("%d %d", &V , &A);
        E.clear();
        ady = vector<vector<int> >( V + A + 3, vector<int>() );
        memset( degree, 0 , sizeof( degree ) );
        int undirected[ A + 1 ];
        memset( undirected, 0 , sizeof( undirected ) );
        for( int i = 0 ; i <= V ;++i) graph[ i ].clear();

        ///auxiliar contiene aristas de grafo normal inicial
        vector<Edge> aux;
        for( int i = 1 ; i <= A ;++i){
            scanf("%d %d %c",&u,&v,&c);
            degree[ u ]++;
            degree[ v ]++;
            add( 0 , i , 1 );
            add( i , A + v , 1 );
            aux.push_back( Edge( u , v , 0 , 0 ) );
            if( c == 'U' ){
                add( i , A + u , 1 );
                undirected[ i ] = 1;
            }else graph[ v ].push_back( u );
        }
        bool possible = true;

        for( int i = 1 ; i <= V ; ++i ){
             if( degree[ i ] & 1 ){
                 possible = false;
                 break;
             }
        }
        if( !possible ){
             printf("No euler circuit exist\n");
             continue;
        }

        ///super source y super sink
        for( int i = 1 ; i <=V ;++i ){
             add( A + i , A + V + 1 , degree[ i ]>>1 );
        }

        ///MAX flow sobre grafo bipartito para hallar la cantidad de matchings
        if( maxflow( 0 , V + A + 1 ) == A ){

             ///armo circuito para imprimir
             for( int i = 1 ; i <= A ;++i ){

                  if( undirected[ i ] ){
                      for( int j = 0; j < ady[ i ].size(); ++j ){
                           if( E[ ady[ i ][ j ] ].c == 0 ){
                               if( aux[ i - 1 ].u != E[ ady[ i ][ j ] ].v - A ){
                                  graph[ E[ ady[ i ][ j ] ].v - A ].push_back( aux[ i - 1].u);
                               }
                               else graph[ E[ ady[ i ][ j ] ].v - A ].push_back( aux[ i -  1].v );
                           }
                      }
                  }
             }

             m = 0;
             ///para q funcione revertir las aristas
             tour( 1 );
             printf("\n");

        }
        else printf("No euler circuit exist\n");

    }
    return 0;
}

/**
Grafo bipartito, Lado izquierdo aristas, Lado derecho vertices
No dirido, arista uno ambos, Dirigo solo al segundo
ejemplo 1 conecciones

1  -> 9 , 11

2  -> 9 , 12

3  -> 10, 12

4  -> 13

5  -> 12

6  -> 12, 13

7  -> 14

8  -> 13 , 14

Ahora creamos super source y super sink, super source con capacidad 1 x rekerir recorrer una arista
super sink con capacidad grado de vertice entre 2

**/

