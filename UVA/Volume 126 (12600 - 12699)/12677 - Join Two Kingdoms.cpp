/*****************************************
 ***Problema: Join Two Kingdoms
 ***ID: 12677
 ***Juez: UVA
 ***Tipo: BFS
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;
#define MAX 40005
int N , Q;
long long dist1[ MAX ] , dist2[ MAX ] , sum[ MAX ];

struct Edge{
    int v, w;
    Edge( int vv , int ww) :v(vv) , w( ww ){}
};
vector<Edge> ady[ MAX ] , ady2[ MAX ];

struct Estado{
    int nodo;
    long long d;
    Estado( int n , int dd ):nodo( n ) , d( dd ){}
};

bool seen[ MAX ];

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

pair<int , int > bfs2( int x ){
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

        for( int i = 0 ; i < ady2[ act.nodo ].size(); ++i ){
             Edge e = ady2[ act.nodo ][ i ];
             if( !seen[ e.v ] ){
                 seen[ e.v ] = true;
                 Q.push( Estado( e.v , e.w + act.d ) );
             }
        }
    }
    pair<int , int > ans( dist , large );
    return ans;
}

void largest1( int x ){
    memset( seen , 0 , sizeof( seen ) );
    queue<Estado> Q;
    Q.push( Estado( x , 0 ) );
    seen[ x ] = true;
    while( !Q.empty() ){
        Estado act = Q.front(); Q.pop();
        for( int i = 0 ; i < ady[ act.nodo ].size(); ++i ){
             Edge e = ady[ act.nodo ][ i ];
             if( !seen[ e.v ] ){
                 seen[ e.v ] = true;
                 dist1[ e.v ] = max( dist1[ e.v ] , e.w + act.d );
                 Q.push( Estado( e.v , e.w + act.d ) );
             }
        }
    }
}

void largest2( int x ){
    memset( seen , 0 , sizeof( seen ) );
    queue<Estado> Q;
    Q.push( Estado( x , 0 ) );
    seen[ x ] = true;
    while( !Q.empty() ){
        Estado act = Q.front(); Q.pop();
        for( int i = 0 ; i < ady2[ act.nodo ].size(); ++i ){
             Edge e = ady2[ act.nodo ][ i ];
             if( !seen[ e.v ] ){
                 seen[ e.v ] = true;
                 dist2[ e.v ] = max( dist2[ e.v ] , e.w + act.d );
                 Q.push( Estado( e.v , e.w + act.d ) );
             }
        }
    }
}


int main(){

    int u , v;
    long long maxDiameter;
    while( scanf("%d %d" , &N , &Q ) != EOF ){
        memset( sum , 0 , sizeof( sum ) );
        memset( dist1 , 0 , sizeof( dist1 ) );
        memset( dist2 , 0 , sizeof( dist2 ) );

        for( int i = 0 ; i < MAX ; ++i ) ady[ i ].clear();
        for( int i = 0 ; i < MAX ; ++i ) ady2[ i ].clear();

        for( int i = 0 ; i < N - 1 && scanf("%d %d" , &u , &v ); ++i ){
            ady[ u - 1 ].push_back( Edge( v - 1 , 1 ) );
            ady[ v - 1 ].push_back( Edge( u - 1 , 1 ) );
        }

        for( int i = 0 ; i < Q - 1 && scanf("%d %d" , &u , &v ); ++i ){
            ady2[ u - 1 ].push_back( Edge( v - 1 , 1 ) );
            ady2[ v - 1 ].push_back( Edge( u - 1 , 1 ) );
        }

        pair< int , int > n1 = bfs( 0 );
        pair< int , int > n2 = bfs( n1.second  );

        pair< int , int > q1 = bfs2( 0 );
        pair< int , int > q2 = bfs2( q1.second  );

        maxDiameter = max( n2.first , q2.first );

        dist1[ n1.second ] = n2.first;
        largest1( n1.second );
        dist1[ n2.second ] = n2.first;
        largest1( n2.second );

        dist2[ q1.second ] = q2.first;
        largest2( q1.second );
        dist2[ q2.second ] = q2.first;
        largest2( q2.second );

        sort( dist2 , dist2 + Q );
        for( int i = 0 ; i < Q ; ++i ){
            dist2[ i ]++;
            if( i )
                sum[ i ] = sum[ i - 1 ] + dist2[ i ];
            else
                sum[ i ] = dist2[ i ];
        }

        long long ans = 0;
        long long denom = (long long)N * Q;
        for( int i = 0 ; i < N ; ++i ){
            long long left = 0 , right = Q, mid , search = maxDiameter - dist1[ i ];
            while( left < right ){
                mid = ( left + right )>>1LL;
                if( dist2[ mid ] < search ){
                    left = mid + 1;
                }
                else
                    right = mid;
            }
            ans += maxDiameter * left + dist1[ i ] * ((long long)Q - left ) + ( sum[ Q - 1 ] - ( (left - 1) >= 0 ? sum[ left - 1 ] :0 ) );
        }

        printf("%.3lf\n" , (double)ans/denom );
    }
    return 0;
}
