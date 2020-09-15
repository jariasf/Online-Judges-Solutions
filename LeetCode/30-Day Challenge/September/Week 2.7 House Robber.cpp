/*******************************************
 ***Problema: House Robber
 ***ID: Week2.7
 ***Juez: LeetCode
 ***Tipo: Dynamic Programming
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

// time: O(n), space: O(1) 
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int one = 0, two = 0;
        for( int i = 0 ; i < n ; ++i ){
            int tmp = one;
            one = max(one, two + nums[i]);
            two = max(two, tmp);
        }
        return one;
    }
};

// time: O(n), space: O(n)
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0 ) return 0;
        if(n < 2) return nums[0];
        vector<int> dp(n + 5);
        dp[0] = 0;
        dp[1] = nums[0];
        dp[2] = max(dp[1], nums[1]);
        for( int i = 2 ; i < n ; ++i ){
            dp[i + 1] = max(dp[i - 1] + nums[i], dp[i]);
        }
        return dp[n];
    }
};
