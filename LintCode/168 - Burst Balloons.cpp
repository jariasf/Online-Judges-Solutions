/*******************************************
 ***Problema: Burst Balloons
 ***ID: 168
 ***Juez: LintCode
 ***Tipo: Dynamic Programming
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    /**
     * @param nums: A list of integer
     * @return: An integer, maximum coins
     */
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
