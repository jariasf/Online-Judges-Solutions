/*************************************************
 ***Problema: Sorting Slides
 ***ID: 663
 ***Juez: UVA
 ***Tipo: Graph Theory, Maximum bipartite matching
 ***Autor: Jhosimar George Arias Figueroa
 *************************************************/

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
#define M 128
#define N 10005

bool graph[M][N];
bool seen[N];
int matchL[M], matchR[N];
int n, m;

bool bpm( int u )
{
    for( int v = 0; v < m; v++ ) if( graph[u][v] )
    {
        if( seen[v] ) continue;
        seen[v] = true;
        if( matchR[v] < 0 || bpm( matchR[v] ) )
        {
            matchL[u] = v;
            matchR[v] = u;
            return true;
        }
    }
    return false;
}

struct Rect{
    int xmin , xmax , ymin , ymax;
    Rect( int x , int xx ,int y , int yy ): xmin(x), xmax(xx), ymin(y), ymax(yy){}
};

struct Point{
    int x, y;
    Point( int xx , int yy ): x(xx), y(yy){}
};

bool insideRect(Point p,Point L, Point R){
    if(p.x<=R.x && L.x<=p.x && p.y<=R.y && L.y<=p.y){
       return true;
    }
    return false;
}

bool correct;
bool cycle;
void dfs( int x , int origen ){

    seen[ x ] = 1 ;

    for( int i = 0 ; i < m ; ++i ){
        if( graph[ x ][ i ] ){
            if( i == origen ){ cycle = true; return;}

            if( !seen[ i ] ){
                dfs( i , origen );
            }
            if( cycle ) return;
        }
    }

}


int main(){

    int V, xmin , xmax, ymin , ymax, x ,y, t = 1;

    while( scanf("%d" , &V) && V ){
        vector<Rect> r;
        vector<Point> p;
        ///letras
        for( int i = 0 ; i < V ; ++i ){

            scanf("%d %d %d %d",&xmin ,&xmax, &ymin, &ymax );
            r.push_back( Rect( xmin, xmax , ymin , ymax ) );
        }
        ///numeros
        for( int i = 0 ; i < V ; ++i ){
            scanf("%d %d", &x, &y );
            p.push_back( Point( x , y ) );
        }
        m = V * 2;
        n = 0;
        ///formamos grafo para cada slide unimos con cada numero posible
        for( int i = 0 ; i < V ; ++i ){
            for( int j = 0 ; j < V ; ++j ){
                ///verificamos si el numero actual esta dentro del rectangulo y creamos enlace
                if( insideRect( p[ j ] , Point(r[ i ].xmin , r[ i ].ymin ) , Point( r[ i ].xmax , r[ i ].ymax) ) ){
                    graph[ i ][ j + V ] = 1;
                    n++;
                }
            }
        }


        memset( matchL, -1, sizeof( matchL ) );
        memset( matchR, -1, sizeof( matchR ) );
        int cnt = 0;
  
        for( int i = 0; i < m; i++ ){
            memset( seen, 0, sizeof( seen ) );
            if( bpm( i ) ) cnt++;
        }

        correct = false;
        bool first = true;
        printf("Heap %d\n", t++ );
        if( cnt == V ){

 
            for( int i = 0 ; i < V ;++i ){
                 graph[ i ][ matchL[ i ] ] = 0;
                 graph[ matchL[ i ] ] [ i ]  = 1;
            }

            ///Recorremos con dfs y vemos posible ciclos

            for( int i = 0 ; i < V ;++i ){
                 memset( seen, 0, sizeof( seen ) );
                 cycle = false;
                 dfs( i , i );
                 if( !cycle ){
                     correct = true;
                     if( !first ) printf(" ");
                     printf("(%c,%d)", i + 'A' , matchL[ i ] - V + 1 );
                     first = false;
                 }

            }
        }

        if( !correct )printf("none");

        printf("\n\n");
        memset( graph, 0 ,sizeof( graph ) );
    }

    return 0;
}
