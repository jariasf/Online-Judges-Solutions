/*****************************************
 ***Problema: Counting Chaos
 ***ID: 11309
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

string toStr( int n ){
    stringstream ss;
    ss<<n;
    string s;
    ss>>s;
    return s;
}

bool isPali( string s ){
    int l = s.length();
    for( int i = 0 ; i < l ; ++i ){
        if( s[ i ] != s[ l - i - 1 ] )return false;
    }
    return true;
}

int main(){

    int t , h , m;
    scanf("%d" , &t );
    while( t-- ){
        scanf("%d:%d" , &h , &m );

        while( 1 ){
            string cad = "";
            m++;
            if( m == 60 ){
                m = 0;
                h++;
                if( h == 24 ) h = 0;
            }

            if( h > 9 ){
                cad += toStr( h );
                if( m < 10 ) cad += "0";
            }
            if( h < 10 && h > 0 ) cad+= toStr( h );
            cad += toStr( m );

            if( isPali( cad ) ){
                if( h < 10 ) printf("0");
                printf("%d:" ,h);
                if( m < 10 )printf("0");
                printf("%d\n" , m );
                break;
            }
        }

    }
    return 0;
}

