/*****************************************
 ***Problema: Probability|Given
 ***ID: 11181
 ***Juez: UVA
 ***Tipo: Probability
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
#include <climits>
#include <fstream>
#include <list>
#include <sstream>
#include <iostream>
#include <iomanip>

using namespace std;

#define MAX 22
double a[ MAX ] , P[ MAX ];
int main(){
    int r , i , j , q = 1 , n;
    while( scanf("%d %d" , &n , &r ) , n | r ){
        for( i = 0 ; i < n && scanf("%lf" , &a[ i ] ) ; ++i ) P[ i ] = 0.0;
        double denom = 0.0;

        for( i = 0 ; i < 1<<n ; ++i ){
            if( __builtin_popcount( i ) != r ) continue;
            double p = 1.0;
            for( j = 0 ; j < n ; ++j ){
                if( i & 1<<j ) p *= a[ j ];
                else p *= ( 1 - a[ j ] );
            }
            denom += p;
            for( j = 0 ; j < n ; ++j ) if( i & 1<<j ) P[ j ] += p;
        }

        printf("Case %d:\n" , q++ );
        for( i = 0 ; i < n ; ++i ){
            printf("%.6lf\n" , P[ i ]/denom );
        }
    }

    return 0;
}
