/*****************************************
 ***Problema: Pay the Price
 ***ID: 10313
 ***Juez: UVA
 ***Tipo: DP - Coin Change
 ***Tiempo: 0.052 -> 19 ranking
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

#define MAXN 305
#define MAX 305
long long dp[ MAXN ][ MAXN ];
int _left , _right , n;

void solve( ){
    memset( dp , 0 , sizeof(dp));
    for( int i = 0 ; i < 301 ; ++i ){
        dp[ 0 ][ i ]= 1;
    }

    for( int i = 1 ; i < 301 ; ++i ){
        for( int j = 1 ; j < 301 ; ++j ){
            dp[ i ][ j ] = dp[ i ][ j - 1 ];
            if( i - j >= 0 )
                dp[ i ][ j ] += dp[ i - j ][ j  ];
        }
    }
}

int main(){
    string s;
    int N ,L1 ,L2;
    solve();
    while( getline( cin , s ) ){
        switch( sscanf( s.c_str() , "%d %d %d", &N , &L1, &L2 ) ){
            case 1:
                printf( "%lld\n" , dp[ N ][ N ] );
                break;
            case 2:
                if( L1 > N ) L1 = N;
                printf("%lld\n" , dp[ N ][ L1 ] );
                break;
            case 3:
                if( L1 > N && L2 > N ){
                    printf("0\n");
                    break;
                }
                if( L1 > N ) L1 = N;
                if( L2 > N ) L2 = N;
                printf("%lld\n" , dp[ N ][ L2 ] - dp[ N ][ L1 - 1 ] );
                break;
        }
    }
    return 0;
}

/*
300 2
100 10 10
100
200
200 30 75
200 111 199
300
299 88 1000
47 7 709
7 6 8
7 8 6
0 0 1
80 300
90 300
300 299
6 0 6
300 15 405
300 100 100
*/
