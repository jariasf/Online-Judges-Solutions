/*****************************************
 ***Problema: Bright lights
 ***ID: 10927
 ***Juez: UVA
 ***Tipo: Sorting + Angle
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
#define MAX 100005
const long double PI = 2 * acos(.0);

struct Point{
    double x , y , angle;
    int h;
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
}p[ MAX ] , resp[ MAX ];

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
double norm( Vector v ){
    return v.x * v.x + v.y * v.y;
}
//Angle between two vectors
//|a * b | = ||a|| ||b|| cos0
double angle( Point a , Point b , Point o ){
    Vector OA = toVec( o , a ) , OB = toVec( o , b );
    return acos( dot( OA , OB )/( sqrt( norm( OA ) * norm( OB ) ) ) );
}

int n;

bool cmp( Point p1 , Point p2 ){

    double ang1 = p1.angle;
    double ang2 = p2.angle;

    if( fabs( ang1 - ang2 ) > EPS ){
        return ang1 + EPS < ang2;
    }
    return dist( p1 , Point( 0 , 0 ) ) + EPS < dist( p2 , Point( 0 , 0 ) );
}

int main(){
    int q = 1;
    while( scanf("%d" , &n ) , n ){
        for( int i = 0 ; i < n && scanf("%lf %lf %d" , &p[ i ].x , &p[ i ].y , &p[ i ].h ) ; ++i ){
            p[ i ].angle = angle( p[ i ] , Point( 1 , 0 ) , Point( 0 , 0 ) );
            if( p[ i ].y + EPS < 0.0 ){
                if( p[ i ].angle > EPS )
                    p[ i ].angle = 2 * PI - p[ i ].angle;
            }
            p[ i ].angle = Rad_to_Deg( p[ i ].angle );
        }

        sort( p , p + n , cmp );
        int len = 0 , maxh = p[ 0 ].h;
        for( int i = 1 ; i < n ; ++i ){
            if( fabs( p[ i - 1 ].angle - p[ i ].angle) < EPS ){
                if( p[ i ].h <= maxh ){
                    resp[ len++ ] = p[ i ];
                }
                else{
                    maxh = p[ i ].h;
                }
            }
            else{
                maxh = p[ i ].h;
            }
        }

        sort( resp , resp + len );
        printf("Data set %d:\n" , q++ );
        if( len == 0 ) puts("All the lights are visible.");
        else{
            puts("Some lights are not visible:");
            for( int i = 0 ; i < len - 1 ; ++i ){
                printf("x = %d, y = %d;\n" , (int)resp[ i ].x, (int)resp[ i ].y);
            }
            printf("x = %d, y = %d.\n" , (int)resp[ len - 1 ].x, (int)resp[ len - 1 ].y);
        }
    }
    return 0;
}

/*
4
-1 1 2
1 1 3
-1 -1 1
1 -1 0
*/
