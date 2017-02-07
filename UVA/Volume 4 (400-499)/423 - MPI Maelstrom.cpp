/*****************************************
 ***Problema: MPI Maelstrom
 ***ID: 423
 ***Juez: UVA
 ***Tipo: Graph Theory, Floyd Warshall
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
#define MAX 105
#define INF 9999999
int ady[MAX][MAX] , V;

void Init(){
    for(int i = 0 ; i < MAX ; ++i ){
         for(int j = 0 ; j < MAX ; ++j ){
                 ady[ i ][ j ] = INF;
         }
        ady[ i ][ i ] = 0;
    }
}

void floyd(){
    for(int k = 0 ; k < V ; ++k ){
        for(int i = 0 ; i < V ; ++i ){
             for(int j = 0 ; j < V ; ++j ){
                    int t = ady[ i ][ k ] + ady[ k ][ j ];
                    if( t < ady[ i ][ j ] ){
                        ady[ i ][ j ] = t;
                    }
             }
        }
    }
}

int toInt( string s ){
    stringstream ss( s);
    int n;
    ss>>n;
    return n;
}

int main(){
    int j;
    string s;
    scanf("%d" , &V);
    Init();
    cin.get();
    for( int i = 1 ; i < V  ;++i){

        getline( cin , s );
        s+=" ";
        stringstream ss( s );
        j = 0;
        while( ss>> s ){
            if( s != "x" ){
                ady[ i ][ j ] = ady[ j ][ i ] = toInt( s );
            }
            j++;
        }
    }
    floyd();
    int resp = 0;
    for( int i = 0 ; i < V ; ++i ){
        if( ady[ 0 ][ i ] != INF && resp < ady[ 0 ][ i ])resp = ady[ 0 ][ i ];
    }
    printf("%d\n" , resp);
    return 0;
}
