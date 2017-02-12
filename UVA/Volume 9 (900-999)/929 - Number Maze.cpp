/*****************************************
 ***Problema: Number Maze
 ***ID: 929
 ***Juez: UVA
 ***Tipo: Dijkstra
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <cstring>
#include <queue>
using namespace std;
#define MAX 1005
#define INF 1<<30
int h , w , ady[ MAX ][ MAX ] , dx[ 4 ] = { 0 , 0 , 1 , -1 } , dy[ 4 ] = { 1 , -1 , 0 , 0 };

struct Node{
    int x , y, d;
    Node( int xx , int yy , int dd ): x( xx ) , y( yy ) , d( dd ){}
};

struct cmp{
    bool operator()( Node n1 , Node n2 ){
        return n1.d > n2.d;
    }
};

int getId( int x , int y ){ return x * w + y; }
int seen[ MAX ][ MAX ], dist[ MAX * MAX ];
int dijkstra( int xini , int yini ){
    priority_queue< Node , vector< Node > , cmp > Q;
    Q.push( Node( xini , yini , ady[ xini ][ yini ] ) );

    int i , u , v , nx , ny;
    for( i = 0 ; i < w * h ; ++i ) dist[ i ] = INF;
    memset( seen , 0 , sizeof( seen ) );
    seen[ xini ][ yini ] = 1;
    dist[ 0 ] = ady[ xini ][ yini ];

    while( !Q.empty() ){
        Node act = Q.top(); Q.pop();

        u = getId( act.x , act.y );
        if( u == h * w - 1 ) break;
        for( i = 0 ; i < 4 ; ++i ){
            nx = dx[ i ] + act.x;
            ny = dy[ i ] + act.y;
            v = getId( nx , ny );
            if( nx >= 0 && ny >= 0 && nx < h && ny < w && !seen[ nx ][ ny ] && dist[ v ] > dist[ u ] + ady[ nx ][ ny ] ){
                seen[ nx ][ ny ] = 1;
                dist[ v ] = dist[ u ] + ady[ nx ][ ny ];
                Q.push( Node( nx , ny , dist[ getId( nx , ny ) ] ) );
            }
        }
    }
    printf("%d\n" , dist[ getId( h - 1 , w - 1 ) ] );
}

int main(){
    int t , i , j;
    scanf("%d" , &t );
    while( t-- > 0 && scanf("%d %d" , &h , &w ) == 2 ){
        for( i = 0 ; i < h ; ++i )
            for( j = 0 ; j < w && scanf("%d" , &ady[ i ][ j ] ) ; ++j );
        dijkstra( 0 , 0 );
    }
    return 0;
}
