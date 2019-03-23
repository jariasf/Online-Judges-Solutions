/*****************************************
 ***Problema: Dancing the Cheeky-Cheeky
 ***ID: 11452
 ***Juez: UVA
 ***Tipo: String Manipulation
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
char s[ MAX ];
int len , b[ MAX ];

void preprocess(){
    int i = 0 , j = -1; b[ 0 ] = -1;
    while( i < len ){
        while( j >= 0 && s[ i ] != s[ j ] ) j = b[ j ];
        i++; j++;
        b[ i ] = j;
    }
}

int main(){
    int t , circle , left , i;
    scanf("%d" , &t );
    while( t-- > 0 && scanf("%s" , &s ) ){
        len = strlen( s );
        preprocess();
        circle = len - b[ len ];
        left = len % circle;
        for( i = 0 ; i < 8 ; ++i ){
            printf("%c" , s[ left ] );
            left = ( left + 1 ) % circle;
        }
        printf("...\n");
    }
    return 0;
}
