/*******************************************
 ***Problema: Reverse Subarray To Maximize Array Value
 ***ID: 1330
 ***Juez: LeetCode
 ***Tipo: Ad hoc - Math (Hard)
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    
    int maxValueAfterReverse(vector<int>& nums) {
        int n = nums.size();
        
        int tot = 0;
        for( int i = 1 ; i < n ; ++i ){
            tot += abs(nums[i] - nums[i - 1]);
        }
        
        int res = tot;
        
        // Reverse between [1:n-2]
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for( int i = 1 ; i < n ; ++i ){
            mini = min( mini, max(nums[i - 1], nums[i]));
            maxi = max( maxi, min(nums[i - 1], nums[i]));
        }
        res = max(0, tot + 2*(maxi - mini) );
        
        // Reverse at the beginning or end of the array
        for( int i = 1 ; i < n ; ++i ){
            res = max(res, tot - abs(nums[i - 1] - nums[i]) + abs(nums[i - 1] - nums[n - 1]) );
            res = max(res, tot - abs(nums[i - 1] - nums[i]) + abs(nums[0] - nums[i]) );            
        }
        
        return res;
    }
};
