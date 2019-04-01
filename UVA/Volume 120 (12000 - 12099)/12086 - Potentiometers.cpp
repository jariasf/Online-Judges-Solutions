/*****************************************
 ***Problema: Potentiometers
 ***ID: 12086
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
#define MAX 200005
int tree[ 4 * MAX ];
int n , by;
void update( int pos , int left = 0 , int right = n - 1 , int node = 0 ){
    if( left == right ){
        int ant = tree[ node ];
        tree[ node ] = by;
        by -= ant;
        return;
    }
    int mid = ( left + right )/2;

    if( pos > mid ) update( pos ,  mid + 1 , right , 2 * node + 2 );
    else update( pos , left , mid , 2 * node + 1 );
    tree[ node ] += by;
}


int rsq( int from , int to , int left = 0 , int right = n - 1 , int node = 0 ){

    if( left >= from && right <= to )return tree[ node ];
    int mid = ( left + right )/2;
    int sum = 0;
    if( from <= mid ){
        sum += rsq( from , to , left , mid , 2 * node + 1 );
    }
    if( to > mid ){
        sum += rsq( from , to , mid + 1 , right , 2 * node + 2 );
    }
    return sum;
}

void init(){
    for( int i = 0 ; i < 4 * MAX ; ++i ) tree[ i ] = 0;
}

int main(){
    int x , y , q = 0;
    char s[ 5 ];
    while( scanf("%d" , &n ) , n ){
        init();
        for( int i = 0 ; i < n ; ++i ){
            scanf("%d" , &x );
            by = x;
            update( i );
        }
        if( q )printf("\n");
        printf("Case %d:\n" , ++q );
        while( scanf("%s" , &s ) , s[ 0 ] != 'E' ){
            scanf("%d %d" , &x , &y );
            if( s[ 0 ] == 'M' ){
                printf( "%d\n" , rsq( x - 1 , y - 1 ) );
            }
            else{
                by = y;
                update( x - 1  );
            }
        }
    }
    return 0;
}
