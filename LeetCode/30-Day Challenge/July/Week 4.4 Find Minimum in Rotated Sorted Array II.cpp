/*******************************************
 ***Problema: Find Minimum in Rotated Sorted Array II
 ***ID: Week4.4
 ***Juez: LeetCode
 ***Tipo: Binary Search
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n - 1;
        while( left < right ){
            int mid = ( left + right ) / 2;
            if( nums[left] == nums[mid] && nums[right] == nums[left]){
                left++; 
                continue;
            }
            
            if( nums[mid] > nums[right] ){
                left = mid + 1;
            }else
                right = mid;
        }
        return nums[left];
    }
};
