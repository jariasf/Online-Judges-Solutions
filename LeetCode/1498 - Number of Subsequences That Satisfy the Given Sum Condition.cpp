/*******************************************
 ***Problema: Number of Subsequences That Satisfy the Given Sum Condition
 ***ID: 1498
 ***Juez: LeetCode
 ***Tipo: Sorting + Two Pointers
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int MOD = 1e9 + 7;
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> pot(n);
        pot[0] = 1;
        for( int i = 1 ; i < n ; ++i ){
            pot[i] = pot[i - 1] * 2;
            pot[i] %= MOD;
        }
        int left = 0, right = n - 1, res = 0;
        while( left <= right ){
            if( nums[left] + nums[right] > target ){
                right--;
            }else{
                res = (res + pot[right - left]) % MOD;
                left++;
            }
        }
        return res;
    }
};
