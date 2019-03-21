/*****************************************
 ***Problema: Smeech
 ***ID: 11291
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

double toDouble( string s ){
    stringstream ss( s );
    double n;
    ss>>n;
    return n;
}

double prob( double p , double x , double y ){
    return p * ( x + y ) + ( 1 - p ) * ( x - y );
}

int main(){
    char s[ 100005 ];
    double p;
    double x , y;
    string str;
    while( gets( s ) && strcmp( s , "()") != 0 ){
        str = "";
        int l = strlen( s );
        for( int i = 0 ; i < l ; ++i ){
            if( s[ i ] == '(' || s[ i ] == ')' ){
                str += " ";
                str += s[ i ];
                str += " ";
            }
            else str += s[ i ];
        }
        str += " ";
        stringstream ss( str );
        stack<double> S;
        while( ss>>str ){

            if( str != "(" && str != ")" ){
                S.push( toDouble( str ) );
            }
            else if( str == ")"){
                int cnt = 1;
                y = S.top() ; S.pop();
                x = S.top() ; S.pop();
                p = S.top() ; S.pop();
                S.push( prob( p , x , y ) );
            }
        }
        printf("%.2lf\n" , S.top()  );
    }

    return 0;
}
