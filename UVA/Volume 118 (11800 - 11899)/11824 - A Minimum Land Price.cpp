/*****************************************
 ***Problema: A Minimum Land Price
 ***ID: 11824
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

int pot( int a , int b ){
    int r = 1;
    for( int i = 1 ; i <= b ; ++i ) r *= a ;
    return r;
}

int main(){

    int t, len, a[ 50 ], n, j;
    int res;
    scanf("%d" , &t);
    while( t-- ){
        len = 0;
        while( scanf( "%d" , &n ) && n ){ a[ len++ ] = n;}
        res = 0;
        sort( a , a + len );
        int i;
        for( i = len - 1 , j = 1 ; i >= 0 ; --i , ++j ){
            res += 2 * pot( a[ i ] , j );
            if( res > 5000000 ){
                break;
            }
        }
        if( i >= 0 )puts("Too expensive");
        else printf("%d\n" , res);
    }

    return 0;
}
