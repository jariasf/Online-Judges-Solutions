/*****************************************
 ***Problema: Play on Words
 ***ID: 10129
 ***Juez: UVA
 ***Tipo: Union Find, DFS, Euler Tour
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
#define MAX 26
int V;

int ady[ MAX ][ MAX ];
bool seen[ MAX ];
int in[ MAX ], out[ MAX ];

int parent[MAX],rank[MAX];
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

int bosque(){
   set<int> cc;
   for( int i = 0; i < MAX ;i++){
       if( out[ i ] + in[ i ] > 0 )cc.insert(Find(i));
   }
   return cc.size();
}

bool connected( ){

    for( int i = 0 ; i < MAX ;++i){
        if( out[ i ] + in[ i ] > 0 )Make_Set( i );
    }

    for( int i = 0 ; i < MAX ;++i ){
       for( int j = 0 ; j < MAX ; ++j ){
            if( ady[ i ][ j ] ){
                if( Find( i ) != Find( j ) ){
                    Merge( i , j );
                }
            }
       }
    }
    if( bosque() != 1)return false;
    return true;
}

int main(){

    int t , ini;
    scanf("%d", &t);

    char s[ 1005 ];
    while( t-- ){
        scanf("%d", &V);
        memset( in , 0 , sizeof( in ) );
        memset( out , 0 , sizeof( out ) );
        memset( ady , 0 , sizeof( ady ));

        for( int i = 0 ; i < V ;++i ){
            scanf("%s", s );
            int u = s[ strlen( s ) - 1 ] - 'a';
            int v = s[ 0 ] - 'a';
            ady[ u ][ v ] = 1;
            ady[ v ][ u ] = 1;
            in[ v ]++;
            out[ u ]++;
        }

        if( !connected(  ) ){
            printf("The door cannot be opened.\n");
            continue;
        }

        int cont1 = 0, cont2 = 0, V_alpha = 0, cont4 = 0;
        bool possible = false;

        for( int i = 0 ; i < MAX ;++i ){
             if( out[ i ] + in[ i ] > 0 ){
                 V_alpha++;
                 if( out[ i ] == in[ i ] + 1 )cont1++;
                 else if( in[ i ] == out[ i ] + 1 )cont2++;
                 else if( out[ i ] == in[ i ] )cont4++;
             }
        }
        if(  V_alpha == cont4 || ( cont1 < 2 && cont2 < 2 && cont4 + cont1 + cont2 == V_alpha ) )possible = true;

        if( !possible )printf("The door cannot be opened.\n");
        else printf("Ordering is possible.\n");
    }
}
