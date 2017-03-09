/*****************************************
 ***Problema: String to Palindrome
 ***ID: 10739
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
char s[ MAX ];
int dp[ MAX ][ MAX ];

int solve( int left , int right ){
    if( left + 1 == right ){
        if( s[ left ] == s[ right ] ) return 0;
        return 1;
    }
    if( left == right ){
        return 0;
    }
    if( dp[ left ][ right ] != -1 ) return dp[ left ][ right ];
    int mini = 1<<30;
    if( s[ left ] == s[ right ] ) mini = min( mini , solve( left + 1 , right - 1 ) );
    else{
        mini = min( mini , min( 1 + solve( left + 1 , right ) , min( 1 + solve( left , right - 1 ) ,  1 + solve( left + 1 , right - 1 ) ) ) );
    }
    return dp[ left ][ right ] = mini;
}

int main(){
    int t , q;
    scanf("%d" , &t );
    for( q = 1 ; q <= t && scanf("%s" , &s ) ; ++q ){
        memset( dp , -1 , sizeof( dp ) );
        printf("Case %d: %d\n" , q , solve( 0 , strlen( s ) - 1 ) );
    }
    return 0;
}
