/*****************************************
 ***Problema: Argus
 ***ID: 1203
 ***Juez: UVA
 ***Tipo: Priority_queue
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
#define pii pair<int , int>
struct comp {
    bool operator() (const pii &a, const pii &b) {
        return a.second > b.second || ( a.second == b.second && a.first > b.first );
    }
};
int main(){

    char s[ 25 ];
    int q , k , p, reg[ 3005 ] = { 0 } , val[ 3005 ] = { 0 };
    priority_queue< pii, vector<pii> , comp > Q;
    while( scanf("%s" , &s ) , s[ 0 ] != '#' ){
        scanf("%d %d" , &q , &p );
        reg[ q ] = p;
        val[ q ] = p;
        Q.push( pii( q , reg[ q ] ) );
    }
    scanf("%d" , &k );
    while( !Q.empty() && k-- ){
        pii act = Q.top(); Q.pop();
        printf("%d\n", act.first );
        reg[ act.first ] += val[ act.first ];
        Q.push( pii( act.first , reg[ act.first ] ) );

    }


    return 0;
}
