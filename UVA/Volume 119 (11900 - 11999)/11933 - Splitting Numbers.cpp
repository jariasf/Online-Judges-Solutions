/*****************************************
 ***Problema: Splitting Numbers
 ***ID: 11933
 ***Juez: UVA
 ***Tipo: Ad hoc
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

int main(){
    int n, idx[ 33 ], len;
    long long a , b;
    while( scanf("%d" , &n ) , n ){
        len = 0;
        for( int i = 0 ; i < 32 ; ++i ){
            if( n & ( 1 << i ) ){
                idx[ len++ ] = i;
            }
        }
        a = 0; b = 0;
        for( int i = 0 ; i < len ; i += 2 ){
            a += ( 1LL << idx[ i ] );
        }
        for( int i = 1 ; i < len ; i += 2 ){
            b += ( 1LL << idx[ i ] );
        }
        printf("%lld %lld\n" , a , b );
    }

    return 0;
}
