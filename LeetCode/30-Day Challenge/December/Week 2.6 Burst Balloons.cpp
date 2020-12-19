/*******************************************
 ***Problema: Burst Balloons
 ***ID: Week2.6
 ***Juez: LeetCode
 ***Tipo: Dynamic Programming
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int maxCoins(vector<int> &nums){
        int n = nums.size();
        vector<vector<int> > dp(n + 2, vector<int>(n + 2, 0));
        for( int right = 1 ; right <= n + 1; ++right ){
            for( int left = right - 1 ; left >= 0 ; --left ){
                for( int i = left + 1 ; i <= right - 1 ; ++i ){
                    int product = nums[i - 1];
                    if( left >= 1 )
                        product *= nums[left - 1];
                    if( right <= n )
                        product *= nums[right - 1];
                    dp[left][right] = max( dp[left][right], product + dp[left][i] + dp[i][right]);
                }
            }
        }
        return dp[0][n+1];
    }
};
