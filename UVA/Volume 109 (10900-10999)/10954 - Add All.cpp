/*****************************************
 ***Problema: Add All
 ***ID: 10954
 ***Juez: UVA
 ***Tipo: Greedy
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

struct cmp {
    bool operator() (const int &a, const int &b) {
        return a > b;
    }
};
int main(){

    int n , x, ans ;
    while( scanf("%d" , &n ) , n ){
        priority_queue<int , vector<int> , cmp > Q;
        for( int i = 0 ; i < n ; ++i ){
            scanf("%d" , &x );
            Q.push( x );
        }
        ans = 0;
        while( !Q.empty() ){
            x = Q.top();Q.pop();
            x += Q.top();Q.pop();
            ans += x;
            Q.push( x );
            if( Q.size() == 1 )break;
        }
        printf("%d\n" , ans );
    }

    return 0;
}
