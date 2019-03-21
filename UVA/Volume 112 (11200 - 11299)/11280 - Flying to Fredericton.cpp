/*****************************************
 ***Problema: Flying to Fredericton
 ***ID: 11280
 ***Juez: UVA
 ***Tipo: Floyd Warshall | Bellman Ford
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <cstring>
#include <queue>
using namespace std;
#define MAX 105
#define pii pair< int , int >
#define mp make_pair
#define pb push_back
#define INF 1<<30
int V , numcities;
char s[ 25 ] , s1[ 25 ];
char cities[ MAX ][ 25 ];
int get_Id( char *s ){
    for( int i = 0 ; i < numcities ; ++i ){
        if( strcmp( s , cities[ i ] ) == 0 ) return i;
    }
    strcpy( cities[ numcities ] ,s );
    return numcities++;
}

int ady[ MAX ][ MAX ], dist[ MAX ][ MAX ];

struct Node{
    int x , steps;
    Node( int xx , int s ): x( xx ) , steps( s ){}
};

void solve(){
    int i , j , u , v , w , k;
    for( i = 0 ; i < V ; ++i )
        for( j = 0 ; j <= V ; ++j ){
            if( !i ) dist[ i ][ j ] = 0;
            else dist[ i ][ j ] = INF;
        }

    queue< Node > Q;
    Q.push( Node( 0 , 0 ) );
    while( !Q.empty() ){
        Node act = Q.front(); Q.pop();
        u = act.x;
        k = act.steps;
        for( v = 0 ; v < V ; ++v ){
            w = ady[ u ][ v ];
            if( w != INF ){
                if( dist[ v ][ k + 1 ] > dist[ u ][ k ] + w && k + 1 <= V ){
                    dist[ v ][ k + 1 ] = dist[ u ][ k ] + w;
                    Q.push( Node( v , k + 1 ) );
                }
            }
        }
    }
}

int main(){
    int t , q , i , u , v , w , j , E , Q , k;
    scanf("%d" , &t );

    for( q = 1 ; q <= t ; ++q ){
        if( q - 1 ) printf("\n" );

        scanf("%d" , &V );
        numcities = 0;
        for( i = 0 ; i < V && scanf("%s" , &s ) ; ++i ) get_Id( s );

        for( i = 0 ; i < V ; ++i )
            for( j = 0 ; j < V ; ++j )
                ady[ i ][ j ] = INF;

        scanf("%d" , &E );
        while( E-- > 0 && scanf("%s %s %d" , &s ,&s1 , &w ) ){
            u = get_Id( s );
            v = get_Id( s1 );
            ady[ u ][ v ] = min( ady[ u ][ v ] , w );
        }

        printf("Scenario #%d\n" , q );

        solve();
        scanf("%d" , &Q );
        while( Q-- > 0 && scanf("%d" , &k ) ){
            if( k < 0 ) k = 0;
            if( k > V ) k = V - 1;
            u = INF;
            for( i = 1 ; i <= k + 1 ; ++i ) u = min( u , dist[ V - 1 ][ i ] );
            if( u == INF )puts("No satisfactory flights");
            else printf("Total cost of flight(s) is $%d\n" , u );
        }
    }

    return 0;
}
