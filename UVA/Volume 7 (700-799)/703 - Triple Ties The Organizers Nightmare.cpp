/****************************************************
 ***Problema: Triple Ties: The Organizer's Nightmare
 ***ID: 703
 ***Juez: UVA
 ***Tipo: Complete Search
 ***Autor: Jhosimar George Arias Figueroa
 ****************************************************/

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
#define MAXN 50005
int n, ady[ MAX ][ MAX ], cnt;
int a[ MAXN ] , b[ MAXN ], c[ MAXN ];
int main(){

    while( scanf("%d" , &n ) == 1 ){
        for( int i = 0 ; i < n ; ++i )
            for( int j = 0 ; j < n ;++j )
                scanf("%d" , &ady[ i ][ j ] );
        cnt = 0;
        for( int i = 0 ; i < n ; ++i ){
            for( int j = 0 ; j < n ; ++j ){
                for( int k = 0 ; k < n ; ++k ){
                    //cycle
                    if( ady[ i ][ j ] && ady[ j ][ k ] && ady[ k ][ i ] ){
                        if( (i > j && j > k) || ( i < j && j < k ) ){
                            a[ cnt ] = i + 1, b[ cnt ] = j + 1, c[ cnt++ ] = k + 1;
                        }
                    }
                    else if( !ady[ i ][ j ] && !ady[ j ][ k ] && !ady[ k ][ i ] && !ady[ j ][ i ] && !ady[ k ][ j ] && !ady[ i ][ k ]){
                        if( ( i < j && j < k ) ){
                            a[ cnt ] = i + 1, b[ cnt ] = j + 1, c[ cnt++ ] = k + 1;
                        }
                    }
                }
            }
        }
        printf("%d\n" , cnt );
        for( int i = 0 ; i < cnt ; ++i )
            printf("%d %d %d\n" , a[ i ] , b[ i ] , c[ i ] );
    }

    return 0;
}
