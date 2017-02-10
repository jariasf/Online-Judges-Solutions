/*****************************************
 ***Problema: The MTM Machine
 ***ID: 743
 ***Juez: UVA
 ***Tipo: Ad hoc, Simulation
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
#include <climits>
#include <fstream>
#include <list>
#include <sstream>
#include <iostream>
#include <iomanip>

using namespace std;
#define MAX 10005
string s;
int len;

bool zeros(){
    for( int i = 0 ; i < len ; ++i ) if( s[ i ] == '0' ) return true;
    return false;
}
/*
- 3X -> si X es de la forma 2X y produce Y entonces devolvemos Y2Y
- 2X -> devolvemos solamente X
*/
bool possible;
string solve( int i ){
    if( i == len ){
        return "";
    }

    string ans = "" , tipo2;
    if( s[ i ] == '3' ){
        if( i + 1 < len ){
            tipo2 = solve( i + 1 );
            if( tipo2.length() > 0 ){
                ans = tipo2 + "2" + tipo2;
            }
            else possible = false;
        }
        else possible = false;
    }
    else if( s[ i ] == '2' ){
        if( i + 1 < len ){
            ans = s.substr( i + 1 );
        }
        else possible = false;
    }
    else{
        possible = false;
        return "";
    }
    return ans;
}

int main(){
    while( cin>>s ){
        len = s.length();
        if( len == 1 && s[ 0 ] == '0' ) break;

        if( zeros() ) puts("NOT ACCEPTABLE");
        else{
            possible = true;
            string ans = solve( 0 );
            if( !possible ) puts("NOT ACCEPTABLE");
            else printf("%s\n" , ans.c_str() );
        }
    }
    return 0;
}
