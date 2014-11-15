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
#define pii pair<int ,int>
#define mp make_pair
#define pb push_back

int V, x[ MAX ], y[ MAX ], numColor[ MAX ], color[ MAX ];
bool used[ MAX ];
vector<int> ady[ MAX ];
map< pii , int > point;

long long dist( long long x1 , long long y1 , long long x2 , long long y2 ){
	return ( x1 - x2 ) * ( x1 - x2 ) + ( y1 - y2 ) * ( y1 - y2 );
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


void preCalNeighbors(vector<pii> &d){
    for( int i = -5 ; i <= 5 ; ++i ){
        for( int j = -5 ; j <= 5 ; ++j ){
            if( (i|j) && dist( 0, 0 , i , j ) <= 25 ){
                d.pb( mp(i , j));
            }
        }
    }
}

int main(){

    vector<pii> d;
    preCalNeighbors(d);

    while( scanf("%d" , &V ) != EOF ){
        point.clear();
        int idCoord = 0;
        for( int i = 0 ; i < V && scanf("%d %d" , &x[i] , &y[i] ) ; ++i){
            point[ mp( x[i] , y[i] ) ] = i;
            ady[ i ].clear();
        }

        memset( used , 0 , sizeof( used ) );
        for( int i = 0 ; i < V ; ++i ){
            for( int j = 0 ; j < d.size() ; ++j ){
                int nx = x[i] + d[j].first;
                int ny = y[i] + d[j].second;
                if( point.find( mp( nx , ny ) ) != point.end() ){
                    int idPoint = point[ mp( nx , ny ) ];
                    ady[ i ].push_back( idPoint );
                    used[ i ] = used[ idPoint ] = 1;
                }
            }
        }

        int ans = 0;
        memset( color , 0 , sizeof( color ) );
        for( int i = 0 ; i < V ; ++i ){
            if( !used[ i ] || color[ i ] ) continue;
            bfs( i );
            ans += min( numColor[ 1 ] , numColor[ 2 ] );
        }
        printf("%d\n" , ans );

    }
    return 0;
}
