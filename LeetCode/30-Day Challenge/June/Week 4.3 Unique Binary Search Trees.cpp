/*******************************************
 ***Problema: Unique Binary Search Trees
 ***ID: Week4.3
 ***Juez: LeetCode
 ***Tipo: Dynamic Programming
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1);
        dp[0] = 1;
        for( int i = 1 ; i <= n ; ++i ){
            for( int j = 1 ; j <= i ; ++j )
                dp[i] += dp[j - 1] * dp[i - j];
        }
        return dp[n];
    }
};
