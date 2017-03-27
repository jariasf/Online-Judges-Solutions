/*****************************************
 ***Problema: Let's Play Magic!
 ***ID: 10978
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

int main(){
    int n, idx;
    char resp[ 53 ][ 21 ];
    char card[ 5 ] , word[ 25 ];
    while( scanf("%d" , &n ) , n ){
        vector<int> v;
        for( int i = 0 ; i < n ; ++i ) v.push_back( i );
        idx = 0;
        for( int i = 0 ; i < n ; ++i ){
            scanf("%s %s" , &card , &word );
            idx = ( idx + strlen( word ) - 1 ) % v.size();
            strcpy( resp[ v[ idx ] ] , card );
            v.erase( v.begin()  + idx );
        }
        printf("%s" , resp[ 0 ] );
        for( int i = 1 ; i < n ; ++i )printf(" %s" , resp[ i ] );
        putchar('\n');
    }

    return 0;
}
