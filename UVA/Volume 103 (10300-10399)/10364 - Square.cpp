/*****************************************
 ***Problema: Square
 ***ID: 10364
 ***Juez: UVA
 ***Tipo: DP + Bitmask
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

int a[ 25 ], n, suma;
int seen[ 10001 ];

bool dfs( int val , int last , int len){
    if( val == suma ){
        len++;
        val = 0;
        last = 0;
    }
    if( len == 4 ) return true;
    for( int i = last ; i < n ; ++i ){
        if( seen[ i ] )continue;
        seen[ i ] = true;
        if( ( a[ i ] + val ) <= suma ){

            if( dfs( val + a[ i ] , i + 1 , len ) ) return true;;
        }
        else{
            seen[ i ] = false;
            break;
        }
        seen[ i ] = false;
    }
    return false;
}

int main(){
    int t, sum;
    scanf("%d" , &t );
    while( t-- ){
        sum = 0;
        scanf("%d" , &n );
        for( int i = 0 ; i < n ; ++i ){ scanf("%d" , &a[ i ] ); sum += a[ i ]; }
        if( sum % 4 != 0 ){
            printf("no\n");
            continue;
        }
        suma = sum / 4;
        memset( seen , 0 , sizeof( seen ) );
        sort( a , a + n );
        if( dfs( 0 , 0 , 0 ) )printf("yes\n");
        else printf("no\n");
    }
    return 0;
}
