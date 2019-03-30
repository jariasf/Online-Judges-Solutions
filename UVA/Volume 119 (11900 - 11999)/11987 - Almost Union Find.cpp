/*****************************************
 ***Problema: Almost Union Find
 ***ID: 11987
 ***Juez: UVA
 ***Tipo: Union Find
 ***Tiempo:
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/
/*
8 30
1 2 3
1 2 1
1 4 5
1 7 8
3 3
3 5
3 8
3 6
2 2 4
3 2
3 4
2 2 7
3 2
3 4
1 3 2
3 2
*/
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

#define MAX 100005

struct Node{
    long long sum , cnt;
    int parent;
    Node(){}
    Node( long long s , long long c , int p ): sum( s ) , cnt( c ) , parent( p ){}
    //Node( int s , int c ): sum( s ) , cnt( c ){}
}root[ MAX ];

int tree[ MAX ]; //arbol al cual pertenece el i-esimo elemento
int n;          //numero de elementos

//Find lo realizamos sobre los arboles al q pertenece un determinado elemento
int Find( int x ){
    return ( root[ x ].parent == x ) ? x : root[ x ].parent = Find( root[ x ].parent );
}

//Union sobre los arboles
void Union( int x , int y ){
    int yRoot = Find( tree[ y ] );
    int xRoot = Find( tree[ x ] );
    if( xRoot == yRoot ) return;
    root[ yRoot ].sum += root[ xRoot ].sum;
    root[ yRoot ].cnt += root[ xRoot ].cnt;
    root[ xRoot ].parent = yRoot;
}

//Move: cambiamos simplemente el puntero al arbol del elemento x, su nuevo arbol sera el arbol del elemento y
void Move( int x , int y ){
    int xRoot = Find( tree[ x ] );
    int yRoot = Find( tree[ y ] );
    if( xRoot == yRoot ) return;
    root[ xRoot ].sum -= x;
    root[ xRoot ].cnt--;
    root[ yRoot ].sum += x;
    root[ yRoot ].cnt++;
    tree[ x ] = yRoot;
}

void Print( int x ){
    int xRoot = Find( tree[ x ] );
    printf("%lld %lld\n" , root[ xRoot ].cnt , root[ xRoot ].sum );
}

int main(){
    int m, cnt , sum , c , u , v;
    while( scanf("%d %d"  ,&n , &m ) == 2 ){
        for( int i = 1 ; i <= n ; ++i ){
            tree[ i ] = i;
            root[ i ] = Node( i , 1 , i );
        }
        while( m-- ){
            scanf("%d" , &c );
            if( c == 1 ){
                scanf("%d %d" , &u , &v );
                Union( u , v );
            }
            else if( c == 2 ){
                scanf("%d %d" , &u , &v );
                Move( u , v );
            }
            else{
                scanf("%d" , &u );
                Print( u );
            }
        }
    }

    return 0;
}
