/*****************************************
 ***Problema: Tiling Up Blocks
 ***ID: 1196
 ***Juez: UVA
 ***Tipo: DP, LIS
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
#define pii pair<int,int>
#define mp make_pair
int n;
pii a[ MAX ];
int dp[ MAX ];
bool cmp( pii p1 , pii p2 ){
    if( p1.first <= p2.first && p1.second <= p2.second )
        return 1;
    return p1 < p2;
}

int main(){
    int x , y;
    while( scanf("%d" , &n ) , n ){
        for( int i = 0 ; i < n && scanf("%d %d" , &x , &y) ; ++i ){
            a[ i ] = mp( x , y );
            dp[ i ] = 1;
        }
        sort( a , a + n );
        for( int i = 0 ; i < n ; ++i ){
            for( int j = i + 1 ; j < n ; ++j ){
                if( a[i].first <= a[j].first && a[i].second <= a[j].second ){
                    dp[ j ] = max( dp[ j ] , dp[ i ] + 1 );
                }
            }
        }
        int maxi = 0;
        for( int i = 0 ; i < n ; ++i )
            maxi = max( maxi , dp[ i ] );
        printf("%d\n" , maxi );
    }
    printf("*\n");
    return 0;
}
