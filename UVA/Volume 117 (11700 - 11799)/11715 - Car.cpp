/*****************************************
 ***Problema: Car
 ***ID: 11715
 ***Juez: UVA
 ***Tipo: Ad hoc, Fisica
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
double u , v , t , a , s;
int main(){
    int n, q = 1;
    while( scanf("%d" , &n ) && n ){
        printf("Case %d: " , q++ );
        if( n == 1 ){
            scanf("%lf %lf %lf" , &u , &v , &t );
            a = ( v - u )/t;
            s = ( v * v - u * u )/( 2.0 * a);
            printf("%.3lf %.3lf\n" , s , a );
        }
        else if( n == 2 ){
            scanf("%lf %lf %lf" , &u , &v , &a );
            t = ( v - u )/a;
            s = ( v * v - u * u )/( 2.0 * a);
            printf("%.3lf %.3lf\n" , s , t );
        }
        else if( n == 3 ){
            scanf("%lf %lf %lf" , &u , &a , &s );
            v = sqrt( u * u + 2 * a * s );
            t = ( v - u )/a;
            printf("%.3lf %.3lf\n" , v , t );
        }
        else{
            scanf("%lf %lf %lf" , &v , &a , &s );
            u = sqrt( v * v - 2 * a * s );
            t = ( v - u )/a;
            printf("%.3lf %.3lf\n" , u , t );
        }
    }

    return 0;
}
