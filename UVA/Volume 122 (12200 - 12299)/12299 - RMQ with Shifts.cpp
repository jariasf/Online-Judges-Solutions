/*****************************************
 ***Problema: RMQ with Shifts
 ***ID: 12299
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
#include <climits>
#include <fstream>
#include <list>
#include <sstream>
#include <iostream>
#include <iomanip>

using namespace std;
#define MAX 100005
int n , tree[ 4 * MAX ];

void build( int left = 0 , int right = n - 1 , int node = 0 ){

    if( left == right ){
        tree[ node ] = 1<<30;
        return;
    }
    int mid = ( left + right ) >> 1;
    build( left , mid , 2 * node + 1  );
    build( mid + 1 , right , 2 * node + 2 );
}

void update( int pos , int val , int left = 0 , int right = n - 1 , int node = 0 ){
    if( left == right ){
        tree[ node ] = val;
        return;
    }
    int mid = ( left  +right ) >> 1;
    if( mid < pos )
        update( pos , val , mid + 1 , right , 2 * node + 2  );
    else
        update( pos , val , left , mid , 2 * node + 1 );
    tree[ node ] = min( tree[ 2 * node + 1 ] , tree[ 2 * node + 2 ] );
}

int query( int from , int to , int left = 0 , int right = n - 1 , int node = 0 ){
    if( left >= from && right <= to ){
        return tree[ node ];
    }
    int mid = ( left  +right ) >> 1 , ans = 1<<30 , L , R ;
    L = R = ans;
    if( mid < to )
        R = query( from , to , mid + 1 , right , 2 * node + 2  );
    if( mid >= from  )
        L = query( from , to , left , mid , 2 * node + 1 );
    ans = min( R , L );
    return ans;
}


int a[ MAX ];
#define MAXN 35
char s[ MAXN ];
int x[ MAXN ];
int main(){
    int Q , i , left , right  ;
    scanf("%d %d" , &n , &Q );
    for( i = 0 ; i < n && scanf("%d" , &a[ i ] ) ; ++i )
        update( i , a[ i ] );

    while( Q-- > 0 && scanf("%s" , s ) ){
        if( s[ 0 ] == 'q' ){
            sscanf( s , "query(%d,%d)" , &left , &right );
            printf("%d\n" , query( left - 1 , right - 1 ) );
        }
        else{
            for( i = 0 ; s[ i ] ; ++i ){
                if( s[ i ] >= '0' && s[ i ] <= '9' ) continue;
                s[ i ] = ' ';
            }
            stringstream ss( s );
            i = 0;
            while( ss>>x[ i ] ) x[ i ]-- , i++;
            int tmp = a[ x[ 0 ] ];
            for( int j = 0 ; j + 1 < i ; ++j ){
                a[ x[ j ]  ] = a[ x[ j + 1 ] ];
                update( x[ j ] , a[ x[ j ] ] );
            }
            a[ x[ i - 1 ] ] = tmp;
            update( x[ i - 1 ] , tmp );
        }
    }

    return 0;
}
