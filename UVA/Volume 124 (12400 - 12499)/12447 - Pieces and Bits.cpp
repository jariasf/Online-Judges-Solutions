/*****************************************
 ***Problema: Pieces and Bits
 ***ID: 12447
 ***Juez: UVA
 ***Tipo: Bitwise
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
int n;

bool solve( ){
    int i , len , aux , val = 0;
    for( len = 0 ; len < 1<<n ; ++len ){
        printf("%d\n" , val );
        for( i = 0 ; i < n ; ++i ){
            //si tengo 0 pongo 1 en esa posicion
            if( !( len & 1<<i ) ) break;
        }
        if( i == n ) break;
        aux = ( ( 1<<n ) - 1 ) ^ ( 1<<i );
        val = val ^ aux ;
    }
}


int main(){
    int t ,i , j ;
    scanf("%d" , &t );
    while( t-- > 0 && scanf("%d" , &n ) ){
        solve();
    }
    return 0;
}
