/*******************************************
 ***Problema: Find Right Interval
 ***ID: Week4.6
 ***Juez: LeetCode
 ***Tipo: Map | Sorting + Binary Search
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        map<int, int> mp;
        for( int i = 0 ; i < n;  ++i )
            mp[intervals[i][0]] = i;
        
        vector<int> res(n, -1);
        for( int i = 0 ; i < n ; ++i ){
            auto it = mp.lower_bound(intervals[i][1]);
            if( it != mp.end() )
                res[i] = it -> second;
        }
        return res;
    }
};
