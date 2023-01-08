/*******************************************
 ***Problema: Maximize Palindrome Length From Subsequences
 ***ID: 1771
 ***Juez: LeetCode
 ***Tipo: Dynamic Programming
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

int dp[2001][2001];
class Solution {
public:
    string s;
    int n, n1, n2;
    int solve(int left, int right){
        if(left > right)
            return 0;
        
        if( left == right )
            return 1;
        
        if( dp[left][right] != -1 )
            return dp[left][right];
        
        int res = 0;        
        if( s[left] == s[right])
            res = 2 + solve(left + 1, right - 1);
        res = max( res, solve(left + 1, right));
        res = max( res, solve(left, right - 1));      
        return dp[left][right] = res;
    }
    
    int longestPalindrome(string s1, string s2) {
        s = s1 + s2;
        n = s.size();
        n1 = s1.size(); n2 = s2.size();
        memset(dp, -1, sizeof(dp));
        
        int res = 0;
        for( int i = 0 ; i < n1 ; ++i ){
            for( int j = 0 ; j < n2 ; ++j ){
                if( s1[i] == s2[j]){
                    res = max(res, solve(i, j + n1));
                }
            }
        }        
        return res;
    }
};
