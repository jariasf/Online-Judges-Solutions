/*******************************************
 ***Problema: Max Points on a Line
 ***ID: Week 2.1
 ***Juez: LeetCode
 ***Tipo: Hashing | Map + Math
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    #define pii pair<double,double>
    #define mp make_pair
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();        
        int maxi = 1;
        double dx, dy, slope, intercept;
        map<pii, int> hash;
        for(int i = 0 ; i < n ; ++i){
            hash.clear();
            for(int j = 0 ; j < n ; ++j){
                if( i == j ) continue;
                dx = points[j][0] - points[i][0];
                dy = points[j][1] - points[i][1];
                slope = INT_MAX, intercept = points[i][0];
                if(dx != 0){
                    slope = dy/dx;
                    intercept = points[i][1] - slope * points[i][0];
                }
                hash[mp(slope, intercept)]++;
                maxi = max(maxi, hash[mp(slope, intercept)] + 1);
            }
        }
        return maxi;
    }
};
