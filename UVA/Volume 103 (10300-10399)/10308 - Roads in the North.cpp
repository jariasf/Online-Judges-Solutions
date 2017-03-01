/*****************************************
 ***Problema: Roads in the North
 ***ID: 10308
 ***Juez: UVA
 ***Tipo: Trees, diameter of a tree
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/


#include <stdio.h>
#include <queue>
#include <iostream>

using namespace std;
#define MAX 10005

struct Edge{
    int v, w;
    Edge( int vv , int ww) :v(vv) , w( ww ){}
};
vector<Edge> ady[ MAX ];

struct Estado{
    int nodo, d;
    Estado( int n , int dd ):nodo( n ) , d( dd ){}
};

bool seen[ MAX ];
//primero tiene distancia mas larga y segundo tiene nodo mas largo
pair<int , int > bfs( int x ){
    memset( seen , 0 , sizeof( seen ) );
    queue<Estado> Q;
    Q.push( Estado( x , 0 ) );
    seen[ x ] = true;
    int large = 0, dist = 0;
    while( !Q.empty() ){
        Estado act = Q.front(); Q.pop();

        if( dist < act.d ){
            dist = act.d;
            large = act.nodo;
        }

        for( int i = 0 ; i < ady[ act.nodo ].size(); ++i ){
             Edge e = ady[ act.nodo ][ i ];
             if( !seen[ e.v ] ){
                 seen[ e.v ] = true;
                 Q.push( Estado( e.v , e.w + act.d ) );
             }
        }
    }
    pair<int , int > ans( dist , large );
    return ans;
}

int main(){
    int u , v , w, V, i;
    char line[ 2005];
    while( 1 ){
        V = 0;
        for (i = 0; gets( line ); ) {
            i++;
            if( sscanf( line , "%d %d %d" ,&u ,&v ,&w ) != 3 )break;
            ady[ u ].push_back( Edge( v , w ) );
            ady[ v ].push_back( Edge( u , w ) );
        }
        if( i == 0 )break;
        printf( "%d\n" , bfs( bfs( 1 ).second ).first );
        for( i = 0 ; i < MAX ; ++i )ady[ i ].clear();
    }
    return 0;
}

