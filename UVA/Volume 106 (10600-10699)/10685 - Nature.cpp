/*****************************************
 ***Problema: Nature
 ***ID: 10685
 ***Juez: UVA
 ***Tipo: Graph Theory, Union Find
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
#define MAX_SIZE 5005
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

    int V, E, len;
    int resp[ MAX_SIZE ];
    char s[ 40 ], s1[ 40 ];
    while( scanf("%d %d" , &V , &E ) && V|E ){
        map<string , int > mp;
        len = 0;
        for( int i = 0 ; i < V ; ++i ){
            scanf("%s" , s );
            if( mp.find( s ) == mp.end() ){
                mp[ s ] = len++;
            }
        }

        for( int i = 0 ; i < len ; ++i )Make_Set( i );

        while( E-- ){
            scanf("%s %s" , s , s1 );
            int a = mp[ s ] , b = mp[ s1 ];
            if( Find( a ) != Find( b ) ){
                Merge( a , b );
            }
        }

        memset( resp , 0 , sizeof( resp ) );
        for( int i = 0 ; i < len ; ++i ){
            resp[ Find( i ) ]++;
        }
        int ans = 0;
        for( int i = 0 ; i < V + 1 ; ++i ){
            if( resp[ i ] > ans )ans = resp[ i ];
        }
        printf("%d\n" , ans );

    }

    return 0;
}
