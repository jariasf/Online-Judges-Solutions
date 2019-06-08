/*******************************************
 ***Problema: Minimum Falling Path Sum
 ***ID: 931
 ***Juez: LeetCode
 ***Tipo: Dynamic Programming
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int n = A.size();
        vector<vector<int> > dp(n, vector<int>(n, 1<<30) );
        for( int i = 0 ; i < n ; ++i ) dp[0][i] = A[0][i];
        for( int i = 0 ; i < n - 1 ; ++i ){
            for( int j = 0 ; j < n ; ++j ){                
                if( j - 1 >= 0 )
                    dp[i + 1][j - 1] = min( dp[i + 1][j - 1], dp[i][j] + A[i + 1][j - 1]);              
                if( j + 1 < n )
                    dp[i + 1][j + 1] = min( dp[i + 1][j + 1], dp[i][j] + A[i + 1][j + 1]);
                dp[i + 1][j] = min( dp[i + 1][j], dp[i][j] + A[i + 1][j]);
            }
        }
        int result = dp[n - 1][0];
        for( int i = 0 ; i < n ; ++i ) result = min( result, dp[n - 1][i]);
        return result;
    }
};
