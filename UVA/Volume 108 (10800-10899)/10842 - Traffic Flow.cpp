/*****************************************
 ***Problema: Traffic Flow
 ***ID: 10842
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
#define MAX_SIZE 16001

struct Arista{
  int origen;
  int destino;
  int peso;
  //cambiar a > para arbol de recubrimiento de maxima suma
  bool operator<(const Arista &a) const{
     return peso>a.peso;
  }
}v[ MAX_SIZE ];

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
int ady[ MAX_SIZE ][ MAX_SIZE ];
///END UNION FIND

int f(const void *p, const void *q)
{
    return ((Arista *)q )->peso - ((Arista *)p)->peso;
}

int main(){

    int t , V, E , u , vv , c;
    scanf("%d" ,&t );
    for( int q = 1 ; q <= t ; ++q ){

        scanf("%d %d", &V ,&E );
        for( int i = 0 ; i < E ; ++i ){
            scanf( "%d %d %d" , &v[ i ].origen , &v[ i ].destino , &v[ i ].peso );
        }

        qsort( v, E , sizeof(v[0]), &f);
        for( int i = 0 ; i < V ; ++i ) Make_Set( i );


        int min = v[ 0 ].peso;
        for( int i = 0 ; i < E ; ++i ){

            int u = v[ i ].origen , vv = v[ i ].destino , w = v[ i ].peso;

            if( Find( u ) != Find( vv ) ){
                if( min > w )min = w;
                Merge( u , vv );
            }

        }
        printf("Case #%d: %d\n" , q , min );
    }

    return 0;
}
