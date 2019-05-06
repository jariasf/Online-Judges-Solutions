/********************************************
 ***Problema: Valid Boomerang
 ***ID: 1037
 ***Juez: LeetCode
 ***Tipo: Geometry - cross product
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
	struct Point{
        int x , y;
        Point( int xx , int yy ): x( xx ) , y( yy ) {}
        Point() {}
        double operator ^( const Point &p1 )const{
            return x * p1.y - y * p1.x;
        }
        Point operator -( const Point &p1 )const{
            return Point( x - p1.x , y - p1.y );
        }
	};
    
    bool isBoomerang(vector<vector<int>>& points) {
        Point p = Point(points[0][0], points[0][1]);
        Point q = Point(points[1][0], points[1][1]);
        Point r = Point(points[2][0], points[2][1]);
        return (( q - p ) ^ ( r - p )) != 0;
    }
};
