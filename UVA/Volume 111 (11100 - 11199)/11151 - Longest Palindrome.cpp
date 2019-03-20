/*****************************************
 ***Problema: Longest Palindrome
 ***ID: 11151
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

    //par adma -- dm
    if( left + 1 == right ){
        if( s[ left ] == s[ right ] ) return 2;
        return 1;
    }
    //impar ada - d
    else if( left == right ){
        return 1;
    }
    if( dp[ left ][ right ] != -1 ) return dp[ left ][ right ];
    int maxi = 0;
    if( s[ left ] == s[ right ] ){
        maxi = max( maxi , 2 + solve( left + 1 , right - 1 ) );
    }
    else{
        maxi = max( maxi , max( solve( left + 1 , right ) , solve( left , right - 1 ) ) );
    }
    return dp[ left ][ right ] = maxi;
}

int main(){
    int t;
    scanf("%d" ,&t );
    gets( s );
    while( t-- > 0 && gets( s ) ){
        memset( dp , -1 , sizeof( dp ) );
        printf("%d\n" , solve( 0 , strlen( s ) - 1 ) );
    }
    return 0;
}
