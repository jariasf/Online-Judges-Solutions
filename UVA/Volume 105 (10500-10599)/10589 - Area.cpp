/*****************************************
 ***Problema: Area
 ***ID: 10589
 ***Juez: UVA
 ***Tipo: Geometry, point inside circle
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>
#include <cmath>

#define EPS 1e-15
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

    Point operator + (Point other)const{
        return Point( x + other.x , y + other.y );
    }

    Point(){}
};

double dist( Point p1 , Point p2 ){
    return hypot( p1.x - p2.x , p1.y - p2.y );
}
int insideCircle( Point p , Point c , double r ){
    double d = dist( p , c );
    if( d + EPS < r ) return 1;
    if( fabs( d - r ) < EPS ) return 2;
    return 0;
}

int main(){
    int n , cnt , radius;
    double y , x;
    while( scanf("%d %d", &n , &radius ) , n ){
        cnt = 0;
        for( int i = 0 ; i < n && scanf("%lf %lf" , &x , &y ) ; ++i ){
            if( insideCircle( Point( x , y ) , Point( 0 , 0 ) , radius ) > 0 &&
                insideCircle( Point( x , y ) , Point( radius , 0 ) , radius ) > 0 &&
                insideCircle( Point( x , y ) , Point( 0 , radius ) , radius ) > 0 &&
                insideCircle( Point( x , y ) , Point( radius , radius ) , radius ) > 0 ){
                cnt++;
            }
        }
        printf("%.5lf\n" , (double)(cnt * radius * radius)/(double)n);
    }

    return 0;
}
