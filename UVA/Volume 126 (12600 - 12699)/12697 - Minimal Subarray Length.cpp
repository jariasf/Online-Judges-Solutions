/*****************************************
 ***Problema: Minimal Subarray Length
 ***ID: 12697
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
/*
2
7 3
-1 1 1 1 -1 -3 5
10 15
1 4 -1 -2 6 3 -8 14 -1 1 -1
*/

#define MAX 500005
long long sum[ MAX ];
long long tree[MAX * 4];
int n;

void update( int pos , int by , int left = 0 , int right = n - 1, int node = 0 ){
    if( left == right ){
        tree[ node ] = by;
        return;
    }
    int mid = ( left + right )/2;
    if( pos > mid ){
        update( pos , by , mid + 1 , right , 2 * node + 2 );
    }
    else{
        update( pos , by , left , mid , 2 * node + 1 );
    }
    tree[ node ] = min( tree[ 2 * node + 1 ] , tree[ 2 * node + 2 ] );
}

int query( long long value , int left = 0 , int right = n - 1, int node = 0 ){
    if( left > right ) return 1<<30;
    if( left == right ){
        return left;
    }
    int mid = ( left + right )/2, res = 0;
    int L = 2 * node + 1 , R = 2 * node + 2;
    int index = 1<<30;
    if( tree[ R ] <= value ){
        index = query( value , mid + 1 , right , R );
    }else if( tree[ L ] <= value )
        index = query( value , left , mid , L );
    return index;
}

int init(){
	for(int i = 0; i < 4 * n; i++) tree[ i ] = 1<<30;
}

int main(){
    long long x, m;
    int t ,  ans, idx;
    scanf("%d" , &t );
    while( t-- > 0 && scanf("%d %lld" , &n , &m ) ){
        init();
        ans = 1<<30;
        sum[ 0 ] = 0;
        update( 0 , 0 );
        for( int i = 1 ; i <= n && scanf("%lld" , &x ) ; ++i ){
            sum[ i ] = sum[ i - 1 ] + x;
            long long lookFor = sum[ i ] - m;
            int index = query( lookFor );
            if( index != 1<<30 ){
                ans = min( ans , i - index );
            }
            update( i , sum[ i ] );
        }
        if( ans == 1<<30 )
            printf("-1\n");
        else
            printf("%d\n" , ans );
    }
    return 0;
}
