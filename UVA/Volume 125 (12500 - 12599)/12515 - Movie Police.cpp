/*****************************************
 ***Problema: Movie Police
 ***ID: 12515
 ***Juez: UVA
 ***Tipo: Brute Force
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
#define MAX 105
#define MAXN 1005
int n , sz[ MAXN ];
char s[ MAX ] , dic[ MAXN ][ MAX ];
int main(){
    int i , Q , maxi , idx , j , k;
    scanf("%d %d" , &n , &Q );
    for( i = 0 ; i < n && scanf("%s" , dic[ i ] ) ; ++i ) sz[ i ] = strlen( dic[ i ] );
    while( Q-- > 0 && scanf("%s" , s ) ){
        maxi = idx = -1;
        int len = strlen( s ) , cnt , mx;
        for( i = 0 ; i < n ; ++i ){
            if( sz[ i ] >= len ){
                mx = 0;
                for( j = 0 ; j <= sz[ i ] - len ; ++j ){
                    cnt = 0;
                    for( k = 0 ; k < len ; ++k ){
                        if( s[ k ] == dic[ i ][ j + k ] ){
                            cnt++;
                        }
                    }
                    mx = max( mx , cnt );
                }
                if( mx > maxi ){
                    maxi = mx;
                    idx = i + 1;
                }
            }
        }
        printf("%d\n" , idx );
    }

    return 0;
}
