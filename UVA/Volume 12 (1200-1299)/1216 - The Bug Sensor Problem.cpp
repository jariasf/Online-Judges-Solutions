/*****************************************
 ***Problema: The Bug Sensor Problem
 ***ID: 1216
 ***Juez: UVA
 ***Tipo: MST
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
#include <climits>
#include <fstream>
#include <list>
#include <sstream>
#include <iostream>
#include <iomanip>

using namespace std;
#define MAX 100005
#define MAXE 1000005
int uf[ MAX ] , V , E , numComp;
int Find( int x ){ return ( x == uf[ x ] )? x : uf[ x ] = Find( uf[ x ] ); }
void Union( int x , int y ){ uf[ Find( x ) ] = Find( y ); }
void MakeSet(){ for( int i = 0 ; i < V ; ++i ) uf[ i ] = i; numComp = V; }
struct Edge{
    int u , v;
    double w;

    Edge( int uu , int vv , double ww ) : u(uu) , v(vv) , w(ww){}

    bool operator < ( const Edge e1 ) const{
        return w < e1.w;
    }
    Edge(){}
}graph[ MAXE ];

int a[ MAX ][2];

double dist( double x1 , double y1 , double x2 , double y2 ){
    return sqrt( ( x1 - x2 ) * ( x1 - x2 ) + ( y1 - y2 ) * ( y1 - y2 ) );
}

int main(){

    int t , n , x , y;
    scanf("%d" , &t );
    while( t-- > 0 && scanf("%d" , &n ) ){
        V = 0;
        while( scanf("%d" , &x ) , x != -1 ){
            scanf("%d" , &y );
            a[V][0] = x; a[V++][1] = y;
        }


        E = 0;
        for( int i = 0 ; i < V ; ++i ){
            for( int j = i + 1 ; j < V ; ++j ){
                graph[ E++ ] = Edge( i , j , dist( a[ i ][0 ] , a[i][1] , a[j][0] , a[j][1] ) );
            }
        }

        MakeSet();
        sort( graph , graph + E );

        if( V <= n ){
            printf("0\n");
            continue;
        }

        for( int i = 0 ; i < E ; ++i ){
            int u = graph[i].u;
            int v = graph[i].v;
            double w = graph[i].w;
            if( Find( u ) != Find( v ) ){
                Union( u , v );
                numComp--;
            }
            if( numComp <= n ){
                printf("%d\n" , (int)ceil(w) );
                break;
            }
        }
    }

    return 0;
}

/*
3
2
1 1
2 1
8 7
-1
3
1 1
2 1
8 7
-1
1
1 1
99999 99999
-1
*/
