/*******************************************
 ***Problema: Largest Divisible Subset
 ***ID: Week2.5
 ***Juez: LeetCode
 ***Tipo: DP - LIS
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), maxi = 0, index = 0;
        if( n == 0 ) return {};
        vector<int> dp(n + 1);
        vector<int> prev(n + 1, -1);
        for( int i = 0 ; i < n ; ++i ){
            for( int j = i - 1 ; j >= 0 ; --j ){
                if( nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1 ){
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
            if( maxi < dp[i]){
                maxi = dp[i];
                index = i;
            }
        }
        vector<int> res;
        while( index != -1 ){
            res.push_back(nums[index]);
            index = prev[index];
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
