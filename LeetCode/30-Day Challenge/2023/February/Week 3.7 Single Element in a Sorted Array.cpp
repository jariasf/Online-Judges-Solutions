/*******************************************
 ***Problema: Single Element in a Sorted Array
 ***ID: Week 3.7
 ***Juez: LeetCode
 ***Tipo: Binary Search
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

// Solution 1: Comparing even|odd indices
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size(), left = 0 , right = n, mid;
        while( left < right ){
            mid = (left + right)/2;
            if( mid & 1){
                if( nums[mid] == nums[mid - 1]){
                    left = mid + 1;
                }else{
                    right = mid;
                }
            }else if( mid + 1 < n && nums[mid] == nums[mid + 1]){
                left = mid + 1;
            }else{
                right = mid;
            }
        }
        return nums[left];
    }
};


// Solution 2: Comparison using xor
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n - 1;
        while( left < right ){
            int mid = (left + right)/2;
            if( nums[mid] == nums[mid^1])
                left = mid + 1;
            else
                right = mid;
        }
        return nums[left];
    }
};
