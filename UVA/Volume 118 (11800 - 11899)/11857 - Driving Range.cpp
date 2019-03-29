/*****************************************
 ***Problema: Driving Range
 ***ID: 11857
 ***Juez: UVA
 ***Tipo: Graph Theory, MST
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
#define MAX 1000005
int uf[ MAX ];
int Find( int x ){
    return ( uf[ x ] == x ) ? x : uf[ x ] = Find( uf[ x ]);
}
void Union( int x , int y ){
    uf[ Find( x ) ] = Find( y );
}

struct Arista{
    int u , v , w;
    Arista( int uu , int vv , int ww ): u( uu ) , v( vv ) , w( ww ) {}
    Arista(){}
    bool operator <( const Arista &a ) const{
        return w < a.w;
    }
}graph[ MAX ];

int main(){
    int V , E , u , v , w , ans , size;

    while( scanf("%d %d" , &V , &E ) , V|E ){
        for( int i = 0 ; i < E ; ++i ){
            scanf("%d %d %d" , &u , &v , &w );
            graph[ i ] = Arista( u , v , w );
        }
        sort( graph , graph + E );
        ans = -1;
        size = 0;
        for( int i = 0 ; i < V ; ++i )uf[ i ] = i;
        for( int i = 0 ; i < E ; ++i ){
            u = graph[ i ].u; v = graph[ i ].v; w = graph[ i ].w;
            if( Find( u ) != Find( v ) ){
                size++;
                if( w > ans ) ans = w;
                Union( u , v );
            }
        }
        if( size == V - 1 && ans != -1 )printf("%d\n" , ans );
        else printf("IMPOSSIBLE\n");
    }

    return 0;
}
