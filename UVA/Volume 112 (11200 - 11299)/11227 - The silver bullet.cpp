/*****************************************
 ***Problema: The silver bullet
 ***ID: 11227
 ***Juez: UVA
 ***Tipo: Collinear points
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
#define MAX 105
#define EPS 1e-8
struct Point{
    double x , y;
    Point( double xx , double yy ): x( xx ) , y( yy ){}
    Point(){}
    double operator *( const Point &p1 )const{
        return x * p1.x + y * p1.y;
    }
    double operator ^( const Point &p1 )const{
        return x * p1.y - y * p1.x;
    }
    Point operator -( const Point &p1 )const{
        return Point( x - p1.x , y - p1.y );
    }

    bool operator <( Point p2 ) const{
        return x < p2.x || ( x == p2.x && y < p2.y );
    }

}v[ MAX ];

//Si punto r esta en la linea formada por p y q
bool collinear( Point p , Point q , Point r ){
    return fabs( ( q - p ) ^ ( r - p ) ) < EPS;
}

int main(){
    int t , n , i , q , j , k , cnt , maxi;
    scanf("%d" , &t );
    for( q = 1 ; q <= t && scanf("%d" , &n ) ; ++q ){
        for( i = 0 ; i < n && scanf("%lf %lf" , &v[ i ].x , &v[ i ].y ) ; ++i );
        set< Point > s( v , v + n );
        vector< Point > a( s.begin() , s.end() );
        n = a.size();
        maxi = 0;
        printf("Data set #%d contains " , q );
        for( i = 0 ; i < n ; ++i ){
            for( j = i + 1 ; j < n ; ++j ){
                cnt = 0;
                for( k = 0 ; k < n ; ++k ){
                    if( collinear( a[ i ] , a[ j ] , a[ k ] ) ){
                        cnt++;
                    }
                }
                maxi = max( maxi , cnt );
            }
        }
        if( a.size() == 1 ){
            printf("a single gnu.\n");
        }else{
            if( a.size() == 2 ) maxi = 2;
            printf("%d gnus, out of which a maximum of %d are aligned.\n" , a.size() , maxi );
        }
    }
    return 0;
}
