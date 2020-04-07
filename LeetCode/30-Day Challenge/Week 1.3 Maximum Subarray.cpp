/*******************************************
 ***Problema: Maximum Subarray
 ***ID: Week1.3
 ***Juez: LeetCode
 ***Tipo: Kadane 1D
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int sum = 0, maxi = INT_MIN;
        for( int i = 0 ; i < n ; ++i ){
            sum += nums[i];
            if( sum > maxi ){
                maxi = sum;
            }
            if( sum < 0 ) sum = 0;
        }
        return maxi;
    }
};
