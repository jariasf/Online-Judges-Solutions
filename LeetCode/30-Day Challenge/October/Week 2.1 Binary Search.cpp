/*******************************************
 ***Problema: Binary Search
 ***ID: Week2.1
 ***Juez: LeetCode
 ***Tipo: Binary Search
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size();
        while( left < right ){
            int mid = (left + right)/2;
            if(nums[mid] == target)
                return mid;
            if( nums[mid] < target )
                left = mid + 1;
            else
                right = mid;
        }
        return -1;
    }
};
