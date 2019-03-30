/*****************************************
 ***Problema: Easy Problem from Rujia Liu?
 ***ID: 11991
 ***Juez: UVA
 ***Tipo: Graph Theory, adjacency list
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
    map< int , vector<int> > ady;
    int n , q, x , v;
    while( scanf("%d %d" , &n , &q ) == 2 ){
        for( int i = 0 ; i < n ; ++i ){
            scanf("%d" , &x );
            ady[ x ].push_back( i + 1 );
        }
        while( q-- ){
            scanf("%d %d" , &x , &v );
            if( x <= ady[ v ].size() ){
                printf("%d\n" , ady[ v ][ x - 1 ] );
            }
            else puts("0");
        }
        ady.clear();
    }
    return 0;
}
