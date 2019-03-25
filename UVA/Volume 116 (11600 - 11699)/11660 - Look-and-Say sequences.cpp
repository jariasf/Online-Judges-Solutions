/*****************************************
 ***Problema: Look-and-Say sequences
 ***ID: 11660
 ***Juez: UVA
 ***Tipo: Math
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
#define MAX 2005
char s[ MAX ] , aux[ MAX ];

int main(){
    int xn , pos , i , x1 , k , j , cnt , len;
    while( scanf("%d %d %d" , &x1 , &xn , &pos ) , x1 | xn  |pos ){
        pos--;
        sprintf( s , "%d" , x1 );
        for( i = 1 ; i < xn ; ++i ){
            aux[ 0 ] = '\0';
            for( j = 0 ; s[ j ] && j <= 1000 ; ++j ){
                k = j + 1;
                cnt = 1;
                while( s[ k ] && s[ k ] == s[ j ] ){
                    k++;
                    cnt++;
                }
                sprintf( aux + strlen( aux ) , "%d%c" , cnt , s[ j ] );
                j = k - 1;
            }
            strcpy( s , aux );
        }
        printf("%c\n" , s[ pos ] );
    }

    return 0;
}

