/*****************************************
 ***Problema: Hyperactive Girl
 ***ID: 12245
 ***Juez: UVA
 ***Tipo: DP
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
#define MOD 100000000
#define MAX 125

struct Node{
    int ini , fin;
    bool operator < ( const Node &n1 ) const{
        return ini < n1.ini;
    }
    Node(){}
}a[ MAX ];
int n , m;

map< int , map< int , int > > dp[ MAX ];
int solve( int posIni , int posFin ,  int last  ){
    if( posFin >= m ) return 1;
    if( last == n ){
        return 0;
    }

    if( dp[ last ].find( posIni )  != dp[ last ].end() ){
       if( dp[ last ][ posIni ].find( posFin ) != dp[ last ][ posIni ].end() ){
            return dp[ last ][ posIni ][ posFin ] % MOD;
       }
    }
    int ans = 0;
    for( int i = last ; i < n ; ++i ){
        if( posIni < a[ i ].ini && a[ i ].ini <= posFin && posFin < a[ i ].fin ){
            ans = (ans % MOD + solve( posFin  , a[ i ].fin , i + 1 ) % MOD ) % MOD;
        }
    }
    return dp[ last ][ posIni ][ posFin ] = ans % MOD;
}

int main(){
    while( scanf("%d %d" , &m , &n ) , n | m ){
        for( int i = 0 ; i < n ; ++i ){
            scanf("%d %d" , &a[ i ].ini , &a[ i ].fin );
        }
        sort( a , a + n );
        int ans = 0;
        for( int i = 0 ; i < n ; ++i ){
            if( a[ i ].ini == 0 ){
                ans = ans % MOD + solve( a[ i ].ini , a[ i ].fin , i + 1  ) % MOD;
                ans %= MOD;
            }
        }
        printf("%d\n" , ans );
        for( int i = 0 ; i < MAX ; ++i ) dp[ i ].clear();
    }

    return 0;
}
