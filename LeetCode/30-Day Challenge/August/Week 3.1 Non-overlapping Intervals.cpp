/*******************************************
 ***Problema: Non-overlapping Intervals
 ***ID: Week3.1
 ***Juez: LeetCode
 ***Tipo: Greedy
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort( intervals.begin(), intervals.end() );
        int result = 0;
        int sz = intervals.size();
        if( sz == 0 ) return 0;
        vector<int> last = intervals[0];
        for( int i = 1 ; i < sz ; ++i ){
            if( intervals[i][0] < last[1] ){
                result++;
                if( intervals[i][1] < last[1] ) last[1] = intervals[i][1];
            }else{
                last[1] = intervals[i][1];
            }
        }
        
        return result;
    }
};
