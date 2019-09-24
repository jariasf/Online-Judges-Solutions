/*******************************************
 ***Problema: Kth Largest Element
 ***ID: 5
 ***Juez: LintCode
 ***Tipo: Partition - Quicksort
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    /**
     * @param n: An integer
     * @param nums: An array
     * @return: the Kth largest element
     */
    int partition(vector<int> &nums, int left, int right){
        int pivot = nums[left];
        int start = left + 1;
        for( int i = left + 1 ; i < right ; ++i ){
            if( nums[i] <= pivot ){
                swap( nums[start++], nums[i]);
            }
        }
        swap(nums[left], nums[start - 1]);
        return start - 1;
    } 
     
    int solve(vector<int> &nums, int left, int right, int k ){
        if( left < right ){
            int pos = partition(nums, left, right);
            int left_cnt = pos - left + 1;
            if( left_cnt == k ){
                return nums[pos];
            }
            if( k < left_cnt ){
                return solve(nums, left, pos, k);
            }else{
                return solve(nums, pos + 1, right, k - left_cnt );
            }
        }
        return -1;
    } 
     
    int kthLargestElement(int n, vector<int> &nums) {
        int k = nums.size() - n + 1;
        return solve(nums, 0, nums.size(), k);
    }
};
