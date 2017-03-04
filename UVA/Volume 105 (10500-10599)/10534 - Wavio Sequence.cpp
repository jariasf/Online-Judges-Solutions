/*****************************************
 ***Problema: Wavio Sequence
 ***ID: 10534
 ***Juez: UVA
 ***Tipo: DP, LIS
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
int n;
int a[ MAX ], lis[ MAX ], incr[ MAX ] , decr[ MAX ] , k;


int solve(){
    int len , q ,t , u , v , i;
    incr[ 0 ] = k = 1;
    lis[ k ] = a[ 0 ];
    for( int p = 1 ; p < n ; ++p ){
        if( lis[ k ] < a[ p ] ){
            incr[ p ] = ++k ;
            lis[ incr[ p ] ] = a[ p ];
            continue;
        }
        for( u = 1 , v = k ; u < v ;){
            if( lis[ t = ( u + v )>>1 ] < a[ p ] ) u = t + 1; else v = t;
        }
        incr[ p ] = u;
        if( a[ p ] < lis[ u ] ) lis[ u ] = a[ p ];
    }
    
    //inverted LIS
    decr[ n - 1 ] = k = 1;
    lis[ k ] = a[ n - 1 ];
    for( int p = n - 2 ; p >= 0 ; --p ){
         if( lis[ k ] < a[ p ] ){
             decr[ p ] = ++k;
             lis[ k ] = a[ p ];
             continue;
         }
         for( u = 1 , v = k ; u < v ; ){
             if( lis[ t = ( u + v )>>1 ] < a[ p ] ) u = t + 1; else v = t;
         }
         decr[ p ] = u;
         if( lis[ u ] > a[ p ] ) lis[ u ] = a[ p ];
    }

    for( len = 1 , i = 0 ; i < n ; ++i ){
        u = 2 * min( incr[ i ] , decr[ i ] ) - 1;
        len = ( len < u )? u : len;
        cout<<incr[ i ]<<" "<<decr[ i ]<<endl;
    }

    return len;
}

int main(){
    while( scanf("%d" , &n ) != EOF ){
        for( int i = 0 ; i < n ; ++i )scanf("%d" , &a[ i ] );
        printf("%d\n" , solve() );
    }
    return 0;
}

/*
TEST CASES
10
1 1 1 1 5 4 3 2 1 4
6
1 4 2 3 2 1
*/
