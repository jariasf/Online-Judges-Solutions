/*******************************************
 ***Problema: Flip String to Monotone Increasing
 ***ID: Week 3.3
 ***Juez: LeetCode
 ***Tipo: Dynamic Window | DP
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/


// Solution 1: Dynamic Window → O(n)
class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int zeros = 0, ones = 0, n = s.size();
        for(char c:s) zeros += (c == '0');
        int res = n - zeros;
        for(int i = 0 ; i < n; ++i ){
            res = min(res, zeros + ones);
            if( s[i] == '0') zeros--;
            else ones++;
        }
        return res;
    }
};

// Solution2: DP → O(n)
class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int ones = 0, n = s.size();
        int res = 0;
        for(int i = 0 ; i < n; ++i ){
            if( s[i] == '1') ones++;
            else{
                // dp[i] = min(num_ones, dp[i - 1] + 1)
                res = min(ones, res + 1);
            }
        }
        return res;
    }
};
