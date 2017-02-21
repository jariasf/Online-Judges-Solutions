/************************************************
 ***Problema: War
 ***ID: 10158
 ***Juez: UVA
 ***Tipo: Graph Theory, Connectivity, Union Find
 ***Autor: Jhosimar George Arias Figueroa
 ***********************************************/

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
#define MAX_SIZE 20005

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
using namespace std;
int n;

///para enemigos
int other( int nodo ){
    if( nodo >= n )return nodo - n ;
    return n + nodo;
}

int main(){
    int c , x, y;
    while ( scanf("%d", &n) != EOF ){

        for( int i = 0 ; i < MAX_SIZE ; ++i )Make_Set(i);

        while( scanf("%d %d %d", &c ,&x ,&y ) ){
            if( c == 0 && x == 0 && y == 0)break;
            if( c == 1 ){

                ///si son enemigos no tienen xq ser amigos
                if( Find( x ) == Find( other(y) ) || Find( y ) == Find( other(x) ) ){
                   printf("-1\n");
                }
                else{
                    Merge( x , y );
                    Merge( other( x ) , other( y ) );
                }
            }
            else if( c == 2 ){
                ///si son amigos no tienen xq ser enemigos
                if( Find( other( x ) ) == Find( other( y ) ) || Find( x ) == Find( y ) ){
                    printf("-1\n");
                }
                else{

                    Merge( x , other(y) );
                    Merge( y , other(x) );
                }
            }
            else if( c == 3 ){

                if( Find( x ) == Find( y ) || Find( other( x ) ) == Find( other( y ) ) ){
                    printf("1\n");
                }
                else printf("0\n");

            }
            else if( c == 4 ){
                if( Find( x ) == Find( other( y ) )  || Find( y ) == Find( other( x ) ) ){
                    printf("1\n");
                }
                else printf("0\n");
            }
        }


    }

    return 0;
}
