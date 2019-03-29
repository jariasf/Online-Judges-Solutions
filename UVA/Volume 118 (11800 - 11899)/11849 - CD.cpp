/*****************************************
 ***Problema: CD
 ***ID: 11849
 ***Juez: UVA
 ***Tipo: Set
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
    int n , m , x, ans;
    set<int> s;
    while( scanf("%d %d" , &n , &m ) , n | m ){
        s.clear();
        for( int i = 0 ; i < n ; ++i ){
            scanf("%d" , &x );
            s.insert( x );
        }
        for( int i = 0 ; i < m ; ++i ){
            scanf("%d" , &x );
            s.insert( x );
        }
        printf("%d\n" , n + m - s.size() );
    }
    return 0;
}
