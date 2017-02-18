/*****************************************
 ***Problema: ShellSort
 ***ID: 10152
 ***Juez: UVA
 ***Tipo: Greedy
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
    char name[ 256 ][ 128 ] , s[ 256 ];
    int resp[ 256 ] , j;
    scanf("%d" , &t );
    while( t-- ){
        scanf("%d" , &n );
        getchar();

        for( int i = 0 ; i < n ; ++i ){
            gets( name[ i ] );
        }

        for( int i = 0 ; i < n ; ++i ){
            gets( s );
            for( j = 0 ; j < n ; ++j ){
                if( strcmp( s , name[ j ] ) == 0 ){
                    break;
                }
            }
            resp[ i ] = j;
        }
        int i;
        for( i = n - 2 ; i >= 0 && resp[ i ] < resp[ i + 1 ] ; --i );

        while( i >= 0 )printf("%s\n" , name[ resp[ i-- ] ] );
        printf("\n");
    }

    return 0;
}
