/*******************************************
 ***Problema: Closest Subsequence Sum
 ***ID: 1755
 ***Juez: LeetCode
 ***Tipo: Meet in the middle
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int minAbsDifference(vector<int>& nums, int goal) {
        int n = nums.size()/2, m = nums.size() - n;
        int res = INT_MAX;
        vector<int> sums;
        for( int i = 0 ; i < (1<<n) ; ++i ){
            int sum = 0;
            for( int j = 0 ; j < n ; ++j ){
                if( i & (1<<j)){
                    sum += nums[j];
                }
            }
            res = min(res, abs(sum - goal));
            sums.push_back(sum);
        }
        
        sort(sums.begin(), sums.end());
        for( int i = 0 ; i < (1<<m) ; ++i ){
            int sum = 0;
            for( int j = 0 ; j < m ; ++j ){
                if( i & (1<<j ) ){
                    sum += nums[n + j];
                }
            }
            res = min(res, abs(sum - goal));
            
            int pos = lower_bound(sums.begin(), sums.end(), goal - sum) - sums.begin();
            if( pos >= 0 && pos < sums.size() )
                res = min(res, abs( sums[pos] + sum - goal) );
            if( pos - 1 >= 0 )
                res = min(res, abs( sums[pos - 1] + sum - goal) );
            if( pos + 1 < sums.size() )
                res = min(res, abs( sums[pos + 1] + sum - goal) );
            
        }
        return res;
    }
};
