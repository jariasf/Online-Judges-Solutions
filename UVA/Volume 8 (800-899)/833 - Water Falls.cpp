/*****************************************
 ***Problema: Water Falls
 ***ID: 833
 ***Juez: UVA
 ***Tipo: Slopes
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

#define MAX 1005
struct Segment{
    Point p1 , p2;
    Segment( Point P1 , Point P2 ):p1( P1 ) , p2(P2){}
    Segment(){}
}s[ MAX ];
int n;

bool ccw( Point p , Point q , Point o ){
    Vector OP = toVec( o , p ), OQ = toVec( o , q );
    return ( cross( OP , OQ ) + EPS < 0 );
}

int solve( int x , int y ){
    while( true ){
        double mini = 1LL<<50;
        int idx = -1;
        for( int i = 0 ; i < n ; ++i ){
            if( s[ i ].p1.x <= x && x <= s[ i ].p2.x && ( ccw( Point( x , y ) , s[i].p2 , s[i].p1 ) ) ){
                Point p;
                double d = distToLine( s[ i ].p1 , s[ i ].p2 , Point( x , y ) , p );
                if( d + EPS < mini ){
                    mini = d;
                    idx = i;
                }
            }
        }

        if( idx == -1 ) break;
        if( s[ idx ].p1.y > s[ idx ].p2.y ){
            x = s[ idx ].p2.x;
            y = s[ idx ].p2.y;
        }
        else{
            x = s[ idx ].p1.x;
            y = s[ idx ].p1.y;
        }
    }
    return x;
}


int main(){
    int t , q , x1 , y1 , x2  ,y2 , m , x , y;
    scanf("%d" , &t );
    for( q = 0 ; q < t && scanf("%d" , &n ) ; ++q ){
        if( q )puts("");
        for( int i = 0 ; i < n && scanf("%d %d %d %d", &x1 , &y1 , &x2 , &y2 ) ; ++i ){
            if( x1 < x2 )
                s[ i ] = Segment( Point( x1 , y1 ) , Point( x2 , y2 ) );
            else
                s[ i ] = Segment( Point( x2 , y2 ) , Point( x1 , y1 ) );
        }
        scanf("%d" , &m );
        for( int i = 0 ; i < m && scanf("%d %d" , &x , &y ) ; ++i ){
            printf("%d\n" , solve( x , y ) );
        }
    }
    return 0;
}
