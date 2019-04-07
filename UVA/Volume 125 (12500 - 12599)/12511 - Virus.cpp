/*****************************************
 ***Problema: Virus
 ***ID: 12511
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
#define MAX 1005
int t , len1 , len2 , A[ MAX ], B[ MAX ];
int dp[ MAX ] , prev[ MAX ];

int solve( ){
    int i , j , act , last;
    memset( dp , 0 , sizeof( dp ) );
    for( i = 0 ; i < len1 ; ++i ){
        act = 0; last = -1;
        for( j = 0 ; j < len2 ; ++j ){
            if( A[ i ] == B[ j ] && act + 1 > dp[ j ] ){
                dp[ j ] = act + 1;
                prev[ j ] = last;

            }
            if( B[ j ] < A[ i ] && act < dp[ j ] ){
                act = dp[ j ];
                last = j;
            }
        }
    }

    int len = 0 , idx = -1;
    for( i = 0 ; i < j ; ++i ){
        if( dp[ i ]> len ){
            len = dp[ i ];
            idx = i;
        }
    }
    return len;
}

int main(){
    int i , t , j;
    scanf("%d" , &t );
    while( t-- > 0 && scanf("%d" , &len1 ) ){
        for( i = 0 ; i < len1 && scanf("%d" , &A[ i ] ); ++i );
        scanf("%d" , &len2 );
        for( i = 0 ; i < len2 && scanf("%d" , &B[ i ] ) ; ++i );
        printf("%d\n" , solve());
    }

    return 0;
}
