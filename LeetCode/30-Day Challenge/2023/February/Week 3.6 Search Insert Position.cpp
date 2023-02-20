/*******************************************
 ***Problema: Search Insert Position
 ***ID: Week 3.6
 ***Juez: LeetCode
 ***Tipo: Binary Search
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0 , right = nums.size(), mid;
        while( left < right ){
            mid = (left + right) / 2;
            if( nums[mid] == target ){
                return mid;
            }else if( nums[mid] < target){
                left = mid + 1;
            }else{
                right = mid;
            }
        }
        return left;
    }
};
