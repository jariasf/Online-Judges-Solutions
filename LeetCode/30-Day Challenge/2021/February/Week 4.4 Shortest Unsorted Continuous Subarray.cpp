/*******************************************
 ***Problema: Shortest Unsorted Continuous Subarray
 ***ID: Week4.4
 ***Juez: LeetCode
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    //[1,4,9,5,3,8,10]
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size(), left = -1, right = n - 1, res = n;
        
        for( int i = 0 ; i < n - 1 ; ++i ){
            if( nums[i] > nums[i + 1] ){
                if( left == -1 ){
                    left = i;
                }
                right = i + 1;
            }
        }
        
        if( left == -1 ) return 0;
        int mini = INT_MAX, maxi = INT_MIN;
        for( int i = left ; i <= right ; ++i ){
            maxi = max(maxi, nums[i]);
            mini = min(mini, nums[i]);
        }
        
        
        for( int i = 0 ; i < left ; ++i ){
            if( nums[i] > mini ){
                left = i;
                break;
            }
        }
        
        for( int i = right + 1 ; i < n ; ++i ){
            if( nums[i] < maxi ){
                right = i;
            }else
                break;
        }
        
        res = min(res, right - left + 1);
       
        return res;
    }
};
