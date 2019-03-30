/*****************************************
 ***Problema: I Can Guess the Data Structure!
 ***ID: 11995
 ***Juez: UVA
 ***Tipo: Data Structure
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
    int n, c[ 1001 ] ,x[ 1001 ];
    bool st, qu , pq;
    while( scanf("%d" , &n ) == 1 ){
        stack<int> S;
        queue<int> Q;
        st = true; qu = true; pq = true;
        priority_queue<int> PQ;
        for( int i = 0 ; i < n ; ++i ){
            scanf("%d %d" , &c[ i ] , &x[ i ] );
        }

        for( int i = 0 ; i < n ; ++i ){
            if( c[ i ] == 1 ){
                S.push( x[ i ] );
            }else{
                if( !S.empty() ){
                    if( S.top() != x[ i ] ) st = false;
                    else S.pop();
                }
                else st = false;
            }
            if( !st )break;
        }
        for( int i = 0 ; i < n ; ++i ){
            if( c[ i ] == 1 ){
                Q.push( x[ i ] );
            }else{
                if( !Q.empty() ){
                    if( Q.front() != x[ i ] ) qu = false;
                    else Q.pop();
                }
                else qu = false;
            }
            if( !qu )break;
        }

        for( int i = 0 ; i < n ; ++i ){
            if( c[ i ] == 1 ){
                PQ.push( x[ i ] );
            }else{
                if( !PQ.empty() ){
                    if( PQ.top() != x[ i ] ) pq = false;
                    else PQ.pop();
                }else pq = false;
            }
            if( !pq )break;
        }

        if( (st && qu) || (st && pq) || (qu && pq) || (st && pq && qu) ) puts("not sure");
        else if( st ) puts("stack");
        else if( qu ) puts("queue");
        else if( pq ) puts("priority queue");
        else puts("impossible");

    }
    return 0;
}
