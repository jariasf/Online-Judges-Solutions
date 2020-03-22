/*******************************************
 ***Problem: Create Target Array in the Given Order
 ***ID: 1389
 ***Judge: LeetCode
 ***Type: Ad hoc
 ***Author: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        int n = nums.size();
        vector<int> res;
        for( int i = 0 ; i < n ; ++i ){
            res.insert(res.begin() + index[i], nums[i]);
        }
        return res;
    }
};
