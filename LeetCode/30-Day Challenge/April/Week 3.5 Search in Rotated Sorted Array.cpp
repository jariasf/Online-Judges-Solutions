/*******************************************
 ***Problema: Search in Rotated Sorted Array
 ***ID: Week3.5
 ***Juez: LeetCode
 ***Tipo: Binary Search
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0, right = n;
        while( left < right ){
            int mid = (left + right)/2;
            if( nums[mid] == target )
                return mid;
            if( nums[mid] > nums[left]){
                if( nums[mid] < target || target < nums[left] ){
                    left = mid + 1;
                }else
                    right = mid;
            }else{
                if( nums[mid] < target && target < nums[left] ){
                    left = mid + 1;
                }else
                    right = mid;
            }
        }
        return -1;
    }
};
