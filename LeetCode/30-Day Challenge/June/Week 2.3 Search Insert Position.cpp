/*******************************************
 ***Problema: Search Insert Position
 ***ID: Week2.3
 ***Juez: LeetCode
 ***Tipo: Binary Search
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size();
        while( left < right ){
            int mid = (left + right)/2;
            if( nums[mid] < target )
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }
};
