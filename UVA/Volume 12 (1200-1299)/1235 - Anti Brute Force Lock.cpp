/*****************************************
 ***Problema: Anti Brute Force Lock
 ***ID: 1235
 ***Juez: UVA
 ***Tipo: Kruskal
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
#define MAX 505
int uf[ MAX ];
int V;
void MakeSet(){ int i; for( i = 0 ; i <= V ; ++i ) uf[ i ] = i; }
int Find( int x ){ return ( x == uf[ x ] )? x : uf[ x ] = Find( uf[ x ] );}
void Union( int x , int y ){ uf[ Find( x ) ] = Find( y ) ;}

char s[ MAX ][ 5 ];
struct Edge{
    int u , v , w;
    Edge( int uu , int vv , int ww ): u( uu ) , v( vv ) , w( ww ){}
    bool operator <( const Edge e1 ) const{
        return w < e1.w;
    }
    Edge(){}
}ady[ 300000 ];

int min( int a , int b ){ return ( a < b )? a : b; }
int getWeight( int a , int b ){
    int i , cnt = 0 , w1 ,w2;
    for( i = 0 ; i < 4 ; ++i ){
        w1 = w2 = 0;
        if( s[ a ][ i ] - '0' < s[ b ][ i ] - '0' ){
            w1 = s[ b ][ i ] - s[ a ][ i ];
            w2 = s[ a ][ i ] + 10 - s[ b ][ i ];
        }
        else if( s[ a ][ i ] - '0' > s[ b ][ i ] - '0' ){
            w1 = s[ a ][ i ] - s[ b ][ i ];
            w2 = s[ b ][ i ] + 10 - s[ a ][ i ];
        }
        cnt += min( w1 , w2 );
    }
    return cnt;
}

int main(){
    int t , i , j , len , u , v , w , ans;
    scanf("%d" , &t );

    while( t-- ){
        scanf("%d" , &V );
        strcpy( s[ 0 ] , "0000");
        for( i = 1 ; i <= V && scanf("%s" , &s[ i ] ) == 1 ; ++i );
        len = 0;
        MakeSet();
        ans = 1<<30;
        for( i = 1 ; i <= V ; ++i ){
            w = getWeight(  0 , i );
            if( ans > w ){
                ans = w;
                u = i;
            }
            for( j = i + 1 ; j <= V ; ++j ){
                ady[ len++ ]=  Edge( i , j , getWeight( i , j ) );
            }
        }

        Union( 0 , u );
        sort( ady , ady + len );

        for( i = 0 ; i < len ; ++i ){
            u = ady[ i ].u;
            v = ady[ i ].v;
            w = ady[ i ].w;
            if( Find( u ) != Find( v ) ){
                ans += w;
                Union( u , v );
            }
        }
        printf("%d\n" , ans );
    }

    return 0;
}
