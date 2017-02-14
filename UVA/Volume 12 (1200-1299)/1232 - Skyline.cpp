/*****************************************
 ***Problema: Skyline
 ***ID: 1232
 ***Juez: UVA
 ***Tipo: Segment Tree
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
#define MAX 100005
int n = MAX;
int tree[ 4 * MAX ] , lazy[ 4 * MAX ];

void propagation( int left , int right, int by , int node ){
    if( lazy[ node ] == -1 )
        return;
    int mid = ( left + right ) >>1 , L = 2 * node + 1 , R = 2 * node + 2;
    tree[ L ] = max( tree[ L ] , tree[ node ] );
    tree[ R ] = max( tree[ R ] , tree[ node ] );
    lazy[ L ] = lazy[ R ] = 1;
    lazy[ node ] = -1;
    tree[ node ] = 0;
}

int query( int from , int to , int by , int left = 0 , int right = n - 1 , int node = 0 ){
    if( from <= left && right <= to && tree[ node ] <= by ){
        lazy[ node ] = 1;
        tree[ node ] = by;
        return right - left + 1;
    }

    if( from <= left && right <= to && tree[ node ] > by && lazy[ node ] == 1 ){
        return 0;
    }

    if( left == right && tree[ node ] > by ){
        return 0;
    }

    int mid = ( left + right ) >>1 , L = 2 * node + 1 , R = 2 * node + 2;
    int ans = 0;
    propagation( left , right , by , node );

    if( from <= mid )
        ans += query( from , to , by , left , mid , L );
    if( to > mid )
        ans += query( from , to , by , mid + 1 , right , R );

    tree[ node ] = max( tree[ L ] , tree[ R ] );

    if( tree[ L ] == tree[ R ] && lazy[ L ] != -1 && lazy[ L ] == lazy[ R ] ){
        lazy[ node ] = 1;
    }else
        lazy[ node ] = -1;

    return ans;
}

void build( int left = 0 , int right = n - 1 , int node = 0 ){
    if( left == right ){
        lazy[ node ] = -1;
        tree[ node ] = 0;
        return;
    }

    int mid = ( left + right ) >>1 , L = 2 * node + 1 , R = 2 * node + 2;
    build( left , mid , L );
    build( mid + 1 , right , R );
    lazy[ node ] = -1;
    tree[ node ] = tree[ L ];
}

int l_[ MAX ] , r_[MAX] , h_[ MAX ];
int main(){
    int t , m , l , r , h , ans, maxi;
    scanf("%d" , &t );
    while( t-- > 0 && scanf("%d" , &m ) ){
        ans = 0;
        maxi = 0;
        for( int i = 0 ; i < m && scanf("%d %d %d" , &l_[i] , &r_[i] , &h_[i] ) ; ++i ){
            maxi = max( maxi , r_[i] + 1 );
        }
        n = maxi;
        build( 0 , n );
        for( int i = 0 ; i < m ; ++i ){
            ans += query( l_[i] , r_[i] - 1 , h_[i] );
        }
        printf("%d\n" , ans );
    }
    scanf("%d" , &t);
    return 0;
}
