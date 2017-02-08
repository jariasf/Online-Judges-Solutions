/*****************************************
 ***Problema: Image Recognizer
 ***ID: 546
 ***Juez: UVA
 ***Tipo: Simulation
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
#define MAX 105
char s[ MAX ];
int row_i , col_i , I[ MAX ][ MAX ] , T[ MAX ][ MAX ] , row_t , col_t;

void solve(){
    int i , j , ii , jj , maxi = -1<<30 , sum , x = 0 , y = 0;
    for( i = 0 ; i + row_t <= row_i ; ++i ){
        for( j = 0 ; j + col_t <= col_i ; ++j ){
            sum = 0;
            for( ii = 0 ; ii < row_t ; ++ii ){
                for( jj = 0 ; jj < col_t ; ++jj ){
                    sum += I[ i + ii ][ j + jj ] * T[ ii ][ jj ];
                }
            }
            if( sum > maxi ){
                maxi = sum;
                x = i;
                y = j;
            }
        }
    }
    printf("(%d,%d)\n" , y , x );
}

int main(){

    gets( s );
    while( strlen( s ) > 0 && s[ 0 ] != 'F' ){
        row_i = row_t = 0;
        while( gets( s ) && !isalpha( s[ 0 ] ) ){
            if( strlen( s ) == 0 ) continue;
            stringstream ss( s );
            col_i = 0;
            while( ss>>I[ row_i ][ col_i ] ){ col_i++;  }
            row_i++;
        }

        while( gets( s ) && !isalpha( s[ 0 ] ) ){
            if( strlen( s ) == 0 ) continue;
            stringstream ss( s );
            col_t = 0;
            while( ss>>T[ row_t ][ col_t ] ){ col_t++; }
            row_t++;
        }
        solve();
    }
    return 0;
}
