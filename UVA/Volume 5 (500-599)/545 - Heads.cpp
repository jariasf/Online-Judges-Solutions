/*****************************************
 ***Problema: Head
 ***ID: 545
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
#include <climits>
#include <fstream>
#include <list>
#include <sstream>
#include <iostream>
#include <iomanip>

using namespace std;
#define EPS 1e-9
#define MAX 9005
double b[ MAX ];
int main(){
    int n , i , digit , t;
    b[ 0 ] = 1;
    for( i = 1 ; i < MAX ; ++i ){
        b[ i ] = b[ i - 1 ]/2.0;
        if( b[ i ] < 1 ) b[ i ] *= 10.0;
    }
    scanf("%d" , &t );
    while( t-- > 0 && scanf("%d" , &n ) ){
        digit = floor( n * log10( 2 ) ) + 1;
        printf("2^-%d = %.3lfE-%d\n" , n , b[ n ] + EPS , digit );
    }
    return 0;
}
