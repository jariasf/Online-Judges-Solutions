/*****************************************
 ***Problema: Lumberjack Sequencing
 ***ID: 11942
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
    int n , x, ant;
    scanf("%d" , &n );
    printf("Lumberjacks:\n");
    bool ordered, up, f;
    while( n-- ){
        ordered = true;
        up = false;
        f = true;
        for( int i = 0 ; i < 10 ; ++i ){
            scanf("%d" , &x );
            if( i != 0 ){
                if( x > ant ){
                    if( !f && !up ) ordered = false;
                    else up = true;
                }
                else if( x <= ant && up ){
                    ordered = false;
                }
                f = false;
            }
            ant = x;
        }
        if( ordered )puts("Ordered");
        else puts("Unordered");
    }

    return 0;
}
