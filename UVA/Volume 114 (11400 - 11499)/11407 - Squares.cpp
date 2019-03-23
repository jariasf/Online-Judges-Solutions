/*****************************************
 ***Problema: Squares
 ***ID: 11407
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
#define MAX 10005
int n;
int dp[ MAX ];
int main(){
    int t;
    scanf("%d" , &t );
    //dp inicialmente todos 0
    dp[ 1 ] = 1;
    for( int i = 2 ; i < MAX ; ++i ){
        dp[ i ] = 1<<30;
        for( int j = 1 ; j * j <= i ; ++j ){
            dp[ i ] = min( dp[ i - j * j ] + 1 , dp[ i ] );
        }
    }

    while( t-- ){
        scanf("%d" , &n );
        printf("%d\n" , dp[ n ] ) ;
    }
    return 0;
}
