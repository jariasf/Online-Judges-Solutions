/*******************************************
 ***Problema: Maximum Absolute Sum of Any Subarray
 ***ID: 1749
 ***Juez: LeetCode
 ***Tipo: Prefix sums
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> sums(n + 1);
        int mini = INT_MAX, maxi = INT_MIN;
        for( int i = 1 ; i <= n ; ++i ){
            sums[i] = sums[i - 1] + nums[i - 1];
        }

        for( int i = 0 ; i <= n ; ++i ){
            mini = min(mini, sums[i]);
            maxi = max(maxi, sums[i]);
        }
        return maxi - mini;
    }
};
