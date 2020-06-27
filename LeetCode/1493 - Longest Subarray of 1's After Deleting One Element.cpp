/*******************************************
 ***Problema: Longest Subarray of 1's After Deleting One Element
 ***ID: 1493
 ***Juez: LeetCode
 ***Tipo: Prefix + Suffix sums
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> left(n + 1);
        int cnt = 0;
        
        for( int i = 0 ; i < n ; ++i ){            
            if( nums[i] == 1 ){
                cnt++;
            }else{
                left[i] = cnt;
                cnt = 0;
            }
        }
        
        int res = -1;
        cnt = 0;
        for( int i = n - 1; i >= 0 ; --i ){            
            if( nums[i] == 1 ){
                cnt++;
            }else{
                res = max(res, left[i] + cnt);
                cnt = 0;
            }
        }
        if( res == -1 ) res = n - 1;
        return res;
        
    }
};
