/*****************************************
 ***Problema: Shopaholic
 ***ID: 11369
 ***Juez: UVA
 ***Tipo: Ad hoc , sorting
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
    int t , n;
    long long resp;
    scanf("%d" , &t );
    while( t-- ){
        scanf("%d" , &n );
        int a[ n ];
        for( int i = 0 ; i < n ; ++i ){
            scanf("%d" , &a[ i ] );
        }
        resp = 0;
        sort( a , a + n );
        for( int i = n - 1, j = 1 ; i >= 0 ; --i , ++j ){
             if( j%3 == 0) resp += a[ i ];
        }
        printf("%lld\n" , resp );
    }

    return 0;
}
