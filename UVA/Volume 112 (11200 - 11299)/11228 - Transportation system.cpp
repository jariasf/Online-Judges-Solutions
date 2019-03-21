/*****************************************
 ***Problema: Transportation system
 ***ID: 11228
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
#define MAX_SIZE 10001

struct Arista{
  int u;
  int v;
  double w;
  Arista( int o , int d , double ww ): u( o ) , v( d ) , w( ww ){}
  //cambiar a > para arbol de recubrimiento de maxima suma
  bool operator<(const Arista &a) const{
     return w<a.w;
  }
};

///UNION-FIND
int parent[MAX_SIZE],rank[MAX_SIZE];
void Make_Set(const int x){
    parent[x]=x;
    rank[x]=0;
}

int Find(const int x){
    if(parent[x]!=x) parent[x]=Find(parent[x]);
    return parent[x];
}

void Union(const int PX, const int PY){
    if(rank[PX]>rank[PY]) parent[PY]=PX;
    else{
        parent[PX]=PY;
        if(rank[PX]==rank[PY]) rank[PY]++;
    }
}

void Merge(const int x,const int y){
    Union(Find(x),Find(y));
}
///END UNION FIND
int main(){
    int t, V, T , states , x, y;
    scanf("%d" ,&t );
    for( int q = 1; q <= t ; ++q ){
        scanf("%d %d", &V , &T);
        states = 1;
        vector< pair<int , int > > p;
        for( int i = 0 ; i < V ; ++i ){

            scanf("%d %d" ,&x ,&y );
            p.push_back( make_pair( x , y ) );
        }
        vector< Arista > v;
        for( int i = 0 ; i < V ; ++i ){

            for( int j = i + 1 ; j < V ; ++j ){

                double dist = ( p[ i ].first - p[ j ].first) * ( p[ i ].first - p[ j ].first) + ( p[ i ].second - p[ j ].second )*( p[ i ].second - p[ j ].second );
                v.push_back( Arista( i , j , dist ) );
            }

        }

        sort( v.begin() , v.end() );
        for( int i = 0 ; i < V ; ++i )Make_Set( i );
        double total = 0 , rail = 0;
        for( int i = 0 ; i < v.size(); ++i ){
            Arista a = v[ i ];
            int u = a.u , v = a.v;
            double w = a.w;
            if( Find( u ) != Find( v ) ){
                 if( w <= T*T ) total += sqrt( w );
                 else {
                     states++;
                     rail += sqrt( w );
                 }
                 Merge( u , v );
            }
        }

        printf("Case #%d: %d %.0f %.0f\n" ,q , states , total , rail );
    }

    return 0;
}
