/*****************************************
 ***Problema: Simply Syntax
 ***ID: 271
 ***Juez: UVA
 ***Tipo: Ad hoc Strings
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
//Gramatica
/*
S : p|q|r|s|t|u|v|w|x|y|z| NS | CSS | DST | EST | IST
*/
#define MAX 300
char s[ MAX ];

int correct(){
    int i , k;
    for( i = 0 , k = 1 ; s[ i ] ; ++i ){
        if( s[ i ] == 'C' || s[ i ] == 'D' || s[ i ] == 'E' || s[ i ] == 'I' ){
            if( k == 0 ) return 0;
            k++;
        }
        else if( s[ i ] >= 'p' && s[ i ] <= 'z' ){
            if( k == 0 ) return 0;
            k--;
        }
        else{
            if( k == 0 ) return 0;
        }
    }
    return ( k == 0 );
}

int main(){
    while( gets( s ) ){
        printf( "%s\n" , (correct() )?"YES":"NO" );
    }
    return 0;
}
