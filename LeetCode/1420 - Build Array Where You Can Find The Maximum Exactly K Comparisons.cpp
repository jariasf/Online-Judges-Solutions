/*******************************************
 ***Problem: Build Array Where You Can Find The Maximum Exactly K Comparisons
 ***ID: 1420
 ***Judge: LeetCode
 ***Type: Dynamic Programming
 ***Author: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    typedef long long LL;
    int MOD = 1e9+7;
    
    vector<vector<vector<LL>>> dp;
    LL solve(int n, int m, int k, int maxi ){
        
        if( n == 0 ){
            if( k == 0 ) return 1;
            return 0;
        }

        if( k < 0 ) return 0;
        if( dp[n][k][maxi] != -1 ) return dp[n][k][maxi];
        
        LL res = 0;
        for( int i = 1 ; i <= m ; ++i ){
            if( i > maxi ){
                res += solve(n - 1, m, k - 1, i);
            }else{
                res += solve(n - 1, m, k, maxi);
            }
            res %= MOD;
        }
        
        return dp[n][k][maxi] = res % MOD;
    }
    
    int numOfArrays(int n, int m, int k) {
        dp = vector<vector<vector<LL>>>(n + 2, vector<vector<LL>>(k + 2, vector<LL>(m + 2, -1)));
        return solve(n, m, k, 0);
    }
};
