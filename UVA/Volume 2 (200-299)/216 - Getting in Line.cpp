/*****************************************
 ***Problema: Getting in Line
 ***ID: 216
 ***Juez: UVA
 ***Tipo: TSP, DP
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
#define MAX 10
int x[ MAX ] , y[ MAX ] , n;
int prev[ MAX ];
double d[ MAX ][ MAX ];
double dist( int i , int j ){
    return sqrt( ( x[ i ] - x[ j ] ) * ( x[ i ] - x[ j ] ) + ( y[ i ] - y[ j ] ) * ( y[ i ] - y[ j ] ) );
}

int bitcount( int n ){
    int cnt = 0;
    while( n ){
        n = n & ( n - 1 );
        cnt++;
    }
    return cnt;
}
int Last;
double mini;

void print( int last ){
    if( prev[ last ] == -1 ){
        return;
    }
    print( prev[ last ] );
    printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2lf feet.\n" , x[ prev[ last ] ] , y [ prev[ last ] ] , x[ last ] , y[ last ] , dist( last , prev[ last ] ) + 16 );
}

int p[ MAX ];
void solve( int last , int mask , double sum ){
    if( bitcount( mask ) == n ){
        if( sum < mini ){
            mini = sum;
            Last = last;
            memcpy( prev , p , sizeof( p ) );
        }
        return;
    }

    for( int j = 0 ; j < n ; ++j ){
        if( !( mask & 1<<j ) ){
            p[ j ] = last;
            solve( j , mask | 1<<j , sum + dist( j , last ) + 16 );
        }
    }

}

int main(){
    int t = 1;
    double ans;
    while( scanf("%d" , &n ) , n ){
        for( int i = 0 ; i < n ; ++i ){
            scanf("%d %d" , &x[ i ] , &y[ i ] );
        }
        puts("**********************************************************");
        printf("Network #%d\n" , t++ );
        mini = 1<<30;
        for( int i = 0 ; i < n ; ++i ){
            memset( p , -1 , sizeof( p ) );
            solve( i , 1<<i , 0.0 );
        }
        print( Last );
        printf("Number of feet of cable required is %.2lf.\n" , mini );
    }
    return 0;
}
