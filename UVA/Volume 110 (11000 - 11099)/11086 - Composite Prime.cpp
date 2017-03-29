/*****************************************
 ***Problema: Composite Prime
 ***ID: 11086
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
#define MAX 1048580
//int a[ MAX ];
//#define MAX 3450
int prime[ MAX ], len;
long long p[ MAX ];
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
    len = 0;
    for( int i = 2 ; i < MAX ; ++i ) if( prime[ i ] ) p[ len++ ] = i;
}

bool composite[ MAX ];

void gen(){
    int i , j;
    for( i = 0 ; i < len ; ++i ){
        for( j = i ; j < len ; ++j ){
            if( p[ i ] * p[ j ] >= MAX ) break;
            composite[ p[ i ] * p[ j ] ] = 1;
        }
    }
}

int main(){
    sieve();
    gen();

    int n , i , x , ans;
    while( scanf("%d" , &n ) != EOF ){
        ans = 0;
        for( i = 0 ; i < n && scanf("%d" , &x ) ; ++i ) ans += composite[ x ];
        printf("%d\n" , ans );
    }

    return 0;
}
