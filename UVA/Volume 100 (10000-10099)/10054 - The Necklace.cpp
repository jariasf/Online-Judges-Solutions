/*****************************************
 ***Problema: The Necklace
 ***ID: 10054
 ***Juez: UVA
 ***Tipo: Graph Theory, Euler Circuit
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <stdlib.h>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <numeric>
#include <utility>
#include <deque>
#include <stack>
#include <bitset>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <queue>
#include <fstream>
#include <list>
#include <sstream>
#include <iostream>
#include <iomanip>

using namespace std;
#define MAX 55

struct Edge{
    int v, id;
    Edge( int vv, int i ):v(vv), id(i){}
};

vector<Edge> ady[ MAX ];
int degree[ MAX ];
int aux[ MAX][ MAX ], V;
bool connected(){

    for( int k = 1 ; k < V ; ++k ){
        for( int i = 1 ; i < V ; ++i ){
           for( int j = 1 ; j < V ; ++j ){
               aux[ i ][ j ] |= aux[ i ][ k ] & aux[ k ][ j ];
           }
        }
    }

    for( int i = 1 ; i < V ; ++i ){
        for( int j = 1 ; j < V ; ++j ){
            if( i != j && degree[ i ] && degree[ j ] && !aux[ i ][ j ] )
                return false;
        }
    }
    return true;
}

deque<int> resp;
bool seen[ 1005 ];
void tour( int x , int id ){

    while( ady[ x ].size() > 0 ){
        Edge y = ady[ x ].back();
        ady[ x ].pop_back();
        if( !seen[ y.id ] ){
            seen[ y.id ] =true;
            tour( y.v , y.id );
            resp.push_back( y.v );
        }
    }
}

int main(){

    int t, E , u , v, min;
    scanf("%d", &t );

    for( int q = 1 ; q <= t ; ++q ){
        if( q - 1 )printf("\n");
        scanf("%d", &E );

        for( int i = 0 ; i < MAX ; ++i )ady[ i ].clear();
        memset( degree , 0 , sizeof( degree ) );
        memset( aux , 0 ,sizeof( aux ) );
        V = 1;
        min = 9999999;
        for( int i = 1 ; i <= E ; ++i ){
            seen[ i ] = false;
            scanf("%d %d", &u ,&v );
            ady[ u ].push_back( Edge( v , i ) );
            ady[ v ].push_back( Edge( u , i ) );
            degree[ u ]++;
            degree[ v ]++;
            aux[ u ][ v ] = aux[ v ][ u ] = 1;
            min = std::min( u , std::min( v , min) );
            V = std::max( u , std::max( v, V ) );
        }
        V++;

        //check connection
        printf("Case #%d\n",q);
        if( !connected() ){
            printf("some beads may be lost\n");
            continue;
        }

        //check circuit property
        bool possible = true;
        for( int i = 1 ; i < V ; ++i ){
            if( degree[ i ] & 1 ){
                possible = false;
                break;
            }
        }
        if( !possible ){
            printf("some beads may be lost\n");
        }
        else{

            for( int i = 1 ; i < V ; ++i   ){
                reverse(ady[ i ].begin() , ady[ i ].end() );
            }
            resp.clear();
            tour( min , -1 );
            for( int i = 0 ; i < resp.size() - 1; ++i ){
                printf( "%d %d\n", resp[ i ] , resp[ i  + 1 ]);
            }
            printf("%d %d\n", resp[ resp.size() - 1 ] , resp[ 0 ] );
        }
    }


    return 0;
}
