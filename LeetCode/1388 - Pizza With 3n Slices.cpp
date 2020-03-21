/*******************************************
 ***Problem: Pizza With 3n Slices
 ***ID: 1388
 ***Judge: LeetCode
 ***Type: Dynamic Programming
 ***Author: Jhosimar George Arias Figueroa
 *******************************************/

// Bottom-Up
class Solution {
public:
    int solve(vector<int> slices, int start, int n, int k){        
        vector<vector<int> > dp = vector<vector<int> >(n + 2, vector<int>(k + 1, 0));
        int maximum = 0;
        for( int i = start + 2 ; i <= n + 1 ; ++i ){
            for( int j = 1; j <= k ; ++j ){
                dp[i][j] = max(slices[i - 2] + dp[i - 2][j - 1], dp[i - 1][j]);  
            }
            maximum = max(maximum, dp[i][k]);
        }
        return maximum;
    }
    
    int maxSizeSlices(vector<int>& slices) {
        int n = slices.size();
        int k = n / 3;
        return max(solve(slices, 0, n - 1, k), solve(slices, 1, n, k));      
    }
    
};

// Top-Down
class Solution {
public:
	
    vector<vector<int> > dp;
    vector<int> slices;
    int solve(int pos, int n, int k){
        if(k < 0) return INT_MIN;
        if( pos >= n ){
            if( k == 0 ) return 0;
            return INT_MIN;
        }
        if( dp[pos][k] != -1 ) return dp[pos][k];
        return dp[pos][k] = max(slices[pos] + solve(pos + 2, n, k - 1), solve(pos + 1, n, k));
    }
    
    
    int maxSizeSlices(vector<int>& _slices) {
        slices = _slices;
        int n = slices.size();
        int k = n / 3;
        dp = vector<vector<int> >(n + 1, vector<int>(k + 1, -1));
        int res = solve(0, n-1, k);
        dp = vector<vector<int> >(n + 1, vector<int>(k + 1, -1));
        return max( res, solve(1, n, k));        
    }
};
