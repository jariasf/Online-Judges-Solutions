/*****************************************
 ***Problema: Money Matters
 ***ID: 11690
 ***Juez: UVA
 ***Tipo: Graph Theory
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
#define MAX 10005
int a[ MAX ], sum[ MAX ];
int uf[ MAX ];
int Find( int x ){
    return ( uf[ x ] == x ) ? x : uf[ x ] = Find( uf[ x ] );
}
void Union( int x , int y ){
    uf[ Find( x ) ] = Find( y );
}
int main(){

    int t , n , m , x , y;
    scanf("%d" , &t );
    while( t-- ){
        scanf("%d %d" , &n , &m );
        for( int i = 0 ; i  < n ; ++i ){
            scanf("%d" , &a[ i ] );
            uf[ i ] = i;
        }
        while( m-- ){
            scanf("%d %d" ,&x , &y );
            Union( x , y );
        }
        memset( sum , 0 , sizeof( sum ) );
        for( int i = 0 ; i < n ; ++i ){
            sum[ Find( i ) ] += a[ i ];
        }
        int i = 0;
        for( ; i < n ; ++i ){
            if( sum[ i ] != 0 ) break;
        }
        if( i == n )puts("POSSIBLE");
        else puts("IMPOSSIBLE");

    }

    return 0;
}
