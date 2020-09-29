/*******************************************
 ***Problema: Subarray Product Less Than K
 ***ID: Week4.7
 ***Juez: LeetCode
 ***Tipo: Sliding Window
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    typedef long long LL;
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if( k == 0 ) return 0;
        int n = nums.size(), res = 0, p = 1;
        for( int left = 0, right = 0; right < n ; ++right ){
            p *= nums[right];
            while( p >= k && left <= right ){
                p /= nums[left++];
            }
            res += right - left + 1;
        }
        return res;
    }
};
