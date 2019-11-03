/*******************************************
 ***Problema: Count Number of Nice Subarrays
 ***ID: 1248
 ***Juez: LeetCode
 ***Tipo: Sliding Window
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int result = 0, odd = 0, even = 0;
        
        int left_even = 0, right_even = 0;
        for(int left = 0, i = 0; i < n ; ++i ){
            if( nums[i] & 1 ) odd++;
            while( left <= i && odd > k ){
                if( nums[left] & 1 ){
                    odd--;
                }
                left++;
            }
            
            if( odd == k ){                
                left_even = right_even = 0;
                
                while( left <= i && nums[left] % 2 == 0 ){
                    left_even++;
                    left++;
                }
                
                int right = i + 1;
                while( right < n && nums[right] % 2 == 0 ){
                    right_even++;
                    right++;
                }
                i = right - 1;
                result += (left_even + 1) * (right_even + 1);    
                
            }
            
        }
        return result;
    }
};
