/*****************************************
 ***Problema: Happy Number
 ***ID: 10591
 ***Juez: UVA
 ***Tipo: Cycle Finding
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

int f( int n ){
    int sum = 0;
    while( n > 0){
        sum += ( n % 10 )* ( n %10 );
        n /= 10;
    }
    return sum;
}

void TortoiseHare(int x){
    int s = 0, p = 1;

    int i = f(x), j = f(f(x));

    while (i != j) i = f(i), j = f(f(j));

    j = i; i = x;

    while (i != j) i = f(i), j = f(j), s++;

    j = f(i);

    while (i != j) j = f(j), p++;

    if( p == 1 )printf("%d is a Happy number.\n",x);
    else printf("%d is an Unhappy number.\n",x);
}

int main(){
    int n;
    int t;
    scanf("%d", &t );
    for( int i = 1; i <= t; ++i ){
        scanf("%d", &n);
        printf("Case #%d: ", i);
        TortoiseHare( n );
    }
    return 0;
}
