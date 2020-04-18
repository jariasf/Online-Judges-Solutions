/*******************************************
 ***Problema: Minimum Path Sum
 ***ID: Week3.4
 ***Juez: LeetCode
 ***Tipo: Dynamic Programming
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int minPathSum(vector<vector<int>>& A) {
        int h = A.size(), w = A[0].size();
        vector<vector<int> > dp( h + 2 , vector<int>(w + 2, 1<<30) );
        dp[0][1] = dp[1][0] = 0;
        for( int i = 1 ; i <= h ; ++i )
            for( int j = 1 ; j <= w ; ++j )
                dp[i][j] = min(dp[i][ j - 1 ] , dp[i - 1][j] ) + A[i - 1][j - 1];

        return dp[h][w];
    }
};
