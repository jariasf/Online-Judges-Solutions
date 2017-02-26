/*****************************************
 ***Problema: Power Strings
 ***ID: 10298
 ***Juez: UVA
 ***Tipo: KMP
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
#define MAX 1000005
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
    int t , periodic;
    while( scanf("%s" , &s ) , s[ 0 ] != '.' ){
        len = strlen( s );
        preprocess();
        periodic = len - b[ len ];
        printf("%d\n" , len/periodic );
    }
    return 0;
}
