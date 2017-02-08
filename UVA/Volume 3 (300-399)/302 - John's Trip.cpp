/*****************************************
 ***Problema: John's Trip
 ***ID: 302
 ***Juez: UVA
 ***Tipo: Graph Theory, Euler Tour
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
#include <limits>
#include <fstream>
#include <list>
#include <sstream>
#include <iostream>
#include <iomanip>

using namespace std;
#define MAX 45
struct Edge{
    int v, id;
    Edge( int vv, int i ):v(vv), id(i){}
};

vector<Edge> ady[ MAX ];

bool f( Edge e1, Edge e2 ){
    return e1.id < e2.id;
}

int V;
#define MAXN 2000
bool seen[ MAXN ];
deque<int> tour;
void dfs( int inicial, int id ){
    for( int i = 0 ; i < ady[ inicial ].size(); ++i ){
         if( !seen[ ady[ inicial ][ i ].id ] ){
             seen[ ady[ inicial ][ i ].id ] = true;
             dfs( ady[ inicial ][ i ].v , ady[ inicial ][ i ].id );
         }
    }
    tour.push_front( id );
}

int main(){
    int id, u , v, inicial;
    int degree[ MAX ];
    while( scanf("%d %d", &u, &v) && u|v ){


        memset( degree , 0 , sizeof( degree ) );
        scanf("%d", &id );
        V = 0;
        ady[ u ].push_back( Edge( v , id ) );
        ady[ v ].push_back( Edge( u , id ) );
        degree[ u ]++;
        degree[ v ]++;
        V = max( V , max( u , v ) );
        //por enunciado john vive en la primra calle
        inicial = min( u , v );
        while( scanf("%d %d", &u, &v) && u|v ){
            scanf("%d", &id );
            ady[ u ].push_back( Edge( v , id ) );
            ady[ v ].push_back( Edge( u , id ) );
            degree[ u ]++;
            degree[ v ]++;
            V = max( V , max( u , v ) );
        }
        bool possible = true;
        for( int i = 1 ; i <= V ; ++i ){
             if( degree[ i ] & 1 ){
                 possible = false;
                 break;
             }
        }
        if( !possible ){
            printf("Round trip does not exist.\n\n");
            for( int i = 0 ; i <=V ;++i )ady[ i ].clear();
            continue;
        }

        ///ordenamos por id de arista para obtener lexicograficamente menor

        for( int i = 1 ; i <= V ;++i )sort( ady[ i ].begin() , ady[ i ].end() , f );

        memset( seen, 0 , sizeof( seen ) );
        tour.clear();
        dfs( inicial , - 1);
        printf("%d", tour[ 1 ]);
        for( int i = 2 ; i < tour.size(); ++i )printf(" %d", tour[ i ] );

        printf("\n\n");

        for( int i = 0 ; i <=V ;++i )ady[ i ].clear();
    }

    return 0;
}


