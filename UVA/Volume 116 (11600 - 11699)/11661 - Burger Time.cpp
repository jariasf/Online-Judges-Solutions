/*****************************************
 ***Problema: Burger Time
 ***ID: 11661
 ***Juez: UVA
 ***Tipo: Ad hoc , simulation
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

int main(){
    int n , l, ans , lastD , lastR;
    char s[ 2000002];
    while( scanf("%d" , &n ) && n ){
        scanf("%s" , &s );
        l = strlen( s );
        ans = 2000005;
        lastD = lastR = -1;
        for( int i = 0 ; i < l ; ++i ){
            if( s[ i ] == 'Z' ){
                ans = 0;
                break;
            }
            if( s[ i ] == 'R' ){
                lastR = i;
                if( lastR != -1 && lastD != -1 ){
                    ans = min( ans , abs( lastR - lastD ) );
                }

            }
            else if( s[ i ] == 'D' ){
                lastD = i;
                if( lastR != -1 && lastD != -1 ){
                    ans = min( ans , abs( lastR - lastD ) );
                }

            }
        }
        printf("%d\n" , ans );
    }

    return 0;
}
