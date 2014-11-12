/*****************************************
 ***Problema: Galaxy collision
 ***Tipo: Graph Theory - Bipartite Coloring
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <map>
#include <vector>
#include <queue>

using namespace std;
#define MAX 50004
int V, x[ MAX ], y[ MAX ], numColor[ MAX ], color[ MAX ];
bool used[ MAX ];
vector<int> ady[ MAX ];
map<int , map< int , int > > point;

long long dist( long long x1 , long long y1 , long long x2 , long long y2 ){
	return ( x1 - x2 ) * ( x1 - x2 ) + ( y1 - y2 ) * ( y1 - y2 );
}

int MIN( int a , int b ){
    if( a == 0 || b == 0 ) return 1;
    return ( a < b )? a : b;
}

int bfs( int origen ){
    memset( numColor , 0 , sizeof( numColor ) );
    queue< int > Q;
    Q.push( origen );
    int act;
    color[ origen ] = 1;
    while( !Q.empty() ){
        act = Q.front(); Q.pop();
        numColor[ color[ act ] ]++;
        for( int i = 0 ; i < ady[ act ].size() ; ++i ){
            if( !color[ ady[ act ][ i ] ] ){
                color[ ady[ act ][ i ] ] = ( color[ act ] + 1 ) % 2;
                if( color[ ady[ act ][ i ] ] == 0 ) color[ ady[ act ][ i ] ] = 2;
                Q.push( ady[ act ][ i ] );
            }
            else if( color[ ady[ act ][ i ] ] == color[ act ] ){
                return -1;
            }
        }
    }
    return 1;
}

int main(){
    while( scanf("%d" , &V ) != EOF ){
        point.clear();
        int idCoord = 0;
        for( int i = 0 ; i < V && scanf("%d %d" , &x[i] , &y[i] ) ; ++i){
            point[ x[i] ][ y[i] ] = i;
        }
        memset( used , 0 , sizeof( used ) );
        for( int i = 0 ; i < V ; ++i ){
            for( int _x = max( 0 ,x[i] - 5)  ; _x <= x[i] + 5 ; ++_x ){
                for( int _y = max( 0 ,y[i] - 5) ; _y <= y[i] + 5 ; ++_y ){
                    if( point[ _x ].find( _y ) != point[ _x ].end() ){
                        int idPoint = point[ _x ][ _y ];
                        if( _x == x[i] && _y == y[i] ||
                            dist( x[i], y[i] , x[ idPoint ] , y[ idPoint ] ) > 25 )
                            continue;
                        ady[ i ].push_back( idPoint );
                        used[ i ] = used[ idPoint ] = 1;
                    }
                }
            }
        }

        int ans = 0;
        memset( color , 0 , sizeof( color ) );
        for( int i = 0 ; i < V ; ++i ){
            if( !used[ i ] || color[ i ] ) continue;
            bfs( i );
            ans += MIN( numColor[ 1 ] , numColor[ 2 ] );
        }
        printf("%d\n" , ans );
        for( int i = 0 ; i < V ; ++i ){
            if( used[ i ])
                ady[ i ].clear();
        }
    }
    return 0;
}
