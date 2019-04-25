/*******************************************
 ***Problema: Video Stitching
 ***ID: 1024
 ***Juez: LeetCode
 ***Tipo: Sorting, Intervals
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    struct myclass {
        bool operator() (vector<int> v1, vector<int> v2){
            return v1[0] < v2[0] || (v1[0] == v2[0] && v1[1] > v2[1]);
        }
    } cmp;
    
    int videoStitching(vector<vector<int>>& v, int T) {
        sort(v.begin(), v.end(), cmp);
        int n = v.size();
        int mini = 1<<30, maxi = -1;
        vector<int> cur = v[0];
        mini = min( mini, cur[0]);
        maxi = max( maxi, cur[1]);
        int result = 1;
        if( mini > 0 ) return -1;
        if( mini == 0 && maxi >= T ) return result;
        for( int i = 1 ; i < n; ++i ){
            int maxi2 = -1;
            for( int j = i ; j < n ; ++j ){
                cur = v[j];
                if( maxi < cur[0] ) break;
                if( cur[1] <= maxi ) continue;
                maxi2 = max(maxi2, cur[1]);
            }
            if( maxi2 == -1 ) return -1;
            maxi = maxi2;
            result++;
            if( mini == 0 && maxi >= T ) return result;
        }
        
        if( mini > 0 || maxi < T ) return -1;
        return result;
    }
};
