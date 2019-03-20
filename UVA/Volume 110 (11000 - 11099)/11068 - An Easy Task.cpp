/*****************************************
 ***Problema: An Easy Task
 ***ID: 11068
 ***Juez: UVA
 ***Tipo: Line Intersection
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
};

//Distance between two points
double dist( Point p1 , Point p2 ){
    return hypot( p1.x - p2.x , p1.y - p2.y );
}

//Convert angle from degrees to radians
double Deg_to_Rad( double angle ){
    return angle * PI/180.0;
}

//Convert angle from radians to degrees
double Rad_to_Deg( double angle ){
    return angle * 180.0/PI;
}

//Rotate ccw
Point rotate( Point p , double angle ){
    double rad = Deg_to_Rad( angle );
    return Point( p.x * cos( angle ) - p.y * sin( angle ) , p.x * sin( angle ) + p.y * cos( angle ) );
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
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

//////////////////////////////////////////////////////////////////////////////////////////////////////
struct Line{
    double a , b , c;
    Line( double A , double B , double C ): a(A),b(B),c(C){}
    Line(){}
};

bool pointToLine( Point p1 , Point p2 , Line &l ){
    if( fabs( p2.x - p1.x ) < EPS ){
        return false;
    }
    l.a = (p2.y - p1.y);
    l.b = (p1.x - p2.x);
    l.c = l.a * p1.x + l.b * p1.y;
    return true;
}

bool areParallel( Line l1 , Line l2 ){
    return fabs(cross( Point( l1.a , l1.b ) , Point( l2.a , l2.b ) )) < EPS;
}

bool areSame( Line l1 , Line l2 ){
    return areParallel( l1 , l2 ) && ( fabs( l1.c - l2.c ) < EPS );
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
int main(){
    int a1,b1,c1,a2,b2,c2;
    while( scanf("%d %d %d %d %d %d" , &a1 , &b1 , &c1 , &a2 , &b2 , &c2) && a1|b1|c1|a2|b2|c2 ){
        Line l1( a1 , b1 , c1 ) , l2( a2 , b2 ,c2 );
        if( areParallel( l1 , l2 ) ){
            puts("No fixed point exists.");
        }
        else{
            Point p;
            lineIntersection( l1 , l2 , p );
            printf("The fixed point is at %.2lf %.2lf.\n" , p.x , p.y );
        }
    }

    return 0;
}
