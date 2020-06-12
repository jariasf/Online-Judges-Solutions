/*******************************************
 ***Problema: Sort Colors
 ***ID: Week2.4
 ***Juez: LeetCode
 ***Tipo: Three Pointers
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int left = 0, mid = 0, right = n - 1;
        while( mid <= right ){
            if( nums[mid] == 0 ){
                swap(nums[left++], nums[mid++]);
            }else if( nums[mid] == 1 ){
                mid++;
            }else {
                swap(nums[mid], nums[right--]);
            }
        }
    }
};
