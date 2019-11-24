/*******************************************
 ***Problema: Minimum Time Visiting All Points
 ***ID: 1266
 ***Juez: LeetCode
 ***Tipo: Math
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n = points.size();
        int res = 0;
        for( int i = 1 ; i < n ; ++i ){
            int a = abs(points[i][0] - points[i - 1][0]);
            int b = abs(points[i][1] - points[i - 1][1]);
            int diag = min(a,b);
            res += diag + a - diag + b  -diag;
        }
        return res;
    }
};
