/*****************************************
 ***Problema: Sunny Mountains
 ***ID: 920
 ***Juez: UVA
 ***Tipo: Distance Point to Line
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
#define MAX 105
const long double PI = 2 * acos(.0);

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

typedef Point Vector;

double dot( Vector v1 , Vector v2 ){
    return v1.x * v2.x + v1.y * v2.y;
}

double cross( Vector v1 , Vector v2 ){
    return v1.x * v2.y - v1.y * v2.x;
}

Vector scale( Vector v , double s ){
    return Vector( v.x * s , v.y * s );
}

Vector toVec( Point p1 , Point p2 ){
    return p2 - p1;
}

Point translate( Point p , Vector v ){
    return Point( p.x + v.x , p.y + v.y );
}

double norm( Vector v ){
    return v.x * v.x + v.y * v.y;
}

double dist( Point p1 , Point p2 ){
    return hypot( p1.x - p2.x , p1.y - p2.y );
}

double distToLine( Point a , Point b , Point p , Point &c ){
    Vector AB = toVec( a , b ) , AP = toVec( a , p );
    double s = dot( AB , AP )/norm( AB );
    c = translate( a , scale( AB , s ) );
    return dist( p , c );
}

double distToLineSeg( Point a , Point b , Point p , Point &c ){
    Vector AB = toVec( a , b ) , AP = toVec( a , p );
    double s = dot( AB , AP )/norm( AB );
    if( s < 0.0 ){
        c = Point( a.x , a.y );
        return dist( a , p );
    }

    if( s > 1.0 ){
        c = Point( b.x , b.y );
        return dist( b , p );
    }

    return distToLine( a , b , p , c );
}
bool collinear( Point p , Point q , Point o ){
    Vector OP = toVec( o , p ), OQ = toVec( o , q );
    return fabs( cross( OP , OQ ) ) < EPS;
}

struct Line{
    double a , b , c;
    Line( double A , double B , double C ): a(A),b(B),c(C){}
    Line(){}
};

bool lineIntersection( Line l1 , Line l2 , Point &p ){
    double det = l1.a * l2.b - l2.a * l1.b;
    if( fabs( det ) < EPS ) return false;
    p.x = (l1.c * l2.b - l2.c * l1.b)/det;
    p.y = (l1.a * l2.c - l2.a * l1.c)/det;
    if( fabs(p.x) < EPS ) p.x = 0.0;
    if( fabs(p.y) < EPS ) p.y = 0.0;
    return true;
}

void pointToLine( Point p1 , Point p2 , Line &l ){
    l.a = (p2.y - p1.y);
    l.b = (p1.x - p2.x);
    l.c = l.a * p1.x + l.b * p1.y;
}


int main(){
    int t , n;
    scanf("%d" , &t );
    while( t-- > 0 && scanf("%d" , &n ) ){
        for( int i = 0 ; i < n && scanf("%lf %lf" , &p[ i ].x , &p[ i ] .y ) ; ++i );
        sort( p , p + n );
        Point ini = p[ n - 1 ];
        double ans = 0.0;
        for( int i = n - 1 ; i >= 1 ; --i ){
            if( ini.y + EPS < p[ i - 1 ].y ){
                ans += dist( ini , p[ i - 1 ] );
                ini = p[ i - 1 ];
            }
            else if( i - 2 >= 0 && ini.y + EPS < p[ i - 2 ].y ){
                Point c;
                Line l1; pointToLine( p[ i - 1 ] , p[ i - 2 ] , l1);
                Line l2; pointToLine( ini , Point( 0 , ini.y ) , l2);
                lineIntersection( l1 , l2 , c );
                ans += dist( c , p[ i - 2 ] );
                ini = p[ i - 2 ];
            }
        }
        printf("%.2lf\n" , ans );
    }
    return 0;
}
