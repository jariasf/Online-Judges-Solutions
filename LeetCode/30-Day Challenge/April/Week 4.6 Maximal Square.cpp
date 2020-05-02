/*******************************************
 ***Problema: Maximal Square
 ***ID: Week4.6
 ***Juez: LeetCode
 ***Tipo: Dynamic Programming
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int h = matrix.size();
        if( h == 0 ) return 0;
        int w = matrix[0].size();
        int maximum = 0;
        vector<vector<int> > dp(h+ 2, vector<int>(w + 2, 0));
        for( int i = 1 ; i <= h ; ++i ){
            for( int j = 1 ; j <= w ; ++j ){
                int mini = min( dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
                dp[i][j] = ( matrix[i-1][j - 1] == '1')?mini + 1: 0;
                maximum = max(maximum, dp[i][j] * dp[i][j]);
            }
        }
        return maximum;
    }
};
