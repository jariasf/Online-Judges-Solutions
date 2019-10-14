/*******************************************
 ***Problema: Erect the Fence
 ***ID: 1152
 ***Juez: LeetCode
 ***Tipo: Geometry - Convex Hull
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */

class Solution {
public:
    /**
     * @param points: List[point]
     * @return: return List[point]
     */
    struct cmp{
        bool operator()(Point &p1, Point &p2){
            return p1.x < p2.x || (p1.x == p2.x && p1.y < p2.y);
        }
    }comp;
    
    int cross_product(Point &O, Point &A, Point &B){
        Point AO(A.x - O.x, A.y - O.y), BO(B.x - O.x, B.y - O.y);
        return AO.y * BO.x - AO.x * BO.y;
    }
     
    vector<Point> outerTrees(vector<Point> &points) {
        int n = points.size();
        if( n <= 3 ) return points;
        sort(points.begin(), points.end(), comp);
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
};
