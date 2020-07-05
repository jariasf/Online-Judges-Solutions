/*******************************************
 ***Problema: Ugly Number II
 ***ID: Week1.4
 ***Juez: LeetCode
 ***Tipo: Dynamic Programming
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n + 1, 0);
        int two = 0, three = 0, five = 0, next;
        dp[0] = 1;
        for( int i = 1 ; i < n ; ++i ){
            dp[i] = next = min( dp[two] * 2, min(dp[three] * 3 , dp[five] * 5));
            if( 2 * dp[two] == next ) two++;
            if( 3 * dp[three] == next ) three++;
            if( 5 * dp[five] == next ) five++;
        }
        return dp[n - 1];
    }
};
