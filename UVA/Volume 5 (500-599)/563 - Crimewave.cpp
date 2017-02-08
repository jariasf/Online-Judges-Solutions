/*****************************************
 ***Problema: Crimewave
 ***ID: 563
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
#include <climits>
#include <fstream>
#include <list>
#include <sstream>
#include <iostream>
#include <iomanip>

using namespace std;

struct Edge{
    int u , v , c , r;
    Edge( int uu , int vv ,int cc ,int rr): u( uu ) , v( vv ) , c( cc ) , r( rr ){}
};
vector<Edge> E;
vector<vector<int> > ady;

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
            c = min( c , E[ prev[ x ] ].c );//c <?= E[ prev[ x ] ].c;
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
void add( int u , int v , int c , bool directed = true ){
    Edge e( u , v , c , E.size() + 1 );
    ady[ u ].push_back( E.size() );
    E.push_back( e );
    Edge e1( v , u , (directed)? 0 : c , E.size() - 1 );
    ady[ v ].push_back( E.size() );
    E.push_back( e1 );
}

int f , c, b;
int in( int u ){ return 2 * u;}
int out( int u ){ return 2 * u + 1;}
int getId( int x , int y ){ return x * c + y;}

int dx[ 4 ] = { 0 ,  0 , 1 , -1 };
int dy[ 4 ] = { 1 , -1 , 0 ,  0 };

int main(){
    int t , x , y, source , sink , V;
    scanf("%d" ,&t );

    while( t-- ){

        scanf("%d %d %d" , &f , &c , &b );
        V = ( f * c + 1 ) * 2 + 5;
        E.clear();
        ady = vector< vector<int> >( V , vector<int> () );

        source = f * c; sink = source + 1;
        for( int i = 0 ; i < b ; ++i ){
             scanf("%d %d" , &x ,&y );
             x--; y--;
             add( out( getId( x , y ) ) , in( sink ) , 1 );
        }
        ///unimos con los 4 adyacentes
        for( int i = 0 ; i < f ; ++i ){
            for( int j = 0 ; j < c ; ++j ){

                //nodos en el borde
                if( i == 0 || i == f - 1 || j == 0 || j == c - 1 ){
                    add( out( source ) , in( getId( i , j ) ) , 1 );
                }
                for( int k = 0 ; k < 4 ; ++k ){
                    int nx = i + dx[ k ];
                    int ny = j + dy[ k ];
                    if( nx >= 0 && nx < f && ny >= 0 && ny < c ){
                        add( out( getId( i , j ) ) , in( getId( nx , ny ) ) , 1 );
                    }
                }
                add( in( getId( i , j ) ) , out( getId( i , j ) ) , 1 );
            }
        }
        add( in( source ) , out( source ) , INT_MAX/2 );
        add( in( sink ) , out( sink ) , INT_MAX/2 );
        int f = maxflow( in( source ) , out( sink ) );

        if( f == b )printf("possible\n");
        else printf("not possible\n");


    }

    return 0;
}
