/*******************************************
 ***Problema: Count of Range Sum
 ***ID: 327
 ***Juez: LeetCode
 ***Tipo: Merge Sort Variation
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    typedef long long LL;
    int mergeSort(vector<LL> &sums, int left, int right, int lower, int upper){
        if( left + 1 >= right ) return 0;
        int mid = (left + right) / 2;
        int total_left  = mergeSort(sums, left, mid, lower, upper);
        int total_right = mergeSort(sums, mid, right, lower, upper);
        int total = total_left + total_right;
        int right_index = mid, sorted_index = 0, lower_index = mid, upper_index = mid;
        vector<LL> sorted(right - left);
        for( int i = left ; i < mid ; ++i ){
            while( lower_index < right && sums[lower_index] - sums[i] < lower ) lower_index++;
            while( upper_index < right && sums[upper_index] - sums[i] <= upper ) upper_index++;
            while( right_index < right && sums[i] > sums[right_index] ){
                sorted[sorted_index++] = sums[right_index++];
            }
            sorted[sorted_index++] = sums[i];
            total += upper_index - lower_index;
        }
        for( int i = 0 ; i < sorted_index; ++i )
            sums[left + i] = sorted[i];
        return total;
    }
    
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        vector<LL> sums(nums.size() + 1);
        for( int i = 0 ; i < nums.size(); ++i )
            sums[i + 1] = sums[i] + nums[i];
        return mergeSort(sums, 0, nums.size() + 1, lower, upper);
    }
};
