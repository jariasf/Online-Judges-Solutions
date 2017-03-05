/*****************************************
 ***Problema: ACM contest and Blackout
 ***ID: 10600
 ***Juez: UVA
 ***Tipo: Graph Theory, MST, second best MST
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
  int origen;
  int destino;
  int peso;
  int mst;
  //cambiar a > para arbol de recubrimiento de maxima suma
  bool operator<(const Arista &a) const{
     return peso<a.peso;
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
///END UNION FIND
int main(){


    int t , V , E, first , second, aux , size;
    scanf("%d" ,&t );
    while( t-- ){
        scanf( "%d %d" , &V, &E );
        for( int i = 0 ; i < E ; ++i ){
            scanf("%d %d %d" , &v[ i ].origen , &v[ i ].destino , &v[ i ].peso );
        }

        sort( v , v + E );
        for( int i = 1 ; i <= V ; ++i )Make_Set( i );
        first = 0;
        for( int i = 0 ; i < E ; ++i ){

             int u = v[ i ].origen ,  vv = v[ i ].destino , w = v[ i ].peso;
             if( Find( u ) != Find( vv ) ){
                 v[ i ].mst = true;
                 first += w;
                 Merge( u , vv );
             }
             else v[ i ].mst = false;
        }

        second = INT_MAX;
        ///vemos aristas del MST y probamos nuevo MST eliminando una de dichas aristas
        for( int j = 0 ; j < E ; ++j ){
            if( !v[ j ].mst ) continue;
            aux = 0; size = 0;
            for( int i = 1 ; i <= V ; ++i ) Make_Set( i );

            for( int i = 0 ; i < E ; ++i ){
                 if( i == j )continue;
                 int u = v[ i ].origen ,  vv = v[ i ].destino , w = v[ i ].peso;
                 if( Find( u ) != Find( vv ) ){
                     aux += w;
                     size++;
                     Merge( u , vv );
                 }
            }
            ///si tengo todos los nodos, puede ser q la arista q halla eliminado sea la unica
            ///coneccion a ese nodo
            if( size == V - 1 )  second = min( second , aux );
        }

        printf("%d %d\n" , first , second );

    }

    return 0;
}
