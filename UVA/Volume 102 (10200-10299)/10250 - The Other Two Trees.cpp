/*****************************************
 ***Problema: The Other Two Trees
 ***ID: 10250
 ***Juez: UVA
 ***Tipo: Point Rotation
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
    return Point( p.x * cos( rad ) - p.y * sin( rad ) , p.x * sin( rad ) + p.y * cos( rad ) );
}

int main(){
    double x1  ,y1 , x2 , y2;
    while( scanf("%lf %lf %lf %lf" , &x1 , &y1 , &x2 , &y2 ) != EOF ){
        if( fabs( x1 ) > EPS || fabs( y1 ) > EPS || fabs( x2 ) > EPS || fabs( y2 ) > EPS ){
            Point mid( (x1 + x2)/2 , (y1+y2)/2) ;
            Point A = rotate( Point( x1 - mid.x , y1 - mid.y ) , 90 ),
            B = rotate( Point( x2 - mid.x , y2 - mid.y ) , 90 );
            printf("%.10lf %.10lf %.10lf %.10lf\n" , A.x + mid.x , A.y + mid.y , B.x + mid.x , B.y + mid.y );
        }
        else break;
    }

    return 0;
}
