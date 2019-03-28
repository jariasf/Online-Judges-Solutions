/*****************************************
 ***Problema: Alternate Task
 ***ID: 11728
 ***Juez: UVA
 ***Tipo: Number Theory
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
int dp[ MAX ];
int main(){
    memset( dp , -1 , sizeof( dp ) );
    for( int i = 1 ; i < 999 ; ++i ){
        int sum = 0;
        for( int j = 1 ; j <= i ; ++j ){
            if( i % j == 0 )sum += j;
        }
        if( sum < MAX )dp[ sum ] = i;
    }

    int t = 1, S;
    while( scanf("%d" , &S ) && S ){
        printf("Case %d: %d\n", t++ , dp[ S ] );
    }

    return 0;
}
