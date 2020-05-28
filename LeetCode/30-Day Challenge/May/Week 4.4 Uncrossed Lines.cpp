/*******************************************
 ***Problema: Uncrossed Lines
 ***ID: Week4.4
 ***Juez: LeetCode
 ***Tipo: Dynamic Programming - LCS
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    vector<vector<int> > dp;
    int n, m;
    vector<int> a, b;
    int solve(int i, int j){
        if( i >= n && j >= m ) return 0;
        if( dp[i][j] != -1 ) return dp[i][j];
        int res = 0;
        if( a[i] == b[j] )
            res = 1 + solve(i + 1, j + 1);        
        res = max(res, solve(i + 1, j));
        res = max(res, solve(i, j + 1));        
        return dp[i][j] = res;
    }
    
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        n = A.size(); m = B.size();
        dp = vector<vector<int> >(n + 1, vector<int>(m + 1, -1));
        a = A; b = B;
        return solve(0, 0);
    }
};
