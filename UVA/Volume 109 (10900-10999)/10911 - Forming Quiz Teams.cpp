/*****************************************
 ***Problema: Forming Quiz Teams
 ***ID: 10911
 ***Juez: UVA
 ***Tipo: DP + bitmask
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <cmath>
#include <iostream>
using namespace std;
#define MAX 9
#define MAXN 20
int n, y[ MAXN ], x[ MAXN ];
char s[ 25 ];
double d[ MAXN ][ MAXN ];
double dp[ MAXN ][ ( 1<<16 ) + 5 ];

double dist( int x1 , int y1 , int x2 , int y2 ){
	return sqrt( ( x1 - x2 ) * ( x1 - x2 ) + ( y1 - y2 ) * ( y1 - y2 ) );
}

int bitcount( int n ){
    int cnt = 0;
    while( n ){
        n = n & ( n - 1 );
        cnt++;
    }
    return cnt;
}

double solve( int last , int mask  ){
    int bc = bitcount( mask );
    if( bc == n ) return 0;
    if( dp[ last ][ mask ] != -1 ) return dp[ last ][ mask ];
    double mini = 1<<30;
    for( int i = 0 ; i < n ; ++i ){
        if( !( mask & 1<<i ) ){
            if( bc & 1 ) mini = min( mini , d[ last ][ i ] + solve( i , mask | 1<<i  ) );
            else mini = min( mini , solve( i , mask | 1<<i ) );
        }
    }
    return dp[ last ][ mask ] = mini;
}

int main(){
    int q = 1;
    while( scanf("%d" , &n ) , n ){
        n *= 2;
        for( int i = 0 ; i < n ; ++i ) scanf("%s %d %d" , &s , &x[ i ] , &y[ i ] );
        for( int i = 0 ; i < n ; ++i ){
            for( int j = i + 1 ; j < n ; ++j ){
                d[ j ][ i ] = d[ i ][ j ] = dist( x[ i ] , y[ i ] , x[ j ] , y[ j ] );
            }
        }

        for( int i = 0 ; i < n;  ++i )
            for( int j = 0 ; j < 1<<n ; ++j )
                dp[ i ][ j ] = -1;

        printf("Case %d: %.2lf\n", q++ , solve( 0 , 1 ) );

    }
    return 0;
}
