/*****************************************
 ***Problema: Andy's Second Dictionary
 ***ID: 11062
 ***Juez: UVA
 ***Tipo: Map
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
    char s[ 1005 ];
    int l;
    string con = "";
    while( gets( s ) ){
        l = strlen( s );
        if( l > 0 && s[ l - 1 ] == '-' ){
            s[ l - 1 ] = '\0';
            con += s;
        }
        else{
            con += s;
            con += " ";
        }
    }
    l = con.length();
    for( int i = 0 ; i < l ; ++i ){
        con[ i ] = tolower( con[ i ] );
        if( !isalpha( con[ i ] ) && con[ i ] != '-' ) con[ i ] = ' ';
    }
    stringstream ss( con + " " );
    map<string , int > mp;
    map<string , int>::iterator it;

    while( ss>>con ) mp[ con ] = 1;

    for( it = mp.begin() ; it != mp.end() ; ++it ){
        printf("%s\n" , (*it).first.c_str() );
    }

    return 0;
}
