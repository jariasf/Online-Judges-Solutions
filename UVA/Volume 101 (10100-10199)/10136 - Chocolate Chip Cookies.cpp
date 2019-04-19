/*****************************************
 ***Problema: Chocolate Chip Cookies
 ***ID: 10136
 ***Juez: UVA
 ***Tipo: Circle through two points and radius
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
#define MAXN 205
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
}p[ MAXN ];

void printPoint( Point p ){
    printf("(%lf,%lf)" , p.x , p.y );
}

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
    return Point( p.x * cos( rad ) - p.y * sin( rad ) , p.x * sin( rad ) + p.y * cos( rad ) );
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

Vector toUnit( Vector v ){
    return Vector( v.x/sqrt( norm(v) ) , v.y/sqrt(norm(v) ) );
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
/**
**Determinate whether p is counter-clockwise of line oq
**/
bool ccw( Point p , Point q , Point o ){
    Vector OP = toVec( o , p ), OQ = toVec( o , q );
    return ( cross( OP , OQ ) + EPS < 0 );
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

//Ax + By = C
bool pointToLine( Point p1 , Point p2 , Line &l ){
    //if( fabs( p2.x - p1.x ) < EPS ){
    //    return false;
   // }
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

//true if p is in the segment of the line (p1,p2)
bool onSegment( Point p1 , Point p2 , Point p ){
    double minX = p1.x , minY = p1.y , maxX = minX , maxY = minY;
    if( p2.x + EPS < p1.x ) minX = p2.x;
    else maxX = p2.x;
    if( p2.y + EPS < p1.y ) minY = p2.y;
    else maxY = p2.y;
    return ( minX <= p.x + EPS && p.x <= maxX + EPS ) &&
           ( minY <= p.y + EPS && p.y <= maxY + EPS ) && collinear( p , p1 , p2 );
}

//Segment Intersection
bool lineSegIntersection( Point p1 , Point p2 , Point p3 , Point p4 , Point &p ){
    //if( onSegment( p1 , p2 , p3 ) || onSegment( p1 , p2 , p4 ) || onSegment( p3 , p4 , p1 ) || onSegment( p3 , p4 , p2 ) ){
    //    return true;
    //}

    Line l1 , l2;
    pointToLine( p1 , p2 , l1 ); pointToLine( p3 , p4 , l2 );
    if( !lineIntersection( l1 , l2 , p ) ) return false;
    return onSegment( p1 , p2 , p ) && onSegment( p3 , p4 , p );
}

//AC = s * AB -> C - A = s * AB
//c = a + s * AB
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

//Angle between two vectors
//|a * b | = ||a|| ||b|| cos0
double angle( Point a , Point b , Point o ){
    Vector OA = toVec( o , a ) , OB = toVec( o , b );
    return acos( dot( OA , OB )/( sqrt( norm( OA ) * norm( OB ) ) ) );
}



////////////////////////////////////////////////////////////////////
///Circles
////////////////////////////////////////////////////////////////////

int insideCircle( Point p , Point c , double r ){
    double d = dist( p , c );
    if( d + EPS < r ) return 1; //inside
    if( fabs( d - r ) < EPS ) return 2; //border
    return 0; //ouside
}

  /**
if m is midway between p1 and p2

ratio mc_1 / mp_1

pythag says r^2 = mp_1^2 + mc_1^2

so mc_1 = sqrt(r^2 - mp_1^2)

h = sqrt(r^2 - mp_1^2) / mp_1

h = sqrt(r^2 - mp_1^2) / sqrt(mp_1^2)
h = sqrt( r^2 / mp_1^2 - 1 )

4 * mp_1^2 = d2

ratio mc_1 / mp_1 = 2 * sqrt( r^2 / d2 - 1/4 )
*/
bool circle2ptsRad( Point p1 , Point p2 , double r, Point &c1 , Point &c2 )
{
    double d2 = ( p1.x - p2.x ) * ( p1.x - p2.x ) + ( p1.y - p2.y ) * ( p1.y - p2.y );
    double det = r * r / d2 - 0.25;
    if (det < 0.0) return false;
    double h = sqrt(det);

    //point m is average p1 and p2 ; scaling / rotation combined (swap x,y neg x)
    c1.x = (p1.x + p2.x) * 0.5 + (p1.y - p2.y) * h;
    c1.y = (p1.y + p2.y) * 0.5 + (p2.x - p1.x) * h;

    c2.x = (p1.x + p2.x) * 0.5 + (p2.y - p1.y) * h;
    c2.y = (p1.y + p2.y) * 0.5 + (p1.x - p2.x) * h;
    return true;
}

bool circle2PointRad( Point p1 , Point p2 , double r , Point &c1 , Point &c2 ){
    double chord = dist( p1 , p2 );
    Point m( ( p1.x + p2.x)/2.0 , (p1.y+p2.y)/2.0 );
    Vector v = toVec( p1 , p2 );
    if( r * r  + EPS < (chord/2.0) * (chord/2.0) )
        return false;
    double center_to_mid_point = sqrt( r * r - (chord/2.0) * (chord/2.0) );
    Vector unit = toUnit( v );
    Point m2 = rotate( m - p1 , 270 );
    unit = toUnit( toVec( p1 , m2 + p1 ) );
    c1 = translate( m , scale( unit , center_to_mid_point ) );
    m2 = rotate( m - p1 , 90 );
    unit = toUnit( toVec( p1 , m2 + p1 ) );
    c2 = translate( m , scale( unit , center_to_mid_point ));
    return true;
}

bool circle3Point( Point p1 , Point p2 , Point p3 , Point &c ){
    if( collinear( p1 , p2 , p3 ) )
        return false;
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
#define MAX 55
char s[ MAX ];

int main(){

    int t , len;
    scanf("%d" , &t );
    gets( s );
    gets( s );
    double radius = 2.5;
    while( t-- ){
        len = 0;
        int maxi = 1;
        while( gets( s ) ){
            if( strlen( s ) == 0 ) break;
            stringstream ss( s );
            ss>>p[ len ].x;
            ss>>p[ len ].y;
            len++;
        }
        for( int i = 0 ; i < len ; ++i ){
            for( int j = i + 1 ; j < len ; ++j ){
                Point c1 , c2;
                if( circle2ptsRad( p[ i ], p[ j ] , radius , c1 , c2 ) ){
                    int cnt = 0;
                    for( int k = 0 ; k < len ; ++k ){
                        if( insideCircle( p[ k ] , c1  ,radius ) ){
                            cnt++;
                        }
                    }
                    maxi = max( cnt , maxi );

                    cnt = 0;
                    for( int k = 0 ; k < len ; ++k ){
                        if( insideCircle( p[ k ] , c2  ,radius ) ){
                            cnt++;
                        }
                    }
                    maxi = max( cnt , maxi );
                }
            }
        }

        printf("%d\n" , maxi );
        if( t > 0 )
            printf("\n");
    }

    return 0;
}
