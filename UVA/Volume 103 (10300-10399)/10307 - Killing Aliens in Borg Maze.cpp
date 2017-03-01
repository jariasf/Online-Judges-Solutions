/*****************************************
 ***Problema: Killing Aliens in Borg Maze
 ***ID: 10307
 ***Juez: UVA
 ***Tipo: Graph Theory, BFS, MST
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

#define MAX_SIZE 101

struct Arista{
  int origen;
  int destino;
  int peso;
  //cambiar a > para arbol de recubrimiento de maxima suma
  bool operator<(const Arista &a) const{
     return peso<a.peso;
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
    //int PX=Find(x),PY=Find(y);

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

#define MAX 60
int f , c;
int posX[ MAX_SIZE ] , posY[ MAX_SIZE ];
char ady[ MAX ][ MAX ];
int dx[ 4 ] = { 1 , -1 , 0 ,  0 };
int dy[ 4 ] = { 0 ,  0 , 1 , -1 };
#define mp make_pair
int dist[ MAX ][ MAX ];
void bfs( int x , int y ){
    queue< pair<int , int> > Q;
    Q.push( mp( x , y ) );
    dist[ x ][ y ] = 0;
    while( !Q.empty() ){
         pair<int , int > act = Q.front(); Q.pop();
         for( int i = 0 ; i < 4 ; ++i ){
            int nx = act.first + dx[ i ];
            int ny = act.second + dy[ i ];
            if( nx >= 0 && nx < f && ny >= 0 && ny < c && ady[ nx ][ ny ] != '#'){
                if( dist[ act.first ][ act.second ] + 1 < dist[ nx ][ ny ] ){
                    dist[ nx ][ ny ] = dist[ act.first ][ act.second ] + 1;
                    Q.push( mp( nx , ny ) );
                }
            }
         }
    }

}

int N;
void Kruskal( vector<Arista> v ){
    int total = 0;
    sort( v.begin() , v.end() );
    for( int i = 0 ; i < N ; ++i ) Make_Set( i );
    for( int i = 0 ; i < v.size() ; ++i ){
         int xi = v[ i ].origen, xf = v[ i ].destino, w = v[ i ].peso;
         if( Find( xi ) != Find( xf ) ){
             total += w;
             Merge( xi , xf );
         }
    }
    printf("%d\n" , total );
}

int main(){
    int t ;
    scanf("%d" ,&t );
    while( t-- ){
        scanf( "%d %d" , &c, &f );
        N = 0;
        memset( ady , '#' , sizeof( ady ) );
        gets( ady[ 0 ] );
        for( int i = 0 ; i < f ; ++i ){
             gets( ady[ i ] );
             int l = strlen( ady[ i ] );
             for( int j = 0 ; j < l ; ++j ){
                  if( ady[ i ][ j ] == 'S' || ady[ i ][ j ] == 'A' ){
                      posX[ N ] = i;
                      posY[ N++ ] = j;
                  }
             }
        }

        vector< Arista > v;
        ///hacemos bfs para hallar distancias entre nodos para hallar MST
        for( int i = 0 ; i < N ; ++i ){
            memset( dist , 0x3f , sizeof( dist ) );
            bfs( posX[ i ] , posY[ i ] );
            for( int j = 0 ; j < N ; ++j ){
                Arista a;
                a.origen = i; a.destino = j ; a.peso = dist[ posX[ j ] ][ posY[ j ] ];
                v.push_back( a );
            }
        }
        Kruskal( v );
    }
    return 0;
}
