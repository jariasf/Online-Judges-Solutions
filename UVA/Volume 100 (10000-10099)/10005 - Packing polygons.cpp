/*****************************************
 ***Problema: Packing polygons
 ***ID: 10005
 ***Juez: UVA
 ***Tipo: Circle por medio de 2 puntos y radio
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
#define MAX 105
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
};
double dist( Point p1 , Point p2 ){
    return sqrt( ( p1.x - p2.x ) *( p1.x - p2.x ) + ( p1.y - p2.y ) * ( p1.y - p2.y ) );
}

bool circle2ptsRad( Point p1 , Point p2 , double r, Point *ctr )
{
    double d2 = ( p1.x - p2.x ) * ( p1.x - p2.x ) + ( p1.y - p2.y ) * ( p1.y - p2.y );
    double det = r * r / d2 - 0.25;
    if( det < 0.0 ) return false;
    double h = sqrt( det );
    ctr -> x = ( p1.x + p2.x ) * 0.5 + ( p1.y - p2.y ) * h;
    ctr -> y = ( p1.y + p2.y ) * 0.5 + ( p2.x - p1.x ) * h;
    return true;
}
/*
   Punto dentro de circunferencia: Retorna true si p esta dentro de circunferencia con center
   y radio r
*/
bool insideCircle( Point center , double r , Point p ){
    return ( dist( center , p ) <= r + EPS );
}

Point v[ MAX ];

int main(){
    int n , i , j , k;
    double radio;
    Point center;
    bool b;
    while( scanf("%d" , &n ) , n ){
        for( i = 0 ; i < n && scanf("%lf %lf" , &v[ i ].x , &v[ i ].y ) ; ++i );
        scanf("%lf" , &radio );
        b = false;
        for( i = 0 ; i < n ; ++i ){
            for( j = 0 ; j < n ; ++j ){
                if( i == j ) continue;
                if( circle2ptsRad( v[ i ] , v[ j ] , radio , &center ) ){
                    for( k = 0 ; k < n ; ++k ){
                        if( !insideCircle( center , radio , v[ k ] ) ) break;
                    }
                    if( k == n ){
                        b = true;
                        goto end;
                    }
                }
            }
        }
        end:
        if( !b ) puts("There is no way of packing that polygon.");
        else puts("The polygon can be packed in the circle.");
    }

    return 0;
}
