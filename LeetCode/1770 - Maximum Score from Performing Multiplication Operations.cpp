/*******************************************
 ***Problema: Maximum Score from Performing Multiplication Operations
 ***ID: 1770
 ***Juez: LeetCode
 ***Tipo: Dynamic Programming
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

int dp[1001][1001];
class Solution {
public:
    int n , m;
    vector<int> nums, v;
    int solve(int left, int right){
        int n = nums.size(), m = v.size();
        if( left + right > m ) 
            return -(1<<30);
        if( left + right == m )
            return 0;
        
        if( dp[left][right] != -1 )
            return dp[left][right];
        
        int res = nums[left] * v[left + right] + solve(left + 1, right);
        res = max(nums[n - right - 1] * v[left + right] + solve(left, right + 1), res);
        return dp[left][right] = res;
    }
    
    int maximumScore(vector<int>& _nums, vector<int>& _v) {
        n = nums.size(); m = v.size();        
        nums = _nums;
        v = _v;        
        memset(dp, -1, sizeof(dp));
        return solve(0, 0);
    }
};
