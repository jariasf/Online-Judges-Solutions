/*******************************************
 ***Problema: Insert Interval
 ***ID: Week2.6
 ***Juez: LeetCode
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        vector<vector<int> > res;
        for( int i = 0 ; i < n ; ++i ){
            if( intervals[i][1] < newInterval[0] ){
                res.push_back(intervals[i]);
            }else if( newInterval[1] < intervals[i][0] ){
                res.push_back(newInterval);
                newInterval = intervals[i];
            }else if( newInterval[0] >= intervals[i][0] || newInterval[1] <= intervals[i][1] ){
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);                
            }
        }
        res.push_back(newInterval);
        return res;
    }
};
