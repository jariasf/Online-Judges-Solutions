/*******************************************
 ***Problema: House Robber II
 ***ID: Week2.7
 ***Juez: LeetCode
 ***Tipo: Dynamic Programming
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        if( n == 1 ) return nums[0];
        int res = 0;
        vector<int> dp(n + 1);
        dp[1] = nums[0];
        for( int i = 2 ; i < n ; ++i ){
            dp[i] = max(dp[i - 2] + nums[i - 1], max(dp[i - 1], nums[i - 1]));
        }
        res = dp[n - 1];
        
        fill(dp.begin(), dp.end(), 0);
        for( int i = 2 ; i <= n ; ++i )
            dp[i] = max(dp[i - 2] + nums[i - 1], max(dp[i - 1], nums[i - 1]));
        return max(res, dp[n]);
    }
};
