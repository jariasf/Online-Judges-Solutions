/*****************************************
 ***Problema: Gourmet Games
 ***ID: 11313
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
    int t , n , m , ans;
    scanf("%d" , &t );
    while( t-- > 0 && scanf("%d %d" , &n , &m ) ){
        ans = 0;
        while( n > 0 ){
            n -= m;
            n++;
            ans++;
            if( n == 1 ) break;
            if( n < m ){
                ans = -1;
                break;
            }
        }
        if( ans == -1 ) puts("cannot do this");
        else printf("%d\n" , ans );
    }

    return 0;
}
