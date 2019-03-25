/*****************************************
 ***Problema: Alarm Clock
 ***ID: 11677
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
    int h1,m2,h2,m1, t1, t2;
    while( scanf("%d %d %d %d" , &h1 , &m1 , &h2 , &m2 ) && (h1|m2|h2|m2) ){
        if( h2 == 0 ) h2 = 24;
        if( h1 == 0 ) h1 = 24;
        t1 = h1 * 60 + m1;
        t2 = h2 * 60 + m2;
        if( t2 >= t1 ) printf("%d\n" , t2 - t1 );
        else{
           printf("%d\n" , 24 * 60 - t1 + t2 );
        }
    }
    return 0;
}
