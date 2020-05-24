/*******************************************
 ***Problema: Max Dot Product of Two Subsequences
 ***ID: 1458
 ***Juez: LeetCode
 ***Tipo: Dynamic Programming
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    vector<vector<vector<int> > > dp;
    int n, m;
    vector<int> v1, v2;
    int solve(int i, int j, bool b){
        if( i == n || j == m ){
            if( b ) return 0;
            return -(1<<30);
        }
        if( dp[i][j][b] != INT_MIN ) return dp[i][j][b];
        int res = v1[i] * v2[j] + solve(i + 1, j + 1, 1);
        res = max( res, solve(i + 1, j, b));
        res = max( res, solve(i, j + 1, b));
        return dp[i][j][b] = res;
    }
    
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        v1 = nums1; v2 = nums2;
        n = v1.size();
        m = v2.size();
        dp = vector<vector<vector<int> > > (n + 1, vector<vector<int> >(m + 1, vector<int>(2, INT_MIN )));
        return solve(0, 0, 0);
    }
};
