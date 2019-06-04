/*******************************************
 ***Problema: Distinct Subsequences II
 ***ID: 940
 ***Juez: LeetCode
 ***Tipo: Dynamic Programming
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

#define MOD 1000000007
typedef long long LL;
class Solution {
public:
    int distinctSubseqII(string S) {
        vector<int> last(300, -1); 
        int n = S.length(); 
        vector<LL> dp(n + 1, 0);
        dp[0] = 1;
        for (int i = 1 ; i <= n ; ++i){ 
            dp[i] = 2 * dp[ i - 1 ] % MOD;
            dp[i] %= MOD;
            if( last[ S[ i - 1 ] ] != -1) 
                dp[i] = (dp[i]% MOD - dp[ last[ S[ i - 1 ] ] ] + MOD) % MOD;  
            last[ S[ i - 1 ] ] = ( i - 1); 
        } 
        return (dp[n] - 1 + MOD) % MOD; 
    }
};
