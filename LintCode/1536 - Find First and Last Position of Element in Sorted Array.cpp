/*******************************************
 ***Problema: Find First and Last Position of Element in Sorted Array
 ***ID: 1536
 ***Juez: LintCode
 ***Tipo: Binary Search
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    
    int lowerBound(vector<int> &nums, int target){
        int left = 0, right = nums.size();
        while( left < right ){
            int mid = (left + right)/2;
            if( nums[mid] < target ){
                left = mid + 1;
            }else{
                right = mid;
            }
        }
        if( right == nums.size() || nums[right] != target ) right = -1;        
        return right;
    }
    
    int upperBound(vector<int> &nums, int target){
        int left = 0, right = nums.size();
        while( left < right ){
            int mid = (left + right)/2;
            if( nums[mid] <= target ){
                left = mid + 1;
            }else{
                right = mid;
            }
        }
        if( left - 1 >= 0 && nums[left - 1] != target ) left = 0;
        return left - 1;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int low = lowerBound(nums, target);      
        int up = upperBound(nums, target);
        vector<int> v = {low, up};
        return v;
    }
};
