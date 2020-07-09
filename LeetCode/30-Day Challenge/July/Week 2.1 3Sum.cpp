/*******************************************
 ***Problema: 3Sum
 ***ID: Week2.1
 ***Juez: LeetCode
 ***Tipo: Two Pointers
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > res;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for( int i = 0 ; i < n ; ++i ){
            if( i > 0 && nums[i] == nums[i - 1]) continue;
            int A = -nums[i];
            int left = i + 1, right = n - 1;
            while( left < right ){
                if( nums[left] + nums[right] == A ){
                    res.push_back({nums[i], nums[left], nums[right]});
                    while( left < right && nums[left] == nums[left + 1] )
                        left++;
                    left++;
                }else if( nums[left] + nums[right] < A ){
                    left++;
                }else
                    right--;
            }
        }
        return res;
    }
};
