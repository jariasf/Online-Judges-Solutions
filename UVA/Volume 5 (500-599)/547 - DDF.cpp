/*****************************************
 ***Problema: DDF
 ***ID: 547
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
#define MAX 3100
int s[ MAX ];

int fact[ 80 ]; //MAX es la raiz cuadrada del maximo valor posible para n
int factores( int n ){
    int len , l , i;
    len = (int)( sqrt( n ) );
    l = 0;
    for( i = 1 ; i <= len ; ++i ){
        if( n % i == 0 ){
            fact[ l++ ] = i;
            if( i != n/i  )
                fact[ l++ ] = n/i;
        }
    }
    int sum = 0;
    for( i = 0 ; i < l ; ++i ){
        while( fact[ i ] > 0 ){
            sum += fact[ i ] % 10;
            fact[ i ] /= 10;
        }
    }
    return sum;
}

bool seen[ MAX ];
vector< int > ady[ MAX ];
void gen(){
    int i , j , n , len;
    for( i = 0 ; i < MAX ; ++i ) s[ i ] = factores( i );

    for( i = 0 ; i < MAX ; ++i ){
        memset( seen , 0 , sizeof( seen ) );
        for( j = i ; !seen[ j ] ; j = s[ j ] ){
            seen[ j ] = 1;
            ady[ i ].push_back( j );
        }
    }
}


int main(){
    gen();

    int a , b , maxi , len , ini , q = 1 , i;
    while( scanf("%d %d" , &a , &b ) != EOF ){
        printf("Input%d: %d %d\n" , q , a , b );
        if( b < a ) swap( a , b );
        maxi = ini = -1;
        for( ; a <= b ; ++a ){
            if( (int)ady[ a ].size() > maxi ){
                maxi = (int)ady[ a ].size();
                ini = a;
            }
        }
        printf("Output%d:" , q++ , ini );
        for( i = 0 ; i < ady[ ini ].size() ; ++i ){
            printf(" %d" , ady[ ini ][ i ] );
        }
        printf("\n");
    }

    return 0;
}
