/*******************************************
 ***Problema: Perform String Shifts
 ***ID: Week2.8
 ***Juez: LeetCode
 ***Tipo: Dynamic Programming
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> out(n + 1, 1);
        out[n - 1] = nums[n - 1];
        for( int i = n - 2 ; i >= 0 ; --i ) out[i] = nums[i] * out[i + 1];
        int left = 1;
        for( int i = 0 ; i < n ; ++i ){
            out[i] = left * out[i + 1];
            left *= nums[i];
        }
        out.pop_back();
        return out;
    }
};
