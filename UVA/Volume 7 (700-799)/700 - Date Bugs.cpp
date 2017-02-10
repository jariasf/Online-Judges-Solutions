/*****************************************
 ***Problema: Date Bugs
 ***ID: 700
 ***Juez: UVA
 ***Tipo: Simulation
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
#define MAX 10000
int main(){
    int q = 1 , n, C[ MAX ] , a[ MAX ] , b[ MAX ], maxi ;
    int seen[ MAX ];
    while( scanf("%d" , &n ) , n ){
        maxi = 0;
        for( int i = 0 ; i < n ; ++i ){
            scanf("%d %d %d" , &C[ i ] , &a[ i ] , &b[ i ]);
            if( a[ i ] > maxi ){
                maxi = a[ i ];
            }
        }
        int op = maxi, cnt;
        bool bb = false;
        printf("Case #%d:\n" , q++);
        while( op < MAX ){
            cnt = 0;
            for( int i = 0 ; i < n ; ++i ){
                int op2 = ( ( op - a[ i ] ) % ( b[ i ] - a[ i ] ) );
                if( ( op2  == ( C[ i ] - a[ i ] ) ) ){
                    cnt++;
                }
                else break;
            }
            if( cnt == n ){
                bb = true;
                printf("The actual year is %d.\n" , op );
                break;
            }
            op++;
        }
        if( !bb )puts("Unknown bugs detected.");
        putchar('\n');
    }
    return 0;
}
