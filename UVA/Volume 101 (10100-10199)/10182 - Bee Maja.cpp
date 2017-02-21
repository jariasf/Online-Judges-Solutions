/*****************************************
 ***Problema: Bee Maja
 ***ID: 10182
 ***Juez: UVA
 ***Tipo: Ad hoc, math, brute force
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

int main(){
    int n , pos , aux , i , cnt , x , y;
    while( scanf("%d" , &n ) != EOF ){
        if( n == 1 ){
            puts("0 0");
            continue;
        }
        cnt = 1;
        for( pos = 1 ; ; ++pos ){
            cnt += 6 * pos;
            if( cnt >= n ) break;
        }
        cnt -= 6 * pos;
        aux = ( n - 1 - cnt )/pos;
        if( aux == 0 ){
            y = n - cnt;
            x = pos - ( n - cnt );
        }
        else if( aux == 1 ){
            cnt += pos;
            x = -1 * ( n - cnt );
            y = pos;
        }
        else if( aux == 2 ){
            cnt += aux * pos;
            x = -1 * pos;
            y = pos - ( n - cnt );
        }
        else if( aux == 3 ){
            cnt += aux * pos;
            y = -1 * ( n - cnt );
            x = ( n - cnt ) - pos;
        }
        else if( aux == 4 ){
            cnt += aux * pos;
            x = ( n - cnt );
            y = -pos;
        }
        else{
            cnt += aux * pos;
            x = pos;
            y = ( n - cnt - pos);
        }
        printf("%d %d\n" , x , y );
    }
    return 0;
}
