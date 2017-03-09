/*****************************************
 ***Problema: Bar Codes
 ***ID: 10721
 ***Juez: UVA
 ***Tipo: DP
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
#define MAX 55
long long dp[ MAX ][ MAX ][ 2 ];
int n , k , m;
long long solve( int sum , int prev , int cantidad ){
    if( cantidad > k || sum > n ) return 0;
    if( sum == n ){
        if( cantidad == k ) return 1;
        return 0;
    }
    if( dp[ sum ][ cantidad] [ prev ] != -1 ) return dp[ sum ][ cantidad] [ prev ];
    long long ans = 0;
    for( int i = 1 ; i <= m ; ++i ){
        ans += solve( sum + i , !prev , cantidad + 1 );
    }
    return dp[ sum ][ cantidad][ prev ] = ans;
}

int main(){
    while( scanf("%d %d %d" , &n , &k , &m ) != EOF ){
        memset( dp , -1 , sizeof( dp ) );
        printf("%lld\n" , solve( 0 , 0 , 0 ) );
    }
    return 0;
}


