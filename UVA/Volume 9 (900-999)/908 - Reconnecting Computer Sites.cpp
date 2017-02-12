/*****************************************
 ***Problema: Re-connecting Computer Sites
 ***ID: 908
 ***Juez: UVA
 ***Tipo: Graph Theory, MST, Kruskal
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

void makeSet(int V ){
    for( int i = 1 ; i <= V ; ++i )
        uf[i] = i;
}

int Find( int x ){
    return ( uf[ x ] == x ) ? x : uf[ x ] = Find( uf[ x ] );
}
void Union( int x , int y ){
    uf[ Find( x ) ] = Find( y );
}

struct Arista{
    int u , v , w;
    Arista( int uu , int vv , int ww ): u( uu ) , v( vv ) , w( ww ) {}
    Arista() {}
    bool operator <( const Arista &a ) const{
        return w < a.w;
    }
} graph[ MAX ];

int main(){
    int u,v , c , T, ans1, ans2, V, K,M;
    bool first = true;
    while( scanf("%d" , &V) != EOF){
        if( !first ) printf("\n");
        first = false;
        ans1 = ans2 = 0;
        for( int i = 0 ; i < V - 1 && scanf("%d %d %d" , &u , &v , &c ) ; ++i ){
            ans1 += c;
        }
        scanf("%d" , &K );
        for( int i = 0 ; i < K && scanf("%d %d %d" , &graph[i].u, &graph[i].v, &graph[i].w) ; ++i);
        scanf("%d" , &M );
        for( int i = 0 ; i < M && scanf("%d %d %d" , &graph[i+K].u, &graph[i+K].v, &graph[i+K].w) ; ++i);
        int E = K + M;
        makeSet(V);
        sort( graph, graph + E );

        for( int i = 0 ; i < E ; ++i ){
            int u = graph[i].u;
            int v = graph[i].v;
            int c = graph[i].w;
            if( Find(u) != Find(v) ){
                Union(u,v);
                ans2 += c;
            }
        }
        printf("%d\n%d\n", ans1, ans2 );
    }

    return 0;
}
