/*****************************************
 ***Problema: Automatic Editing
 ***ID: 10115
 ***Juez: UVA
 ***Tipo: String
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
    int n;
    char cad[ 205 ];
    string s;
    char find[ 12 ][ 90 ], replace[ 12 ][ 90 ];
    while( scanf("%d" , &n ) , n ){
        gets( cad );
        for( int i = 0 ; i < n ; ++i ){
            gets( find[ i ] );
            gets( replace[ i ] );
        }
        gets( cad );
        s = string( cad );
        int k = 0, aux, i = 0 , j;
        for( i = 0 ; i < n ; ++i ){
            string f = string( find[ i ] );
            k = 0;
            while( k < s.length() ){
                aux = k;
                j = 0;
                for( ; j < f.length() && aux < s.length() ; ++j ){
                    if( s[ aux ] == f[ j ] ) aux++;
                    else break;
                }
                if( j == f.length() ){
                    s.replace( k , f.length() , string(replace[ i ] ) );
                    k = 0;
                }
                else k++;
            }
        }
        printf("%s\n" , s.c_str() );
    }
    return 0;
}
