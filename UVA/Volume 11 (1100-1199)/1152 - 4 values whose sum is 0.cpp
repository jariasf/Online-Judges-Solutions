/*****************************************
 ***Problema: 4 values whose sum is 0
 ***ID: 1152
 ***Juez: UVA
 ***Tipo: Meet in the middle
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
int A[16000100], len;
///a + b = -( c+ d )
int main(){
    int n , t;
    scanf("%d" , &t );
    for( int q = 0 ; q < t ; ++q ){
        if( q )printf("\n");
        scanf("%d" , &n );
        int a[ n ], b[ n ], c[ n ],d[ n ];
        for( int i = 0; i < n ; ++i )scanf("%d %d %d %d" , &a[ i ], &b[ i ], &c[ i ] , &d[ i ] );
        len = 0;
        for( int i = 0 ; i < n ; ++i ){
            for( int j = 0 ; j < n ; ++j ){
                A[ len++ ] = a[ i ] + b[ j ];
            }
        }
        sort( A , A + len );
        long long resp = 0;
        pair<int*, int*> find;
        for( int i = 0 ; i < n ; ++i ){
            for( int j = 0 ; j < n ; ++j ){
                find = equal_range(A, A + len , -( c[ i ] + d[ j ] ) );
                resp += find.second - find.first;
            }
        }
        printf("%lld\n" , resp );
    }
    return 0;
}
