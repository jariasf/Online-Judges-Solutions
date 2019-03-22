/*****************************************
 ***Problema: Nested Dolls
 ***ID: 11368
 ***Juez: UVA
 ***Tipo: DP - LIS , Greedy Sorting
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

/*
4
9 9 10 10 10 9 11 10
*/

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
#define MAX 20005
struct Box{
    int w, h;
    Box( int ww, int hh ): w( ww ) , h( hh ){}
    Box(){}

    bool operator <( const Box &b1 )const{
        return ( w < b1.w && h < b1.h );
    }

}a[ MAX ];

int n;


bool f( const Box &b1 , const Box &b2 ){
     if( b1.w != b2.w ) return b1.w < b2.w;
     return b1.h > b2.h;
}

int LDS(){

    int lis[ MAX ], len , i , j , t;
    lis[ 0 ] = 1<<30;
    lis[ len = 1 ] = a[ 0 ].h;
    for( int p = 1 ; p < n ; ++p ){
        for( i = 0 , j = len ; i <= j ;){
            if( lis[ t = ( i + j )>>1 ] >= a[ p ].h ) i = t + 1; else j = t - 1;
        }
        lis[ i ] = a[ p ].h;
        if( i > len ) len = i;
    }

    return len;
}

int main(){
    int t;
    scanf("%d" , &t );
    while( t-- ){

        scanf("%d" , &n );

        for( int i = 0; i < n ; ++i ){
            scanf("%d %d" , &a[ i ].w , &a[ i ].h );
        }
        sort( a , a + n , f );
        printf("%d\n" , LDS() );
    }

    return 0;
}
