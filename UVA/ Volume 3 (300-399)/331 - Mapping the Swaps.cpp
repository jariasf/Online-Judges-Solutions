/*****************************************
 ***Problema: Mapping the Swaps
 ***ID: 331
 ***Juez: UVA
 ***Tipo: BFS
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
#define MAX 10
int n, a[ MAX ];
int cases;
#define psi pair< string , int >
void bfs( string ini , string finish ){
    queue< psi > Q;
    Q.push( psi( ini , 0 ) );
    string s;
    int dist[ 1005 ]; memset( dist , 0 , sizeof( dist ) );
    bool d[ 1005 ] = {  0 };
    if( ini == finish ){
        printf("There are %d swap maps for input data set %d.\n" , 0 , cases++);
        return;
    }
    while( !Q.empty() ){
        psi act = Q.front(); Q.pop();
        if( act.first == finish ){
            dist[ act.second ]++;
            d[ act.second ] = 1;
            continue;
        }
        for( int i = 0 ; i < n - 1 ; ++i ){
            s = act.first;
            if( a[ s[ i ] - '0' ] > a[ s[ i + 1 ] - '0' ] ){
                swap( s[ i ] , s[ i + 1 ] );
                Q.push( psi( s , act.second + 1 ) );
            }
        }
    }
    int mini = 1<<30, ans = 0;
    for( int i = 0 ; i < 1005 ; ++i ){
        if( d[ i ] ){
            ans = dist[ i ];
            break;
        }
    }
    printf("There are %d swap maps for input data set %d.\n" , ans , cases++);
}

#define pii pair<int ,int >
bool cmp( pii p1 , pii p2 ){
    return p1.first < p2.first;
}
int main(){
    string ini , finish;
    vector< pii > v;
    cases = 1;
    while( scanf("%d" , &n ) , n ){
        ini = "";
        v.clear();
        for( int i = 0  ; i < n ; ++i ){
            scanf("%d" , &a[ i ] );
            v.push_back( pii( a[ i ]  , i ) );
            ini += (char)( i + '0' );
        }
        sort( v.begin() , v.end() , cmp );
        finish = "";
        for( int i = 0 ; i < n ; ++i ) finish += (char)( v[ i ].second + '0' );
        bfs( ini , finish );
    }
    return 0;
}

/*
5 1 2 4 5 3
5 1 5 4 2 3
5 2 1 4 3 5
5 2 1 5 3 4
5 4 5 2 1 3
0
There are 1 swap maps for input data set 1.
There are 5 swap maps for input data set 2.
There are 2 swap maps for input data set 3.
There are 3 swap maps for input data set 4.
There are 21 swap maps for input data set 5.
*/
