/*******************************************
 ***Problema: Remove Covered Intervals
 ***ID: Week1.4
 ***Juez: LeetCode
 ***Tipo: Sorting
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    
    bool covered(vector<int> &a, vector<int> &b){
        return a[0] >= b[0] && a[1] <= b[1];
    }
    
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int n = intervals.size(), last_index = 0, removed = 0;
        for( int i = 1 ; i < n ; ++i ){
            if(covered(intervals[i], intervals[last_index])){
                removed++;
            }else if( covered(intervals[last_index], intervals[i]) ) {
                removed++;
                last_index = i;
            }else if( intervals[i][1] > intervals[last_index][1] ){
                last_index = i;
            }
        }
        return n - removed;
    }
};
