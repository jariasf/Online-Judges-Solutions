/*****************************************
 ***Problema: Scrolling Sign
 ***ID: 11576
 ***Juez: UVA
 ***Tipo: KMP
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
#define MAX 100005
char s[ MAX ] , ans[ MAX ];
int len , len_long, b[ MAX ];

void preprocess(){
    int i = 0, j = -1; b[ 0 ] = -1;
    while( i < len ){
        while( j >= 0 && s[ i ] != s[ j ] ) j = b[ j ];
        i++;j++;
        b[ i ] = j;
    }
}
void solve(){
    int i = 0, j = 0;
    while( i < len_long ){
        while( j >= 0 && s[ j ] != ans[ i ] ) j = b[ j ];
        i++; j++;
    }
    for( ; j < len ; ++j ) ans[ len_long++ ] = s[ j ];
}
int main(){
    int t , n , i;

    scanf("%d" , &t );
    while( t-- > 0 && scanf("%d%d" , &len , &n ) ){
        for( i = 0 ; i < n && scanf("%s" , &s ) ; ++i ){
            if( i ){
                preprocess();
                solve();
            }
            else{
                strcpy( ans , s );
                len_long = len;
            }
        }
        printf("%d\n" , len_long );
    }

    return 0;
}
