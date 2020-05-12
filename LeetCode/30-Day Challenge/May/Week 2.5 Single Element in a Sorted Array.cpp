/*******************************************
 ***Problema: Single Element in a Sorted Array
 ***ID: Week2.5
 ***Juez: LeetCode
 ***Tipo: Binary Search
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

// Using XOR
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

// Checking odd/even pairs
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n;
        while( left < right ){
            int mid = (left + right)/2;
            if( mid - 1 >= 0 && nums[mid] == nums[mid - 1]){
                if( mid & 1)
                    left = mid + 1;
                else
                    right = mid;
            }else if( mid + 1 < n && nums[mid] == nums[mid + 1]){
                if( mid & 1)
                    right = mid;
                else
                    left = mid + 1;                
            }else{
                return nums[mid];
            }
        }
        return -1;
    }
};
