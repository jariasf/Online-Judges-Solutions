/*****************************************
 ***Problema: Come and Go
 ***ID: 11838
 ***Juez: UVA
 ***Tipo: Graph Theory, Strongly Connected Components
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

//COMPONENTES FUERTEMENTE CONEXAS: TARJAN
#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

#define MAX_V 2005

vector<int> L[ MAX_V ];
int V , dfsPos , dfsNum[MAX_V] , lowlink[ MAX_V ] , num_scc , scc[MAX_V ];
bool in_stack[ MAX_V ];
stack<int> S;

void tarjan( int v ){
    dfsNum[ v ] = lowlink[ v ] = dfsPos++;
    S.push( v ); in_stack[ v ] = true;
    for( int i = L[ v ].size() - 1 ; i >= 0 ; --i ){
        int w = L[ v ][ i ];
        if( dfsNum[ w ] == -1){
            tarjan( w );
            lowlink[ v ] = min( lowlink[ v ] , lowlink[ w ] );
        }else if( in_stack[ w ] ) lowlink[ v ] = min( lowlink[ v ] , lowlink[ w ] );

    }
    if( dfsNum[ v ] == lowlink[ v ] ){
        int aux;

        do{
            aux = S.top(); S.pop();
            scc[ aux ] = num_scc;
            in_stack[ aux ] = false;
        }while( aux != v );

        ++num_scc;
    }
}

void build_scc(){
    memset( dfsNum , -1 , sizeof( dfsNum ) );
    memset( in_stack , false , sizeof( in_stack ) );
    dfsPos = num_scc = 0;

    for(int i = 0; i < V ; ++i )
        if( dfsNum[ i ] == -1 )
            tarjan( i );
}

int main(){
    int E,u,v, state;
    bool in[MAX_V];

    while( scanf("%d %d" , &V , &E ) && V|E ){

        for(int i = 0; i < V ; ++i ) L[ i ].clear();

        for(int i = 0; i < E ; ++i ){
            scanf("%d %d %d" , &u , &v , &state );
            --u; --v;
            L[ u ].push_back( v );
            if( state == 2 ) L[ v ].push_back( u );
        }

        build_scc();

        if( num_scc != 1 )puts("0");
        else puts("1");
    }
}
