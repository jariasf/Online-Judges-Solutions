/*****************************************
 ***Problema: The Dragon of Loowater
 ***ID: 11292
 ***Juez: UVA
 ***Tipo: Greedy , sorting
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
    int D, K , j;

    while( scanf("%d %d" , &D , &K ) && D|K ){
        long long d[ D ] , k[ K ] , total = 0;
        for( int i = 0 ; i < D ; ++i )scanf("%lld" , &d[ i ] );
        for( int i = 0 ; i < K ; ++i )scanf("%lld" , &k[ i ] );

        sort( d , d + D ); sort( k , k + K );
        j = 0;
        for( int i = 0 ; i < K ; ++i ){
             if( k[ i ] >= d[ j ] ){
                 total += k[ i ];
                 j++;
                 if( j == D )break;
             }
        }
        if( j == D )printf("%lld\n" , total );
        else printf("Loowater is doomed!\n");
    }

    return 0;
}
