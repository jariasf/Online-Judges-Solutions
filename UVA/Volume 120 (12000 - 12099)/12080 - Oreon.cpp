/*****************************************
 ***Problema: Oreon
 ***ID: 1208
 ***Juez: UVA
 ***Tipo: Graph Theory
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
#define MAX 30


int uf[ MAX ];
int Find( int x ){
    return ( uf[ x ] == x )? x : uf[ x ] = Find( uf[ x ] );

}
void Union( int x , int y ){
    uf[ Find( x ) ] = Find( y );
}


struct Arista{
    int v , w , u;
    Arista(){}
    Arista( int uu , int vv , int ww ): u( uu ) , v( vv ) , w( ww ){}
    bool operator <( const Arista &a ) const{
        if( w != a.w ) return w < a.w;
        if( u != a.u ) return u < a.u;
        return v < a.v;
    }
}graph[ MAX ];

int main(){

    int t, V,  w , E , n;
    char s[ 1005 ];
    scanf("%d"  , &t );
    for( int q = 1 ; q <= t ; ++q ){
        scanf("%d" , &V );
        gets( s );
        E = 0;
        for( int i = 0 ; i < V ; ++i ){
            uf[ i ] = i;
            scanf("%d" , &n );
            for( int j = 1 ; j < V ; ++j ){
                scanf(",%d" , &n );
                if( j > i && n != 0 ) {
                    graph[ E++ ] = Arista( i , j , n );
                }
            }
        }

        sort( graph , graph + E );
        printf("Case %d:\n" , q );
        for( int i = 0 ; i < E ; ++i ){
            int u = graph[ i ].u , v = graph[ i ].v;
            w = graph[ i ].w;
            if( Find( u ) != Find( v ) ){
                printf("%c-%c %d\n" , u + 'A' , v + 'A' , w );
                Union( u , v );
            }
        }
    }


    return 0;
}
