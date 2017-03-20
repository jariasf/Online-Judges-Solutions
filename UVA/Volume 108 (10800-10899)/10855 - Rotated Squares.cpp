/*****************************************
 ***Problema: Rotated Squares
 ***ID: 10855
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
#include <limits>
#include <fstream>
#include <list>
#include <sstream>
#include <iostream>
#include <iomanip>

using namespace std;
#define MAX 105
int n , h;
char ady[ MAX ][ MAX ];
char table[ MAX ][ MAX ];
char aux[ MAX ][ MAX ];
void rotate(){
    for( int i = 0 ; i < h ; ++i ){
       for( int j = 0 ; j < h ; ++j){
           aux[ j ][ h - i - 1 ] = table[ i ][ j ];
       }
    }

    for( int i = 0 ; i < h ; ++i ){
       for( int j = 0 ; j < h ; ++j ){
           table[ i ][ j ] = aux[ i ][ j ];
       }
    }
}

int check(){
    int cnt = 0;
    bool finish;
    for( int i = 0 ; i <= n - h ; ++i ){
        for( int j = 0 ; j <= n - h ; ++j ){
            finish = true;
            int ii = i, jj = j;
            for( int k = 0 ; k < h ; ++k , ii++ ){
                jj = j;
                for( int q = 0 ; q < h ; ++q , jj++ ){
                    if( table[ k ][ q ] != ady[ ii ][ jj ] ){
                        finish = false;
                        k = h;
                        break;
                    }
                }
            }
            if( finish ) cnt++;
        }
    }
    return cnt;
}

int main(){
    while( scanf("%d %d" , &n , &h ) , n | h ){
        for( int i = 0 ; i < n ; ++i )scanf("%s" , &ady[ i ] );
        for( int i = 0 ; i < h ; ++i )scanf("%s" , &table[ i ] );
        printf("%d" , check());
        rotate();
        printf(" %d" , check());
        rotate();
        printf(" %d" , check());
        rotate();
        printf(" %d\n" , check());
    }
    return 0;
}
