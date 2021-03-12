/*******************************************
 ***Problema: Coin Change
 ***ID: Week2.4
 ***Juez: LeetCode
 ***Tipo: Dynamic Programming
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 5, INT_MAX);
        dp[0] = 0;
        for( int i = 1 ; i <= amount; ++i ){
            for( int j = 0 ; j < coins.size(); ++j ){
                if( i - coins[j] >= 0 && dp[i - coins[j]] != INT_MAX ){
                    dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
                }
            }
        }
        if( dp[amount] == INT_MAX ) return -1;
        return dp[amount];
    }
};
