/*******************************************
 ***Problem: Restore The Array
 ***ID: 1416
 ***Judge: LeetCode
 ***Type: Dynamic Programming
 ***Author: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    typedef long long LL;
    int MOD = 1e9+7;
    string s;
    int K;
    vector<LL> dp;
    
    LL solve(int pos){
        int n = s.size();        
        if( pos == n )
            return 1;
        
        if( dp[pos] != -1 ) return dp[pos];
        LL res = 0;
        LL val = 0;
        for( int i = pos ; i < n ; ++i ){
            val = val * 10 + s[i] - '0';
            if( val >= 1 && val <= K )  
                res += solve(i + 1) % MOD;
            else break;
        }
        return dp[pos] = res % MOD;
    }
    
    int numberOfArrays(string _s, int k) {
        K = k;
        s = _s;
        dp = vector<LL>(s.size() + 5, -1 );
        return solve(0);
    }
};
