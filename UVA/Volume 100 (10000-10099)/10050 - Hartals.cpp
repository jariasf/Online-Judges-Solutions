/*****************************************
 ***Problema: Hartals
 ***ID: 10050
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
#define MAX 3700
bool seen[ MAX ];
int main(){
    int t , d, n, x;
    scanf("%d" , &t );
    while( t-- > 0 && scanf("%d %d" , &d ,  &n ) ){
        memset( seen , 0 , sizeof( seen ) );
        for( int i = 0 ; i < n && scanf("%d" , &x ) ; ++i ){
            int inc = x;
            while( inc <= d ){
                seen[ inc ] = 1;
                inc += x;
            }
        }

        int f = 6, s = 7, ans = 0;
        for( int i = 1 ; i <= d ; ++i ){
            if( i == f ){
                f += 7;
                continue;
            }
            if( i == s ){
                s += 7;
                continue;
            }
            if( seen[ i ] ){
                ans++;
            }
        }
        printf("%d\n" , ans );
    }
    return 0;
}
