/*******************************************
 ***Problema: Burst Balloons
 ***ID: 312
 ***Juez: LeetCode
 ***Tipo: Dynamic Programming
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

//Iterative
class Solution {
public:
    int maxCoins(vector<int> &nums){
        int n = nums.size();
        vector<vector<int> > dp(n + 2, vector<int>(n + 2, 0));
        for( int right = 1 ; right <= n + 1; ++right ){
            for( int left = right - 1 ; left >= 0 ; --left ){
                for( int i = left + 1 ; i <= right - 1 ; ++i ){
                    int product = nums[i - 1];
                    if( left >= 1 )
                        product *= nums[left - 1];
                    if( right <= n )
                        product *= nums[right - 1];
                    dp[left][right] = max( dp[left][right], product + dp[left][i] + dp[i][right]);
                }
            }
        }
        return dp[0][n+1];
    }
};


//Recursive
class Solution {
public:
    vector<vector<int> > dp;
    int maxCoins(vector<int> &nums, int left, int right){
        int n = nums.size();
        
        if( left >= right )
            return 0;
        
        if(dp[left][right] != -1 ) 
            return dp[left][right];
        
        int maximum = 0;
        for( int i = left + 1 ; i <= right - 1; ++i ){
            int product = nums[i - 1];
            if( left >= 1 ){
                product *= nums[left - 1];
            }
            if( right <= n ){
                product *= nums[right - 1];
            }
            maximum = max(maximum, product + maxCoins(nums, left, i) + maxCoins(nums, i , right));
        }
        return dp[left][right] = maximum;
    } 
     
    int maxCoins(vector<int> &nums) {
        int n = nums.size();
        dp = vector<vector<int> >(n + 2, vector<int>(n + 2, -1) );
        return maxCoins(nums, 0, n + 1);
    }
};
