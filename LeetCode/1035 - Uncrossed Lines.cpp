/********************************************
 ***Problema: Uncrossed Lines
 ***ID: 1035
 ***Juez: LeetCode
 ***Tipo: Dynamic Programming - LCS
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        int nA = A.size(), nB = B.size();
        vector<vector<int> > dp( nA + 1, vector<int>(nB + 1, 0));
        for( int i = 0 ; i < nA ; ++i )
            for( int j = 0 ; j < nB ; ++j )
                if( A[ i ] == B[ j ] )
                    dp[i+1][j+1] = dp[i][j] + 1;
                else
                    dp[i+1][j+1] = max( dp[i+1][j], dp[i][j+1]);
        return dp[nA][nB];
    }
};
