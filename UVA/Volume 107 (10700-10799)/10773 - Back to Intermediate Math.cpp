/*****************************************
 ***Problema: Back to Intermediate Math
 ***ID: 10773
 ***Juez: UVA
 ***Tipo: Math
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
    int t , q , i;
    double ans , u , v , d;
    scanf("%d" , &t );
    for( q = 1 ; q <= t && scanf("%lf %lf %lf" , &d , &v , &u ) ; ++q ){
        printf("Case %d: " , q );
        if( u == 0 || u <= v || v == 0 ) puts("can't determine");
        else printf("%.3lf\n" , fabs( ( d/u ) - ( d/ sqrt( u * u - v * v ) ) ) );
    }
    return 0;
}
