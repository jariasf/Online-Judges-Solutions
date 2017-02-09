/*****************************************
 ***Problema: Eight
 ***ID: 652
 ***Juez: UVA
 ***Tipo: BFS | IDA* | A*
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

//BFS
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
#define MAX 400000
#define SIZE 9

int N = 3;
char direcciones[ 5 ] = { 'l' , 'r' , 'u' , 'd' };
int dx[ 4 ] = { 0 ,  0 , 1 , -1 };
int dy[ 4 ] = { 1 , -1 , 0 ,  0 };
int final[ SIZE ] = { 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 };
int seen[ MAX ], previous[ MAX ];
string path[ MAX ];
struct Estado{
    int d , posVacio , puzzle[ SIZE ] , hash;
    string path;
    Estado(){}
};

int getId( int x , int y ){ return x * N + y; }

void print( int hash ){
    int i;
    for( i = path[ hash ].size() - 1 ; i >= 0 ; --i ) printf("%c" , path[ hash ][ i ] );
    printf("\n");
}

int fact[ 10 ] = { 1 , 1 , 2 , 6 , 24 , 120 , 720 , 5040 , 40320 };
//Permutation inversion
int HashValue( int puzzle[] ){
    int i , j , inversions, hash = 0;
    for( i = 0 ; i < SIZE ; ++i ){
        inversions = 0;
        for( j = i + 1 ; j < SIZE ; ++j ){
            if( puzzle[ i ] > puzzle[ j ] ) inversions++;
        }
        hash += fact[ SIZE - i - 1 ] * inversions;
    }
    return hash;
}

void bfs(){
    int i , nx , ny , x , y , nuevoPos , hash , posVacio , hashAct;
    memset( seen , 0 , sizeof( seen ) );
    queue< Estado > Q;
    Estado inicial;
    memcpy( inicial.puzzle , final , sizeof( final ) );
    inicial.d = 0;
    inicial.posVacio = 8;
    inicial.hash = 0;
    inicial.path = "";
    Q.push( inicial );
    seen[ 0 ] = 1;
    previous[ 0 ] = -1;
    while( !Q.empty() ){
        Estado act = Q.front(); Q.pop();
        posVacio = act.posVacio;
        hashAct = act.hash;
        for( i = 0 ; i < 4 ; ++i ){
            y = posVacio % N;
            x = posVacio / N;
            nx = dx[ i ] + x;
            ny = dy[ i ] + y;
            Estado nuevo = act;
            if( nx >= 0 && ny >= 0 && nx < N && ny < N ){
                nuevoPos = getId( nx , ny );
                swap( nuevo.puzzle[ posVacio ] ,  nuevo.puzzle[ nuevoPos ] );
                hash = HashValue( nuevo.puzzle );
                if( !seen[ hash ] ){
                    seen[ hash ] = 1;
                    previous[ hash ] = hashAct;
                    nuevo.path += direcciones[ i ];
                    path[ hash ] = nuevo.path;
                    nuevo.hash = hash;
                    nuevo.posVacio = nuevoPos;
                    Q.push( nuevo );
                }
            }
        }
    }
}

int main(){
    bfs( );
    int casos , i , hash , q;
    char c;
    scanf("%d" , &casos );
    while( casos-- ){
        Estado inicial;
        for( i = 0 ; i < SIZE ; ++i ){
            scanf(" %c" , &c );
            if( c == 'x' ){
                inicial.puzzle[ i ] = 9;
            }
            else inicial.puzzle[ i ] = c - '0';
        }
        inicial.d = 0;
        hash = HashValue( inicial.puzzle );
        if( seen[ hash ] ){
            print( hash );
        }
        else puts("unsolvable");
        if( casos ) printf("\n");
    }
    return 0;
}

/*
12

x 8 7 6 5 4 3 2 1

6 8 7 x 5 4 3 2 1

8 x 7 6 5 4 3 2 1

6 8 7 3 5 4 x 2 1

6 8 7 5 x 4 3 2 1

8 5 7 6 x 4 3 2 1

8 7 x 6 5 4 3 2 1

2 1 8 5 4 3 7 6 x

2 1 x 5 6 8 7 3 4

2 1 8 5 x 6 7 3 4

2 4 1 5 6 8 x 7 3

1 7 8 2 5 4 x 6 3
*/

