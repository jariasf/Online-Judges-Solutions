/*****************************************
 ***Problema: Digital Fortress
 ***ID: 11716
 ***Juez: UVA
 ***Tipo: Ad hoc, strings
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
    int t , l;
    double sq;
    char s[ 100005 ];
    scanf("%d\n" , &t );
    while( t-- ){
        gets( s );
        l = strlen( s );
        sq = sqrt( l );
        if( sq == ( int )sq ){
            for( int i = 0 ; i < (int) sq ; ++i ){
                for( int j = 0, idx = 0 ; j < (int)sq ; ++j ){
                    putchar( s[ i + idx ] );
                    idx += (int) sq;
                }
            }
            putchar('\n');
        }
        else printf("INVALID\n");

    }

    return 0;
}
