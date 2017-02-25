/*****************************************
 ***Problema: Adventure of Super Mario
 ***ID: 10269
 ***Juez: UVA
 ***Tipo: Dijkstra + Floyd
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

#define INF 1<<30
#define MAX 200
#define MAXL 105
#define MAXK 14
int A , B , L , K , dist[ MAX ][ MAXK ];
int ady[ MAX ][ MAX ];

void init(){
    int i , j;
    for( i = 0 ; i <= A + B ; ++i ){
        for( j = 0 ; j <= A + B ; ++j ){
            ( i == j ) ? ady[ i ][ j ] = 0 : ady[ i ][ j ] = INF;
        }
    }
}

void Floyd(){
    int i , j , k;
    for( k = 0 ; k < A ; ++k ){
        for( i = 0 ; i < A + B ; ++i ){
            if( ady[ i ][ k ] == INF ) continue;
            for( j = 0 ; j < A + B ; ++j ){
                if( ady[ k ][ j ] != INF && ady[ i ][ k ] + ady[ k ][ j ] < ady[ i ][ j ] ){
                    ady[ i ][ j ] = ady[ i ][ k ] + ady[ k ][ j ];
                }
            }
        }
    }
}

struct Node{
    int x , d , l , k;
    Node( int xx , int dd , int ll , int kk): x( xx ) , d( dd ) , l( ll ), k( kk ){}
};

struct cmp{
    bool operator() ( Node e1 , Node e2 ){
        return e1.d > e2.d;
    }
};

int dijkstra( int inicial ){
    int i , v , w ,  l , k , u , j , c;
    priority_queue< Node , vector< Node >  , cmp > Q;

    for( i = 0 ; i <= A + B ; ++i )
        for( k = 0 ; k <= K ; ++k )
            dist[ i ][ k ] = INF;

    for( k = 0 ; k <= K ; ++k ) dist[ inicial ][ k ] = 0;

    Q.push( Node( inicial , 0 , L , K ) );
    while( !Q.empty() ){
        Node act = Q.top(); Q.pop();
        u = act.x;
        for( v = 0 ; v < A + B ; ++v ){
            w = ady[ u ][ v ];
            l = act.l;
            k = act.k;
            if( ady[ u ][ v ] != INF  ){
                if( dist[ v ][ k ] > dist[ u ][ k ] + w  ){
                    dist[ v ][ k ] = dist[ u ][ k ] + w;
                    Q.push( Node( v , dist[ v ][ k ] , l , k  ) );
                }
                if( k > 0 && l >= w && dist[ v ][ k - 1 ] > dist[ u ][ k ] ){
                    dist[ v ][ k - 1 ] = dist[ u ][ k ];
                    Q.push( Node( v , dist[ v ][ k - 1 ] , l , k - 1 ) );
                }
            }
        }
    }

    int ans = INF;
    for( k = 0 ; k <= K ; ++k ) ans = min( ans , dist[ 0 ][ k ] );

    return ans;
}

int main(){

    int t , E , u , v , w , i;

    scanf( "%d" , &t );

    while( t-- > 0 && scanf("%d %d %d %d %d" , &A , &B , &E , &L , &K ) ){
        init();
        while( E-- > 0 && scanf("%d %d %d" , &u , &v , &w ) ){
            ady[ u - 1 ][ v - 1 ] = ady[ v - 1 ][ u - 1 ] = w;
        }
        Floyd();
        printf("%d\n" , dijkstra( A + B - 1 ) );
    }
    return 0;
}
