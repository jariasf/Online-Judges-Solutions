/*****************************************
 ***Problema: Formula 1
 ***ID: 11056
 ***Juez: UVA
 ***Tipo: Sorting + String Comparison
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
struct Data{
    string name , low;
    double time;
    int id;
    Data(){}
    bool operator < ( Data d2 ) const {
        return ( time < d2.time ) || ( time == d2.time && low < d2.low );
    }
}a[ MAX ];

int n;
char s[ MAX ];
bool isUpperCase(char c){return c>='A' && c<='Z';}
char toLowerCase(char c){return (isUpperCase(c))?(c+32):c;}

string toLow( string s ){
    int i;
    string ans = "";
    for( i = 0 ; s[ i ] ; ++i ) ans += toLowerCase( s[ i ] );
    return ans;
}

int main(){
    int i , j , k;
    double min , sec , ms;
    while( scanf("%d" , &n ) != EOF ){
        gets( s );
        for( i = 0 ; i < n && gets( s ) ; ++i ){
            stringstream ss( s );
            ss>>a[ i ].name>>s>>min>>s>>sec>>s>>ms>>s;
            a[ i ].low = toLow( a[ i ].name );
            a[ i ].time = ( min * 60 + sec ) + ms * 0.001;
        }

        sort( a , a + n );

        for( i = 0 , j = 0 , k = 1 ; i < n ; ++i , j = ( j + 1 ) %2 ){
            if( !j ) printf("Row %d\n" , k++ );
            printf("%s\n" , a[ i ].name.c_str() );
        }
        printf("\n");
    }

    return 0;
}
