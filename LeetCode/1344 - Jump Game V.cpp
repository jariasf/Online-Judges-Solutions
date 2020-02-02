/*******************************************
 ***Problema: Jump Game V
 ***ID: 1344
 ***Juez: LeetCode
 ***Tipo: Dynamic Programming
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    vector<int> dp;
    vector<int> h;
    
    int solve(int pos, int d){
        int n = h.size();
        if( dp[pos] != -1 ) return dp[pos];

        int maximum = 1;

        for( int i = 1 ; i <= d && pos + i < n && h[pos + i] < h[pos] ; ++i )
            maximum = max( maximum, 1 + solve(pos + i, d));
        
        for( int i = 1 ; i <= d && pos - i >= 0 && h[pos - i] < h[pos] ; ++i )
            maximum = max( maximum, 1 + solve(pos - i, d));
        
        return dp[pos] = maximum;
    }
    
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        h = arr;
        dp = vector<int>(n + 5, -1);
        int maximum = 1;        
        for( int i = 0 ; i < n ; ++i )
            maximum = max( maximum, solve(i, d));    
        
        return maximum;
    }
};
