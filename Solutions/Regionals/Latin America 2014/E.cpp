/*****************************************
 ***Problema: Even distribution
 ***Tipo: DFS + GCD
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <map>
#include <vector>
#include <set>
using namespace std;
#define MAX 10005
#define MAXC 100005
int V , E;
int cost[ MAX ];
vector<int> ady[ MAX ];
map<int, bool> seen[ MAX ];

int gcd(int a , int b){
   return  ( b == 0 ) ? a:gcd( b , a % b );
}

set<int> k;

void dfs( int u , int div ){
    k.insert( div );
    seen[ u ][ div ] = 1;
    for( int i = 0 ; i < ady[ u ].size() ; ++i ){
        int v = ady[ u ][ i ];
        int mcd = gcd( div , cost[v] );
        if( !seen[ v ][ mcd ] )
            dfs( v , mcd );
    }
}

int main(){
    int u , v;

    while( scanf("%d %d" , &V , &E ) != EOF ){

        for( int i = 0 ; i < V && scanf("%d" , &cost[ i ] ) ; ++i );

        while( E-- > 0 && scanf("%d %d" , &u , &v ) ){
            u--; v--;
            ady[ u ].push_back( v );
            ady[ v ].push_back( u );
        }

        for( int i = 0 ; i < V ; ++i ){
            dfs( i , cost[i] );
        }

        printf("%d\n" , (int)k.size() );

        k.clear();
        for( int i = 0 ; i <= V ; ++i ){
            ady[ i ].clear();
            seen[ i ].clear();
        }
    }

    return 0;
}
