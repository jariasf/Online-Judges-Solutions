/*******************************************
 ***Problema: Palindrome Removal
 ***ID: 1246
 ***Juez: LeetCode
 ***Tipo: Dynamic Programming
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

// Bottom-Up
class Solution {
public:
    int minimumMoves(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int> > dp(n, vector<int>(n, n));
        for( int i = 0 ; i < n ; ++i )
            dp[i][i] = 1;
        
        for( int i = 0; i + 1 < n ; ++i ){
            if( arr[i] == arr[i + 1])
                dp[i][i + 1] = 1;
            else
                dp[i][i + 1] = 2;
        }
        
        for( int i = 2 ; i <= n ; ++i ){
            for( int left = 0, right = left + i; right < n; ++left, ++right){
                if( arr[left] == arr[right])
                    dp[left][right] = dp[left + 1][right - 1];
                for(int j = left; j + 1 <= right ; ++j )
                    dp[left][right] = min(dp[left][right], dp[left][j] + dp[j + 1][right]);
            }
        }
        
        return dp[0][n - 1];
    }
};


// Top-Down
class Solution {
public:
    
    #define MAX 105
    
    int dp[MAX][MAX];
    vector<int> v;
    int solve(int left, int right ){
        if(left >= right){
            return 1;
        }
        if(dp[left][right] != -1) return dp[left][right];
        
        int result = 1<<30;
        
        if( v[left] == v[right] ){
            result = min( result, solve(left + 1, right - 1));
        }
        
        result = min( result, 1 + solve(left + 1, right));
        result = min( result, 1 + solve(left, right - 1));

        for( int i = left + 1 ; i < right ; ++i ){
            result = min(result, solve(left, i) + solve(i + 1, right));
        }
        
        return dp[left][right] = result;
    }
    
    int minimumMoves(vector<int>& arr) {
        int res = arr.size();
        v = arr;
        memset(dp, -1, sizeof(dp));
        return solve(0, res - 1);
    }
};
