/*****************************************
 ***Problema: Hello World!!
 ***ID: 11636
 ***Juez: UVA
 ***Tipo: Ad hoc, recurrencia
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
    int n, i, q = 1;
    while( scanf("%d" , &n ) && n >= 0 ){
        for( i = 0 ; i < 14 ; ++i ) if( ( 1<<i ) >= n )break;
        printf("Case %d: %d\n" , q++ , i );
    }

    return 0;
}
