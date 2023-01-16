/*******************************************
 ***Problema: Insert Interval
 ***ID: Week 3.2
 ***Juez: LeetCode
 ***Tipo: Linear Search
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int n = intervals.size();
        for(int i = 0 ; i < n ; ++i){
            if(intervals[i][1] >= newInterval[0] && intervals[i][0] <= newInterval[1]){
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
            }else{
                if(newInterval[1] < intervals[i][0]){
                    res.push_back(newInterval);
                    newInterval[0] = newInterval[1] = INT_MAX;
                }
                res.push_back(intervals[i]);
            }
        }
        if(newInterval[1] != INT_MAX)
            res.push_back(newInterval);
        return res;
    }
};
