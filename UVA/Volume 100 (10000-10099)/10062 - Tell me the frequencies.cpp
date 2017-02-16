/*****************************************
 ***Problema: Tell me the frequencies
 ***ID: 10062
 ***Juez: UVA
 ***Tipo: ad hoc, sorting
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <algorithm>
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
#include<fstream>
#include <list>
#include <sstream>
#include <iostream>
#include <iomanip>

using namespace std;
#define MAX 1005
bool cmp( pair<int ,int> p1 , pair<int, int> p2 ){
    return p1.first < p2.first || ( p1.first == p2.first && p1.second > p2.second );
}

int main(){
    char s[MAX];
    int l, idx;
    bool b = false;
    while( gets(s) ){
        if( b ) putchar( '\n' );
        b = true;
        l = strlen( s );
        int a[ 130 ] = { 0 };
        for( int i = 0 ; i < l ; ++i ){

            a[ (int)s[ i ] ]++;
        }
        vector< pair<int ,int > > v;
        for( int i = 0 ; i < 130 ; ++i ){
           if( a[ i ] ) v.push_back( make_pair( a[ i ] , i) );
        }
        sort( v.begin() , v.end() , cmp );

        for( int i = 0 ; i < v.size(); ++i ){
            printf("%d %d\n", v[ i ].second , v[ i ] .first);
        }

    }

    return 0;
}
