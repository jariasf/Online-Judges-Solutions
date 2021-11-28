/*******************************************
 ***Problema: Removing Minimum and Maximum From Array
 ***ID: 2091
 ***Juez: LeetCode
 ***Tipo: Greedy
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mini = nums[0], maxi = nums[0], n = nums.size();
        if( n == 1 ) return 1;
        
        int idx_min = 0, idx_max = 0;
        for( int i = 0 ; i < n ; ++i ){
            if( mini > nums[i] ){
                idx_min = i;
                mini = nums[i];
            }
            if( maxi < nums[i]){
                idx_max = i;
                maxi = nums[i];
            }
        }

        int left = 0 , right = n;    
        int res = INT_MAX;
        
        if( idx_min >= idx_max )
            swap(idx_min, idx_max);
        
        res = idx_max + 1;
        res = min(res, (idx_min + 1) + (n - idx_max));
        res = min(res, (n - idx_min));
        return res;
        
    }
};
