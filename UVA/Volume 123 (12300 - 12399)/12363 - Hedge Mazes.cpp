/*****************************************
 ***Problema: Hedge Mazes
 ***ID: 12363
 ***Juez: UVA
 ***Tipo: Bridges
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

///solo va existir un camino de un nodo A a un nodo B de tal forma q visite una vez cada vertice
///Si el camino esta compuesto por bridges, una vez obtenidos los bridges hago union find
///para poner cada nodo en un subgrafo y luego realizar las queries
#include <cstdio>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

#define MAXN 10005
//N vertices, M aristas
int N, counter, seen[MAXN], low[MAXN];
vector<int> adj[MAXN];
vector<int> bridges[ MAXN ];

void dfs(int x, int parent)
{
    int kids = 0, art = 0;
    low[x] = seen[x] = ++counter;

    for (vector<int>::iterator it = adj[x].begin(); it != adj[x].end(); ++it) {
        int y = *it;
        if (y == parent) continue;

        if (seen[y] == 0) {
            dfs(y, x);
            low[x] = min(low[x], low[y]);
            kids++;

            if (low[y] == seen[y]) {
                bridges[ x ].push_back( y );
                bridges[ y ].push_back( x );
            }
        } else {
            low[x] = min(low[x], seen[y]);
        }
    }
}

int uf[ MAXN ];
int Find( int x ){
    return ( uf[ x ] == x ) ? x : uf[ x ] = Find( uf[ x ] );
}
void Union( int x , int y ){
    uf[ Find( x ) ] = Find( y );
}

int component[ MAXN ];
int main()
{
    int i, x, y, M , Q;
    while( scanf("%d %d %d" , &N  , &M , &Q )  , N | M | Q){
        for( int i = 1 ; i <= N ; ++i ) { bridges[ i ].clear(); adj[ i ].clear(); }

        while( M-- ) {
            scanf("%d %d" , &x , &y );
            adj[ x ].push_back( y );
            adj[ y ].push_back( x );
        }

        memset(seen, 0, sizeof(seen));
        counter = 0;
        for (x = 1; x <= N; ++x){
            uf[ x ] = x;
            if ( seen[ x ] == 0 ) dfs( x , -1 );
        }

        //creo subgrafos
        for( int i = 1 ; i <= N ; ++i ){
            for( int j = 0 ; j < bridges[ i ].size() ; ++j ){
                if( Find( i ) != Find( bridges[ i ][ j ] ) ){
                    Union( i , bridges[ i ][ j ] );
                }
            }
        }

        for( int i = 1 ; i <= N ; ++i ){
            component[ i ] = Find( i );
        }

        while( Q-- ){
            scanf("%d %d" , &x , &y );
            //si estan en la misma componente
            if( component[ x ] == component[ y ] ) puts("Y");
            else puts("N");

        }
        puts("-");
    }
}
