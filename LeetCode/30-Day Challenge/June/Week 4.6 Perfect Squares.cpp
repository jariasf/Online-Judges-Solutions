/*******************************************
 ***Problema: Perfect Squares
 ***ID: Week4.6
 ***Juez: LeetCode
 ***Tipo: Dynamic Programming
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, 1<<30);
        dp[0] = 0;
        for( int i = 1 ; i <= n ; ++i )
            for( int j = 1; j*j <= i ; ++j )
                dp[i] = min(dp[i], 1 + dp[i - j*j]);
        return dp[n];
    }
};
