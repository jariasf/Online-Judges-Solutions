/*****************************************
 ***Problema: Reaching the fix-point
 ***ID: 11226
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
#define MAX 500005

int dp[ MAX ];
void gen(){
    int i , j , n , sum;
    for( i = 2 ; i < MAX ; ++i ){
        n = i;
        sum = 0;
        for( j = 2 ; j * j <= n ; ++j ){
            while( n % j == 0 ){
                sum += j;
                n /= j;
            }
        }
        if( n > 1 ) sum += n;
        if( sum == i ) dp[ i ] = 1;
        else dp[ i ] = dp[ sum ] + 1;
    }
}

int main(){
    gen();
    int t , q , a , b , i , maxi;
    scanf("%d" , &t );
    for( q = 1 ; q <= t && scanf("%d %d" , &a , &b ) ; ++q ){
        if( b < a ) swap( a,  b );
        printf("Case #%d:\n" , q );
        maxi = 0;
        for( i = a ; i <= b ; ++i ) maxi = max( maxi , dp[ i ] );
        printf("%d\n" , maxi );
    }
    return 0;
}
