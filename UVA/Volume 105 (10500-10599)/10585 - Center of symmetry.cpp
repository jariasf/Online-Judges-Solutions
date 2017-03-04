/*****************************************
 ***Problema: Center of symmetry
 ***ID: 10585
 ***Juez: UVA
 ***Tipo: Sorting
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
#define EPS 1e-9
const long double PI = 2 * acos(.0);
#define MAX 10005
struct Point{
    double x , y;
    Point( double X , double Y ):x(X) , y(Y){}
    bool operator <( Point other ) const{
        if( fabs( x - other.x ) < EPS ){
            return y + EPS < other.y;
        }
        return x + EPS < other.x;
    }

    bool operator ==( Point other )const{
        return ( fabs( x - other.x ) < EPS && fabs( y - other.y ) < EPS );
    }

    Point operator -(Point other)const{
        return Point( x - other.x , y - other.y );
    }
    Point(){}
}p[ MAX ];

int main(){

    int t , n;
    scanf("%d"  ,&t );
    while( t-- > 0 && scanf("%d" , &n ) ){
        for( int i = 0 ; i < n && scanf("%lf %lf" , &p[ i ].x , &p[ i ].y ); ++i );

        sort( p , p + n );
        bool b = false , error =false;
        Point mid , mid2;
        for( int i = 0 ; i < n/2 ; ++i ){
            if( !b ){
                mid = Point((p[ i ].x + p[ n - 1 - i ].x)/2.0,(p[ i ].y + p[ n - 1 - i ].y)/2.0);
                b = true;
            }
            else{
                mid2 = Point((p[ i ].x + p[ n - 1 - i ].x)/2.0,(p[ i ].y + p[ n - 1 - i ].y)/2.0);
                if( mid == mid2 ) continue;
                else{
                    error = true;
                    break;
                }
            }
        }
        if( !error ) puts("yes");
        else puts("no");
    }
    return 0;
}
