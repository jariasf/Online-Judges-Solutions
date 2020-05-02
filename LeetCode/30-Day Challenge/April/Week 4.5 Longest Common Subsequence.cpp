/*******************************************
 ***Problema: Longest Common Subsequence
 ***ID: Week4.5
 ***Juez: LeetCode
 ***Tipo: Dynamic Programming
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        vector<vector<int> > dp(n + 1, vector<int>(m + 1));
        for( int i = 1 ; i <= n ; ++i ){
            for( int j = 1 ; j <= m ; ++j ){
                if( s1[i - 1] == s2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                dp[i][j] = max( dp[i][j - 1], max(dp[i - 1][j], dp[i][j]));
            }
        }
        return dp[n][m];
    }
};
