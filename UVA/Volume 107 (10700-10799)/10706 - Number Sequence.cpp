/*****************************************
 ***Problema: Number Sequence
 ***ID: 10706
 ***Juez: UVA
 ***Tipo: Binary Search
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
#define MAX 65550
long long sum[ MAX ];

int main(){
    for( long long i = 1 ; i < MAX ; ++i ){
        sum[ i ] = ( i * ( i + 1 ) )/2LL;
    }
    int t, idx;
    scanf("%d" , &t );
    long long val;
    while( t-- ){
        scanf("%lld" , &val );
        idx = lower_bound( sum , sum + MAX , val ) - sum;
        printf("%lld\n" , val - sum[ idx - 1 ] );
    }
    return 0;
}
