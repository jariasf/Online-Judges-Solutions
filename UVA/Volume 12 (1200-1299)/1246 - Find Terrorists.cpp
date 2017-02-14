/*****************************************
 ***Problema: Find Terrorists
 ***ID: 1246
 ***Juez: UVA
 ***Tipo: Prime Factorization
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

int prime[ MAX ];
void sieve(){
    memset( prime , 1 , sizeof( prime ) );
    prime[ 0 ] = 0;
    prime[ 1 ] = 0;

    for(int i = 2 ; i * i <= MAX ; ++i ){
        if( prime[ i ] ){
            for(int k = 2 ; k * i <= MAX ; ++k){
                prime[ k * i ] = 0;
            }
        }
    }
}

bool getFactors( int n ){
    map< int , int > f;
    for( int i = 2 ; i * i <= n ; ++i ){
        while( n % i == 0 ){
            n /= i;
            f[ i ]++;
        }
    }
    if( n > 1 ) f[ n ]++;
    map< int , int > :: iterator it;
    int ans = 1;
    for( it = f.begin() ; it != f.end() ; ++it ) ans *= ( it -> second + 1 );
    return prime[ ans ];
}

bool correct[ MAX ];

int main(){
    int t , i , a , b;
    scanf("%d" , &t );
    sieve();
    for( i = 2 ; i < MAX ; ++i ){
        correct[ i ] = getFactors( i );
    }
    bool possible;
    while(  t-- > 0 && scanf("%d %d" , &a , &b ) ){
        possible = false;
        for( i = a ; i <= b ; ++i ){
            if( correct[ i ] ){
                if( possible ) printf(" ");
                printf("%d" , i );
                possible = true;
            }
        }
        if( !possible ) printf("-1");
        printf("\n");

    }

    return 0;
}
