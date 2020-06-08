/*******************************************
 ***Problema: Coin Change 2
 ***ID: Week1.7
 ***Juez: LeetCode
 ***Tipo: Dynamic Programming
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int> dp(amount + 2);
        dp[0] = 1;
        for( int i = 0 ; i < coins.size(); ++i ){
            for( int j = coins[i] ; j <= amount; ++j ){
                dp[j] += dp[ j - coins[i]];
            }
        }
        return dp[amount];
    }
};
