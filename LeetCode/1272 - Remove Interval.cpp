/*******************************************
 ***Problema: Remove Interval
 ***ID: 1272
 ***Juez: LeetCode
 ***Tipo: Simulation
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved) {
        int n = intervals.size();
        vector<vector<int> > res;
        int x = toBeRemoved[0], y = toBeRemoved[1];
        for( int i = 0 ; i < n ; ++i ){
            int l = intervals[i][0], r = intervals[i][1];
            if( l > y || r < x  ){
                res.push_back(intervals[i]);
            }else{
                if( l < x && r <= y ){
                    res.push_back({l, x});
                }else if( x <= l && y < r ){
                    res.push_back({y, r});
                }else if( l < x && y < r ){
                    res.push_back({l, x});
                    res.push_back({y, r});
                }
            }
        }
        return res;
    }
};
