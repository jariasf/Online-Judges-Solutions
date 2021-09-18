/*******************************************
 ***Problema: Minimum Number of Operations to Make Array Continuous
 ***ID: 2009
 ***Juez: LeetCode
 ***Tipo: Two Pointers
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        nums.resize(unique(nums.begin(), nums.end()) - nums.begin());
        int maxi = 0;
        for( int right = 0, left = 0 ; right < nums.size() ; ++right ){
            while( nums[right] - nums[left] + 1 > n )
                left++;
            maxi = max(maxi, right - left + 1);
        }
        return n - maxi;
    }
};
