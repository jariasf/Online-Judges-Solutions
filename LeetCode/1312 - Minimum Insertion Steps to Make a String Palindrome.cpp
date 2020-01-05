/*******************************************
 ***Problema: Minimum Insertion Steps to Make a String Palindrome
 ***ID: 1312
 ***Juez: LeetCode
 ***Tipo: DP
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    string s;    
    vector<vector<int> > dp;
    int solve(int left, int right){
        if(left >= right ){
            return 0;
        }
        
        if( dp[left][right] != -1 ){
            return dp[left][right];
        }
        
        int res = 1<<30;
        if( s[left] == s[right] ){
            res = solve(left + 1, right - 1);
        }else{
            res = 1 + min(solve(left + 1, right), solve(left, right - 1));
        }
        return dp[left][right] = res;
    }
    
    int minInsertions(string _s) {
        int n = _s.size();
        s = _s;
        dp = vector<vector<int> >(n + 5, vector<int>(n + 5, -1) );
        return solve(0, n - 1);
    }
};
