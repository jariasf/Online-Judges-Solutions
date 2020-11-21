/*******************************************
 ***Problema: Merge Intervals
 ***ID: Week3.4
 ***Juez: LeetCode
 ***Tipo: Sorting
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    
    bool intersect(vector<int> &v1, vector<int> &v2){
        int right = min(v1[1], v2[1]);
        int left = max(v1[0], v2[0]);
        return left <= right;
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int> > res;
        for( int i = 0 ; i < n ; ++i ){
            int j = i + 1 ;
            while( j < n && intersect(intervals[j - 1], intervals[j])){
                intervals[j] = {intervals[j - 1][0], max(intervals[j - 1][1], intervals[j][1])};
                j++;
            }
            res.push_back(intervals[j - 1]);
            i = j - 1;
        }
        return res;
    }
};
