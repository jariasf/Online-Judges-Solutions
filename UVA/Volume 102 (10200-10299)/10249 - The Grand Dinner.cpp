/*****************************************
 ***Problema: The Grand Dinner
 ***ID: 10249
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
#define MAX 105
struct Team{
    int sz , id;
    Team( int s , int i ): sz( s ) , id( i ){}
    Team(){}
    bool operator <( const Team t1 ) const{
        return sz > t1.sz || ( sz == t1.sz && id < t1.id );
    }
}team[ MAX ] , table[ MAX ];

vector<int> ady[ MAX ];
int T[ MAX ];
int main(){
    int m , n, alu , mesa;
    bool first;
    while( scanf("%d %d" , &m , &n ) , m | n ){
        for( int i = 0 ; i < MAX ; ++i ) ady[ i ].clear();
        for( int i = 0 ; i < m ; ++i ){
            scanf("%d" , &team[ i ].sz );
            team[ i ].id = i + 1;
            T[ i ] = team[ i ].sz;
        }

        for( int i = 0 ; i < n ; ++i ){
            scanf("%d" , &table[ i ].sz );
            table[ i ].id = i + 1;
        }

        sort( team , team + m );
        for( int i = 0 ; i < m ; ++i ){
            for( int j = 0 , k = team[ i ].sz ; j < n && k > 0 ; ++j ){
                if( table[ j ].sz > 0 ){
                    table[ j ].sz--;
                    k--;
                    ady[ team[ i ].id ].push_back( table[ j ].id );
                }
            }
        }

        int i = 0;
        for(  ; i < m ; ++i ){
            if( ady[ i + 1 ].size() != T[ i ] ){
                puts("0");
                break;
            }
        }
        if( i != m ){
            continue;
        }
        puts("1");

        for( i = 1 ; i <= m ; ++i ){
            for( int j = 0 ; j < ady[ i ].size() ; ++j ){
                if( j ) printf(" ");
                printf("%d" , ady[ i ][ j ] );
            }
            printf("\n");
        }

    }
    return 0;
}
