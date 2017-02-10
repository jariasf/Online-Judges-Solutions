/*****************************************
 ***Problema: Anagrams by Stack
 ***ID: 732
 ***Juez: UVA
 ***Tipo: Stack
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
char s1[ 3005 ], s2[ 3005 ];
int l1 , l2;
vector<string> v;
void solve( int idx , string s, stack<char> S , int act ){
    if( act == l2 ){
       v.push_back( s );
       return;
    }
    stack<char> aux = S;
    if( idx  < l1 ){
        aux.push( s1[ idx ] );
        solve( idx + 1 , s + "i" , aux , act );
        aux = S;
    }
    if( !S.empty() && S.top() == s2[ act  ]){
        aux.pop();
        solve( idx , s + "o" , aux , act + 1 );
    }
    aux = S;
}

int main(){

    while( gets( s1 ) ){
        gets( s2 );
        l1 = strlen( s1 );
        l2 = strlen( s2 );
        if( l1 != l2 ){
            printf("[\n]\n");
            continue;
        }
        stack<char> S;
        v.clear();
        solve( 0 , "" , S , 0 );
        puts("[");
        for( int i = 0 ; i < v.size() ; ++i ){
            printf("%c" , v[ i ][ 0 ] );
            for( int j = 1 ; j < v[ i ].length() ; ++j )printf(" %c" , v[ i ][ j ] );
            printf("\n");
        }
        puts("]");
    }
    return 0;
}
