/*****************************************
 ***Problema: Chest of Drawers
 ***ID: 11420
 ***Juez: UVA
 ***Tipo: DP, conteo
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
#define MAX 70
#define L 1
#define U 0
int n , s;
long long dp[ MAX ][ MAX ][ 5 ]; //indice, cantidad actual , L/U previo

long long solve( int len , int safe , int lock ){
    if( safe > len ) return 0;
    if( len == n ){
        if( safe == s ) return 1;
        else return 0;
    }
    if( dp[ len ][ safe ][ lock ] != -1 ) return dp[ len ][ safe ][ lock ];
    long long ans = 0;
    if( lock == L ){
        ans += solve( len + 1 , safe + 1 , L );
        ans += solve( len + 1 , safe - 1 , U );
    }
    else if( lock == U ){
        ans += solve( len + 1 , safe , U );
        ans += solve( len + 1 , safe + 1 , L );
    }
    return dp[ len ][ safe ][ lock ] = ans;
}
int main(){

    while( scanf("%d %d" , &n , &s ) , n >= 0 && s >= 0 ){
        memset( dp , -1 , sizeof( dp ) );
        printf("%lld\n" , solve( 0 , 0 , U ) );
    }
    return 0;
}
