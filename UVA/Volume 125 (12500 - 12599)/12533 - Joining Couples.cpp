/*****************************************
 ***Problema: Joining Couples
 ***ID: 12533
 ***Juez: UVA
 ***Tipo: LCA
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/
/*
La idea es remover una arista de cada ciclo en cada componente, de acuerdo a la entrada habra un ciclo x componente
Luego hallamos el LCA en el grafo no dirigido
La respuesta es dado la arista eliminada E =( a , b  ) y el query (u,v) tendremos que tener
Minimo( LCA( u , v ) , LCA( u , a ) + LCA( v , b ) + 1 , LCA( u , b ) + LCA( v , a ) + 1 )
El minimo entre el lca directo y el lca usando la arista eliminada
*/
#include <stdio.h>
#include <cstring>
#include <vector>
using namespace std;

#define MAX 100010
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define pii pair<int , int >
#define MIN( a , b ) ( a < b ) ? a : b

int n, parent[ MAX ] , kparent[ MAX ][ 18 ] , depth[ MAX ], seen[ MAX ], dist[ MAX ];

//Borramos ciclo en cada componente para crear un arbol
bool deletedEdge[ MAX ];
vector< pii > aux[ MAX ]; // para borrar ciclos
int componente[ MAX ];
pii deletedEdgeOfComponent[ MAX ];

void deleteCycle( int x  , int comp , int parent ){
    seen[ x ] = 1;
    int i , v , id;
    componente[ x ] = comp;
    for( i = 0 ; i < aux[ x ].size() ; ++i ){
        v = aux[ x ][ i ].first;
        id = aux[ x ][ i ].second;
        if( !seen[ v ] ){
            deleteCycle( v , comp , x );
        }
        else if( v != parent ){
            deletedEdge[ id ] = 1;
        }
    }
}

void dfs( int x , int lvl ){
    seen[ x ] = 1;
    depth[ x ] = lvl;

    for( int i = 0 ; i < aux[ x ].size() ; ++i ){
        if( !seen[ aux[ x ][ i ].first ] && !deletedEdge[ aux[ x ][ i ].second ] ){
            parent[ aux[ x ][ i ].first ] = x;
            dist[ aux[ x ][ i ].first ] = dist[ x ] + 1;
            dfs( aux[ x ][ i ].first , lvl + 1 );
        }
    }
}
//LCA
void lca_init(){
    int i , j;
    memset( kparent , -1 , sizeof( kparent ) );
    for( i = 0 ; i < n ; ++i ) kparent[ i ][ 0 ] = parent[ i ];
    for( j = 1 ; 1<<j <= n ; ++j )
        for( i = 0 ; i < n ; ++i )
            kparent[ i ][ j ] = kparent[ kparent[ i ][ j - 1 ] ][ j - 1 ];
}

int LCA( int p , int q ){
    int i, j;
    if( depth[ p ] < depth[ q ] ) swap( p , q );
    for( j = 1 ; 1<<j <= depth[ p ] ; ++j ); --j;
    for( i = j ; i >= 0 ; --i )
        if( depth[ p ] - ( 1<<i ) >= depth[ q ] ) p = kparent[ p ][ i ];
    if( p == q ) return q;
    for( i = j ; i >= 0 ; --i )
        if( kparent[ p ][ i ] != -1 && kparent[ p ][ i ] != kparent[ q ][ i ] )
            p = kparent[ p ][ i ] , q = kparent[ q ][ i ];

    return parent[ p ];
}
//END LCA

int degree[ MAX ];
int distancia( int u , int v ){
    int lca = LCA( u , v );
    return dist[ u ] + dist[ v ] - 2 * dist[ lca ];
}

int ady[ MAX ];
int main(){
    int i , v , Q , u , len , mini;
    while( scanf("%d" , &n ) != EOF ){
        for( i = 0 ; i < n && scanf("%d" , &v ) ; ++i ){
            ady[ i ] = v - 1;
            aux[ i ].pb( mp( v - 1 , i ) );
            aux[ v - 1 ].pb( mp( i , i ) );
        }

        memset( deletedEdge , 0 , sizeof( deletedEdge ) );
        memset( componente , -1,  sizeof( componente ) );
        memset( seen , 0 , sizeof( seen ) );
        memset( dist , 0 , sizeof( dist ) );
        len = 0;
        for( i = 0 ; i < n ; ++i ){
            if( !seen[ i ] )deleteCycle( i , len++ , -1 );
        }
        memset( deletedEdgeOfComponent , -1 , sizeof( deletedEdgeOfComponent ) );

        //borramos arista de cada componente que sea ciclo
        for( i = 0 ; i < n ; ++i ){
            if( deletedEdge[ i ] ){
                deletedEdgeOfComponent[ componente[ i ] ] = mp( i , ady[ i ] );
            }
        }

        //Formamos arbol para cada componente para hallar su LCA
        memset( seen , 0 , sizeof( seen ) );
        for( i = 0 ; i < n ; ++i ){
            if( !seen[ i ] ) dfs( i , 0 );
        }

        lca_init();
        scanf("%d" , &Q );
        while( Q-- > 0 && scanf("%d %d" , &u , &v ) ){
            u--; v--;
            if( componente[ u ] != componente[ v ] ) puts("-1");
            else{
                mini = distancia( u , v );
                if( deletedEdgeOfComponent[ componente[ u ] ].first != -1 ){
                    pii del = deletedEdgeOfComponent[ componente[ u ] ];
                    mini = min( mini , min( distancia( u , del.first ) + distancia( v , del.second ) + 1 , distancia( u  , del.second ) + distancia( v , del.first ) + 1 ) );
                }
                printf("%d\n" , mini );
            }
        }
        for( i = 0 ; i < n ; ++i ) aux[ i ].clear();
    }
    return 0;
}
