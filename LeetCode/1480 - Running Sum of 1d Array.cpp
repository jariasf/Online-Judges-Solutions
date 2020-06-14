/*******************************************
 ***Problema: Running Sum of 1d Array
 ***ID: 1480
 ***Juez: LeetCode
 ***Tipo: Prefix Sums
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> sum(nums.size());
        sum[0] = nums[0];
        for( int i = 1 ; i < nums.size(); ++i )
            sum[i] = sum[i - 1] + nums[i];
        return sum;
    }
};
