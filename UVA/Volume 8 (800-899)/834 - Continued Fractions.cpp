/*****************************************
 ***Problema: Continued Fractions
 ***ID: 834
 ***Juez: UVA
 ***Tipo: Brute Force
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
map< int , map< int , int > > path;
map< int , map< int , bool  > > entro;
void solve( int num , int denom , int len ){
    if( denom == 0  ) return;
    int i = 0;
    if( len > 0 ) i = 1;
    for(  ; i * denom <= num ; ++i ){
        path[ num ][ denom ] = i;
        entro[ num ][ denom ] = 1;
        solve( denom , num - i * denom , len + 1 );
    }
}

void print( int num , int denom , int len ){
    if( !entro[ num ][ denom ] ) return;
    if( len == 1 ) printf(";");
    else if( len > 1 ) printf(",");
    printf("%d" , path[ num ][ denom ] );
    print( denom , num - path[ num ][ denom ] * denom , len + 1 );
}

int main(){
    int num , denom;
    while( scanf("%d %d" , &num , &denom ) != EOF ){
        if( num == 1 ){
            printf("[0;%d]\n" , denom );
            continue;
        }
        printf("[");
        entro.clear();
        path.clear();
        solve( num , denom , 0 );
        print( num , denom , 0  );
        printf("]\n");
    }
    return 0;
}
