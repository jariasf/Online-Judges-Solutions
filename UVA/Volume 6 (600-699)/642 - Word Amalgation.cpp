/*****************************************
 ***Problema: Word Amalgamation
 ***ID: 642
 ***Juez: UVA
 ***Tipo: Strings
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

int len;
bool Valid( const char *s1 , const char *s2 ){
    int a[ 27 ] , l1 = strlen( s1 ), l2 = strlen( s2 );
    memset( a , 0 ,sizeof( a ) );
    for( int i = 0 ; i < l1 ; ++i )a[ s1[ i ] - 'a' ]++;
    for( int i = 0 ; i < l2 ; ++i )a[ s2[ i ] - 'a' ]--;
    for( int i = 0 ; i < 27 ; ++i )if( a[ i ] != 0 )return false;
    return true;
}

int main(){
    char s[ 7 ];
    len  = 0;
    vector<string> v;
    while( scanf("%s" , &s ) && strcmp( s , "XXXXXX" ) != 0 ){
        v.push_back( s );
    }
    sort( v.begin() , v.end() );
    len = v.size();
    bool b;
    while( scanf("%s" , &s ) && strcmp( s , "XXXXXX" ) != 0 ){
        b = false;
        for( int i = 0 ; i < len ; ++i ){
             if( Valid( v[ i ].c_str() , s ) ){
                 printf( "%s\n" , v[ i ].c_str() );
                 b = true;
             }
        }
        if( !b )printf("NOT A VALID WORD\n");
        printf("******\n");

    }

    return 0;
}
