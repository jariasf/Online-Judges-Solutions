/*****************************************
 ***Problema: Credit Check
 ***ID: 11743
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

int sumDig( int n ){
    int s = 0;
    while( n > 0 ){
        s += n%10;
        n /= 10;
    }
    return s;
}

int main(){
    int t, sum;
    int a[ 5 ] = { 1 , 3 , 0 , 2 };
    char s1[ 5 ], s2[ 5 ] , s3[ 5 ], s4[ 5 ];
    scanf("%d" , &t );
    while( t-- ){
        sum = 0;
        scanf("%s %s %s %s" , &s1 , &s2 , &s3 , &s4 );
        sum += ( s1[ 1 ] - '0' ) + ( s1[ 3 ] - '0' ) + ( s2[ 1 ] - '0' ) + ( s2[ 3 ] - '0' ) + ( s3[ 1 ] - '0' ) + ( s3[ 3 ] - '0' ) +( s4[ 1 ] - '0' ) + ( s4[ 3 ] - '0' );
        sum += sumDig( 2 * ( s1[ 0 ] - '0' ) ) + sumDig( 2 * ( s1[ 2 ] - '0' ) ) + sumDig( 2 *( s2[ 0 ] -'0' ) ) + sumDig( 2 * (s2[ 2 ] - '0') ) + sumDig( 2*( s3[ 0 ] - '0' ) ) + sumDig( 2 * ( s3[ 2 ] - '0') ) + sumDig( 2 * ( s4[ 0 ] - '0' ) ) + sumDig( 2*( s4[ 2 ] - '0' ) );

        if( sum % 10 == 0 )printf("Valid\n");
        else printf("Invalid\n");
    }

    return 0;
}
