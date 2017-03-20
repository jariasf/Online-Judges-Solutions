/*****************************************
 ***Problema: Code Refactoring
 ***ID: 10879
 ***Juez: UVA
 ***Tipo: Factors
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
#define MAX 3200
int fact[  MAX ];

int main(){
    int n, len , l , t , q , i;
    scanf("%d" , &t );
    for( q = 1 ; q <= t && scanf("%d" , &n ) ; ++q ){
        printf("Case #%d: %d" , q , n );
        len = (int)( sqrt( n ) );
        l = 0;
        for( i = 1 ; i <= len ; ++i ){
            if( n % i == 0 ){
                fact[ l++ ] = i;
                if( i != n/i  )
                    fact[ l++ ] = n/i;
            }
        }
        sort( fact , fact + l );
        len = 0;
        for( i = 0 ; i < l && len < 2 ; ++i ){
            if( fact[ i ] == 1 || n == fact[ i ] ) continue;
            printf(" = %d * %d" , fact[ i ] , n/fact[ i ] );
            len++;
        }
        printf("\n");
    }
    return 0;
}
