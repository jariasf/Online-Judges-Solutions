/*****************************************
 ***Problema: The Circumference of the Circle
 ***ID: 438
 ***Juez: UVA
 ***Tipo: Circle throught three points
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
const double PI = 3.141592653589793;

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

    Point operator + (Point other)const{
        return Point( x + other.x , y + other.y );
    }

    Point(){}
};

//Distance between two points
double dist( Point p1 , Point p2 ){
    return hypot( p1.x - p2.x , p1.y - p2.y );
}

//////////////////////////////////////////////////////////////////////////////////////////////////////

struct Line{
    double a , b , c;
    Line( double A , double B , double C ): a(A),b(B),c(C){}
    Line(){}
};

//Ax + By = C
bool pointToLine( Point p1 , Point p2 , Line &l ){
    l.a = (p2.y - p1.y);
    l.b = (p1.x - p2.x);
    l.c = l.a * p1.x + l.b * p1.y;
    return true;
}

void perpendicularLine( Line &l , Point mid ){
    swap( l.a , l.b );
    l.a = -l.a;
    l.c = l.a * mid.x + l.b * mid.y;
}

//Returns the point of intersection of two lines
bool lineIntersection( Line l1 , Line l2 , Point &p ){
    double det = l1.a * l2.b - l2.a * l1.b;
    if( fabs( det ) < EPS ) return false;
    p.x = (l1.c * l2.b - l2.c * l1.b)/det;
    p.y = (l1.a * l2.c - l2.a * l1.c)/det;

    if( fabs(p.x) < EPS ) p.x = 0.0;
    if( fabs(p.y) < EPS ) p.y = 0.0;

    return true;
}

bool circle3Point( Point p1 , Point p2 , Point p3 , Point &c ){
    Point mid( ( p1.x + p2.x)/2.0 , ( p1.y + p2.y)/2.0 );
    Line line1 , line2;
    pointToLine( p1 , p2 , line1 );
    perpendicularLine( line1 , mid );
    mid = Point( ( p2.x + p3.x )/2.0 , ( p2.y + p3.y )/2.0 );
    pointToLine( p2 , p3 , line2 );
    perpendicularLine( line2 , mid );

    if( !lineIntersection( line1 , line2 , c ) )
        return false;
    return true;
}

int main(){
    Point p1 , p2 , p3;
    while( scanf("%lf %lf %lf %lf %lf %lf" , &p1.x , &p1.y ,&p2.x, &p2.y
                 ,&p3.x , &p3.y ) != EOF ){
        Point c;
        circle3Point( p1 , p2 , p3 ,c);
        double r = dist( c , p1 );
        printf("%.2lf\n" , r * PI * 2.0 );
    }

    return 0;
}
