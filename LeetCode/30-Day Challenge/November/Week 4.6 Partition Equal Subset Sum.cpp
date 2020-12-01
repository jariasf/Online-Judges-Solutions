/*******************************************
 ***Problema: Partition Equal Subset Sum
 ***ID: Week4.6
 ***Juez: LeetCode
 ***Tipo: Dynamic Programming
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    vector<vector<int> > dp;
    bool canPartition(vector<int>& nums) {
        if( nums.size() <= 1 ) return false;
        int sum = 0;
        for( int i = 0 ; i < nums.size() ; ++i ) sum += nums[i];
        if( sum & 1 ) return false;
        dp = vector<vector<int> >(3, vector<int>(sum/2 + 5, 0 ));
        sum /= 2;
        dp[0][0] = dp[1][0] = 1;
        for( int i = 1 ; i <= nums.size(); ++i ){
            for( int j = 1 ; j <= sum ; ++j ){
                dp[i&1][j] = dp[!(i&1)][j];
                if( j >= nums[i - 1])
                    dp[i&1][j] |= dp[!(i&1)][j - nums[i - 1]];
            }
        }
        return dp[ nums.size() & 1 ][ sum ];
    }
};
