/*****************************************
 ***Problema: Word-Search Wonder
 ***ID: 422
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
char ady[ MAX ][ MAX ] , s[ MAX ];
int n , len;
int dx[ 7 ] = { 1 ,  0 ,  0 , 1 , 1 , -1 , -1 };
int dy[ 7 ] = { 0 ,  1 , -1 , 1 , -1 , 1 , -1};
bool solve( int x , int y){
    int i , k , nx , ny;
    for( i = 0 ; i < 7 ; ++i ){
        k = 0;
        while( true ){
            nx = dx[ i ] * k + x; ny = dy[ i ] * k + y;
            if( nx >= 0 && ny >= 0 && nx < n && ny < n && ady[ nx ][ ny ] == s[ k ] ){
                k++;
            }
            else break;
            if( k == len ){
                printf("%d,%d %d,%d\n" , x + 1 , y + 1 , nx + 1 , ny + 1 );
                return true;
            }
        }
    }
    return false;
}
int main(){
    int i, j;
    scanf("%d" , &n );
    for( i = 0 ; i < n && scanf("%s" , &ady[ i ] ) ; ++i );

    while( scanf("%s" , &s) , s[ 0 ] != '0' ){
        len = strlen( s );
        for( i = 0 ; i < n ; ++i ){
            for( j = 0 ; j < n ; ++j ){
                if( solve( i , j ) ){ goto end;}
            }
        }
        end:
        if( i == n ) puts("Not found");
    }

    return 0;
}
