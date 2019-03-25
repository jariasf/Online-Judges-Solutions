/*****************************************
 ***Problema: Small Factors
 ***ID: 11621
 ***Juez: UVA
 ***Tipo: Brute Force
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
#define MAX 1025
long long v[ MAX ];
int len;
void init(){
    int i , j;
     len = 0;
    for( i = 0 ; i < 32 ; ++i )
        for( j = 0 ; j < 32 ; ++j )
            v[ len++ ] = (long long )pow( 2 , i ) * ( long long )pow( 3 , j );
}

int main(){

    long long n;
    init();
    sort( v , v + len );
    int idx;
    while( scanf("%lld" , &n ) ,n ){
        idx = lower_bound( v , v + len , n ) - v;
        while( v[ idx ] < n ) idx++;
        printf("%lld\n" , v[ idx ] );
    }
    return 0;
}
