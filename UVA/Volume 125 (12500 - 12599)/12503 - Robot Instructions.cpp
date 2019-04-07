/*****************************************
 ***Problema: Robot Instructions
 ***ID: 12503
 ***Juez: UVA
 ***Tipo: Ad hoc
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
char s[ MAX ];

int main(){
    int t , n , i , x , idx;
    scanf("%d" , &t );
    while( t-- > 0 && scanf("%d" , &n ) ){
        gets( s );
        vector< string > v;
        for( i = 1 ; i <= n && gets( s ) ; ++i ){
            v.push_back( s );
        }
        x = 0;
        for( i = 0 ; i < n ; ++i ){
            if( v[ i ][ 0 ] == 'L' ) x--;
            else if( v[ i ][ 0 ] == 'R' ) x++;
            else{
                stringstream ss( v[ i ] );
                ss>>s>>s>>idx;
                idx--;
                while( v[ idx ][ 0 ] != 'L' && v[ idx ][ 0 ] != 'R' ){
                    stringstream ss( v[ idx ] );
                    ss>>s>>s>>idx;
                    idx--;
                }
                if( v[ idx ][ 0 ] == 'L') x--;
                else x++;
            }
        }
        printf("%d\n" , x );
    }
    return 0;
}
