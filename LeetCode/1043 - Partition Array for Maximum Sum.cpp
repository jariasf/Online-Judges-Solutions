/*******************************************
 ***Problema: Partition Array for Maximum Sum
 ***ID: 1043
 ***Juez: LeetCode
 ***Tipo: Dynamic Programming
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    
    int n, k;
    vector<int> dp, v;
    int solve(int pos){
        if( pos == n ) return 0;
        if( dp[pos] != -1 ) return dp[pos];
        int res = 0;
        int maxi = 0;
        for( int i = pos, j = 1 ; i < n && j <= k ; ++i, ++j ){
            maxi = max( maxi, v[i] );
            res = max( res, maxi * j + solve(i + 1) );
        }
        return dp[pos] = res;
    }
    
    int maxSumAfterPartitioning(vector<int>& A, int K) {
        n = A.size();
        v = A;
        k = K;
        dp = vector<int>(n + 5, -1);
        return solve(0);
    }
};
