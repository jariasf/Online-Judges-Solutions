/*****************************************
 ***Problema: The Sum Equals the Product
 ***ID: 10483
 ***Juez: UVA
 ***Tipo: Brute Force + Math
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
#define EPS 1e-8
#define MAX 400
struct Data{
    int a , b , c , sum;
    Data( int aa , int bb , int cc , int ss ) : a( aa ) , b( bb ) , c( cc ) , sum( ss ){}
    Data(){}
    bool operator < ( Data d2 ) const{
        return sum < d2.sum || ( sum == d2.sum && a < d2.a ) ||
        ( sum == d2.sum && a == d2.a && b < d2.b );
    }
}v[ MAX ];

int main(){
    double n , m;
    scanf("%lf %lf" , &n , &m );
    int n1 = n * 100 , n2 = m * 100 , i , a , b , c;
    //int n1 = ( n + EPS ) * 100 , n2 = ( m + EPS ) * 100 , i , a , b , c;
    int ii;

    i = 25600; ii = i * 10000;
    int len = 0;
    for( a = 1 ; a <= i ; ++a ){
        if( a * a * a > ii ) break;
        for( b = a ; b <= i ; ++b ){
            if( a * b > ii  || a + b > i || a * b * b > ii ) break;
            if( ( a * b - 10000 > 0 ) && ( ( a + b )* 10000 ) % (a * b - 10000) == 0 ){
                c = ( ( a + b ) * 10000 )/( a * b - 10000 );
                if( c < a || c < b ) break;
                if( a * b * c == ( a + b + c ) * 10000 ){
                    if( a + b + c >= n1 && a + b + c <= n2 ){
                        v[ len++ ] = Data( a , b , c , a + b + c );
                    }
                }
            }
        }
    }
    sort( v , v + len );
    for( i = 0 ; i < len ; ++i ){
        a = v[ i ].a; b = v[ i ].b; c = v[ i ].c;
        printf("%.2lf = %.2lf + %.2lf + %.2lf = %.2lf * %.2lf * %.2lf\n",
               ( a + b + c )/100.0 , a/100.0 , b/100.0 , c/100.0 , a/100.0 , b/100.0 , c/100.0 );
    }
    return 0;
}
