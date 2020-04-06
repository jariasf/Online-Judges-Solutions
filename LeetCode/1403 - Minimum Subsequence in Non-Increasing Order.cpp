/*******************************************
 ***Problem: Minimum Subsequence in Non-Increasing Order
 ***ID: 1403
 ***Judge: LeetCode
 ***Type: Sorting
 ***Author: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        sort(nums.rbegin(), nums.rend());
        int n = nums.size();
        int tot = 0;
        for( int i = 0 ; i < n ; ++i ) tot += nums[i];
        int sum = 0;
        vector<int> res;
        for( int i = 0 ; i < n ; ++i ){
            sum += nums[i];
            tot -= nums[i];
            res.push_back(nums[i]);
            if(sum > tot ) break;
        }
        return res;
    }
};
