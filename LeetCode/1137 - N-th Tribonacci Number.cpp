/*******************************************
 ***Problema: N-th Tribonacci Number
 ***ID: 1137
 ***Juez: LeetCode
 ***Tipo: Fibonacci, Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int tribonacci(int n) {
        vector<long long> dp(n + 5);
        dp[0] = 0;
        dp[1] = dp[2] = 1;
        for( int i = 3 ; i <= n ; ++i ){
            dp[i] = dp[i - 1] + dp[ i - 2] + dp[i - 3];
        }
        return dp[n];
    }
};
