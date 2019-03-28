/*****************************************
 ***Problema: Numbering Roads
 ***ID: 11723
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
#include <limits>
#include <fstream>
#include <list>
#include <sstream>
#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    int r , n , q = 1 , i;
    while( scanf("%d %d" , &r , &n ) , r | n ) {
        printf("Case %d: " ,q++ );
        for( i = 1 ; i <= 27 ; ++i ){
            if( n * i >= r ){
                printf("%d\n" , i - 1 );
                break;
            }
        }
        if( i > 27 ) puts("impossible");
    }

    return 0;
}
