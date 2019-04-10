/*****************************************
 ***Problema: Breaking Board
 ***ID: 12705
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
#define MAX 257
int cnt[ MAX ];
bool cmp( int n1 , int n2 ){
    return n1 > n2;
}
int main(){

    string line;
    int t;
    scanf("%d" , &t );
    getchar();
    while( t-- > 0 && getline( cin , line ) ){
        memset( cnt , 0 , sizeof( cnt ) );
        for( int i = 0 ; i < line.length() ; ++i ){
            if( line[ i ] == ' ')
                continue;
            cnt[ line[ i ] ]++;
        }
        vector<int> v;
        for( int i = 0 ; i < MAX ; ++i ){
            if( cnt[ i ] > 0 )
                v.push_back( cnt[ i ] );
        }
        sort( v.begin() , v.end() , cmp );
        int ans = 0 , diagonal = 1 , len = 0 , value = 2, increase = 1;
        while( len < v.size() ){
            for( int i = 0 ; i < diagonal && len < v.size() ; ++i ){
                ans += value * v[ len++ ];
            }
            if( diagonal == 6 ){
                increase = -1;
            }
            diagonal += increase;
            value++;
        }
        printf("%d\n" , ans );
    }

    return 0;
}
