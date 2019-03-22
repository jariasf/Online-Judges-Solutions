/*****************************************
 ***Problema: Full Tank
 ***ID: 11367
 ***Juez: UVA
 ***Tipo: Dijkstra
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/


#include <cstring>
#include <queue>
#include <stdio.h>
using namespace std;
#define MAX 1005
#define MAXC 105
#define INF 1<<30
int V , cost[ MAX ];
struct Edge{
    int v , w;
    Edge( int vv , int ww ) : v( vv ) , w( ww ){}
};

vector< Edge > ady[ MAX ];
struct Node{
    int x , d , c;
    Node( int xx , int dd ): x( xx ) , d( dd ){}
    Node( int xx , int dd , int cc ): x( xx ) , d( dd ) , c( cc ){}
};

struct cmp{
    bool operator() ( const Node &n1 , Node &n2 ){
        return n1.d > n2.d;
    }
};

int dist[ MAX ][ MAXC ];

void dijkstra( int fuel , int source , int end ){
    int i , j , u , v , w , c , k , ans = INF;
    priority_queue< Node , vector< Node > , cmp > Q;

    for( i = 0 ; i <= V ; ++i )
        for( j = 0 ; j <= MAXC ; ++j )
            dist[ i ][ j ] = INF;

    Q.push( Node( source , 0 , 0 ) );
    dist[ source ][ 0 ] = 0;
    while( !Q.empty() ){
        Node act = Q.top(); Q.pop();
        u = act.x;
        //printf("%d %d\n" , u , act.d );
        if( u == end ){ ans = act.d; break; }
        c = act.c;
        //recargo
        if( c + 1 <= fuel && dist[ u ][ c + 1 ] > cost[ u ] + dist[ u ][ c ] ){
            dist[ u ][ c + 1 ] = cost[ u ] + dist[ u ][ c ];
            Q.push( Node( u , dist[ u ][ c + 1 ] , c + 1 ) );
        }

        //simplemente recorro
        for( i = 0 ; i < ady[ u ].size() ; ++i ){
            v = ady[ u ][ i ].v;
            w = ady[ u ][ i ].w;
            if( c >= w && dist[ v ][ c - w ] > dist[ u ][ c ] ){
                dist[ v ][ c - w ] = dist[ u ][ c ];
                Q.push( Node( v , dist[ v ][ c - w ] , c - w ) );
            }
        }
    }
    if( ans == INF ) puts( "impossible");
    else printf("%d\n" , ans );
}

int main(){
    int E , i , u , v , w , Q , c , source , end , ans;
    scanf("%d %d" , &V , &E );
    for( i = 0 ; i < V && scanf("%d" , &cost[ i ] ) == 1  ; ++i );
    while( E-- > 0 && scanf("%d %d %d" , &u , &v , &w ) == 3 ){
        ady[ u ].push_back( Edge( v , w ) );
        ady[ v ].push_back( Edge( u , w ) );
    }
    scanf("%d" , &Q );
    while( Q-- > 0 && scanf("%d %d %d" , &c , &source , &end ) == 3 ){
        dijkstra( c , source , end );
    }
    return 0;
}
