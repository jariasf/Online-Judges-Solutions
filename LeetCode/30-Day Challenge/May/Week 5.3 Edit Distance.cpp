/*******************************************
 ***Problema: Edit Distance
 ***ID: Week5.3
 ***Juez: LeetCode
 ***Tipo: Dynamic Programming
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int minDistance(string A, string B) {
        int lenA = A.length(), lenB = B.length();
        vector<vector<int> > dp(lenA + 5, vector<int>(lenB + 5, 0) );
        for( int i = 1 ; i <= lenA ; ++i ) dp[i][0] = i;
        for( int i = 1 ; i <= lenB ; ++i ) dp[0][i] = i;
        dp[0][0] = 0;
        for( int i = 1 ; i <= lenA ; ++i ){
            for( int j = 1 ; j <= lenB ; ++j ){
                if(A[i - 1] == B[j - 1] ){
                    dp[i][j] = dp[i - 1][j - 1];
                }else{
                    dp[i][j] = min( dp[i - 1][j - 1] , min( dp[i - 1][j] , dp[i][j - 1] ) ) + 1;
                }
            }
        }
        return dp[lenA][lenB];
    }
};
