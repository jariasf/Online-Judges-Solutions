/*****************************************
 ***Problema: Magic Formula
 ***ID: 11934
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

    int a , b , c , d , L , cnt , i;
    while( scanf("%d %d %d %d %d" , &a , &b , &c , &d , &L ) , a | b | c | d | L ){
        cnt = 0;
        for( i = 0 ; i <= L ; ++i ){
            cnt += ( ( a * i * i + b * i + c ) % d == 0 );
        }
        printf("%d\n" , cnt );
    }

    return 0;
}
