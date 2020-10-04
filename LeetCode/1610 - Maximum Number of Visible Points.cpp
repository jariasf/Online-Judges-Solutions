/*******************************************
 ***Problema: Maximum Number of Visible Points
 ***ID: 1610
 ***Juez: LeetCode
 ***Tipo: Geometry + Sliding Window
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    double pi = acos(-1.0);
    
    double getAngle(double cx, double cy, double x, double y){
        double delta_x = x - cx;
        double delta_y = y - cy;
        return atan2(delta_y, delta_x); //radians
    }
    
    int visiblePoints(vector<vector<int>>& p, int angle, vector<int>& l) {
        double rad = 1.0 * angle * pi/180.0;
        int n = p.size();
        int cx = l[0], cy = l[1];
        vector<double> v;
        int same = 0;
        for( int i = 0 ; i < n ; ++i ){
            if( p[i][0] == l[0] && p[i][1] == l[1] ){ same++;continue;}
            double a = getAngle(cx, cy, p[i][0], p[i][1]);
            v.push_back(a);
        }
        
        sort(v.begin(), v.end());
        
        int m = v.size();
        for(int i = 0 ; i < m; ++i )
            v.push_back(v[i] + 2. * pi);
        
        int maxi = 0;
        for( int right = 0, left = 0 ; right < v.size(); ++right ){
            while(left <= right && v[right] - v[left] > rad ){
                left++;
            }
            maxi = max(right - left + 1, maxi);
        }
        return maxi + same;
        
    }
};
