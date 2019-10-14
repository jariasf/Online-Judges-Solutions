/*******************************************
 ***Problema: Erect the Fence
 ***ID: 587
 ***Juez: LeetCode
 ***Tipo: Geometry - Convex Hull
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    
    struct Point{
        int x, y;
        Point(int _x, int _y ): x(_x), y(_y){}
        Point(){}
        bool operator <(Point p2){
            return x < p2.x || (x == p2.x && y < p2.y);
        }
        Point operator -(Point p2){
            return Point(x - p2.x, y - p2.y);
        }
    };
    
    int cross_product(Point &O, Point &A, Point &B){
        Point AO = A - O, BO = B - O;
        return AO.y * BO.x - AO.x * BO.y;
    }
     
    vector<Point> outerTrees(vector<Point> &points) {
        int n = points.size();
        if( n <= 3 ) return points;
        sort(points.begin(), points.end());
        vector<Point> hull(2*n);
        int k = 0;
        for( int i = 0 ; i < n ; ++i ){
            while(k >= 2 && cross_product(hull[k - 2], hull[k - 1], points[i]) < 0 ) k--;
            hull[k++] = points[i];
        }
        
        for( int i = n - 1, t = k + 1 ; i > 0 ; --i ){
            while(k >= t && cross_product(hull[k - 2], hull[k - 1], points[i - 1]) < 0 ) k--;
            hull[k++] = points[i - 1];
        }
        
        hull.resize(k - 1);
        return hull;
    }
    
    vector<vector<int>> outerTrees(vector<vector<int>>& points) {
        vector<Point> p(points.size());
        for( int i = 0 ; i < points.size(); ++i ){
            p[i] = Point(points[i][0], points[i][1]);
        }
        vector<Point> hull = outerTrees(p);
        
        vector<vector<int> > res( hull.size(), vector<int>(2) );
        for( int i = 0 ; i < hull.size(); ++i ){
            res[i][0] = hull[i].x;
            res[i][1] = hull[i].y;
        }
        return res;
    }
};
