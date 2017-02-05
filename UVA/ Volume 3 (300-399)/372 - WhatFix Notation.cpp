/*****************************************
 ***Problema: WhatFix Notation
 ***ID: 372
 ***Juez: UVA
 ***Tipo: Recursion
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

#define MAX 1005
char pre[ MAX ] , in[ MAX ];

void Solve( char *pre , char *in, int l){

    if( l < 1) return;
    if( l == 1 ){
       putchar( pre[ 0 ] );
       return;
    }
    int i;
    for( i = 0 ; i < l ; ++i ){
       if( pre[ 0 ] == in[ i ] )break;
    }

    Solve( pre + 1 , in , i );
    Solve( pre + i + 1 , in + i + 1 , l - i - 1);
    putchar( pre[ 0 ] );
}

int main(){
    while( gets( in ) ){
        gets( pre );
        printf("INFIX   => %s\n" , in );
        printf("PREFIX  => %s\n" , pre );
        printf("POSTFIX => ");
        Solve( pre , in , strlen( in ) );
        printf("\n");
    }
    return 0;
}
