/*****************************************
 ***Problema: Babel
 ***ID: 11492
 ***Juez: UVA
 ***Tipo: Dijkstra + representacion listas de aristas
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <cstring>
#include <cstdio>
#include <string>
#include <sstream>
#include <queue>
#include <map>
using namespace std;
//veremos x aristas ( caracter inicial , distancia total , vertice destino , id )
#define MAXN 55
#define MAX 20005
struct Edge{
    int d, destino , id;
    char ini;
    Edge( char c , int dd , int des ): ini( c ) , d( dd ) , destino( des ){}
    Edge( char c , int dd , int des , int i ): ini( c ) , d( dd ) , destino( des ) , id( i ){}
    Edge(){}
};
vector< Edge > ady[ 2 * MAX ];  //lista de aristas
char u[ MAXN ], v[ MAXN ] , w[ MAXN ];
int V;

struct cmp{
    bool operator() ( const Edge &e1 , const Edge &e2 ){
        return e1.d > e2.d;
    }
};
bool seen[ MAX ];
void dijkstra(){

    memset( seen , 0 , sizeof( seen ) );
    priority_queue< Edge , vector<Edge> , cmp > Q;
    for( int i = 0 ; i < ady[ 0 ].size() ; ++i ){
        Q.push( ady[ 0 ][ i ] );
        seen[ ady[ 0 ][ i ].id ] = 1;
    }
    int ans = 1<<30;
    while( !Q.empty() ){
        Edge e = Q.top(); Q.pop();
        if( e.destino == 1 ){   //si llegue a mi destino
            ans = min( ans , e.d );
            break;
        }
        for( int i = 0 ; i < ady[ e.destino ].size() ; ++i ){
            Edge aux = ady[ e.destino ][ i ];
            if( !seen[ aux.id ] && e.ini != aux.ini ){
                aux.d += e.d;
                seen[ aux.id ] = 1;
                Q.push( aux );
            }
        }
    }
    if( ans == 1<<30 ) puts("impossivel");
    else printf("%d\n" , ans );
}


int main(){
    int E;
    bool b;
    while( scanf("%d" , &E ) , E ){
        map< string , int > mp; //mapeamos entrada
        scanf("%s %s" , &u , &v );
        for( int i = 0 ; i <= V ; ++i ) ady[ i ].clear();
        b = false;
        if( strcmp( u , v ) == 0 ){
            b = true;
        }
        mp[ u ] = 0;
        mp[ v ] = 1;
        V = 2;
        for( int i = 0 ; i < E ; ++i ){
            scanf("%s %s %s" , &u , &v , &w );
            if( mp.count( u ) == 0 ) mp[ u ] = V++;
            if( mp.count( v ) == 0 ) mp[ v ] = V++;
            if( mp.count( w ) == 0 ) mp[ w ] = V++;
            ady[ mp[ u ] ].push_back( Edge( w[ 0 ] , strlen( w ) , mp[ v ] , i ) );
            ady[ mp[ v ] ].push_back( Edge( w[ 0 ] , strlen( w ) , mp[ u ] , i ) );
        }
        if( b ){
            puts("0");
            continue;
        }
        dijkstra();
    }
    return 0;
}
