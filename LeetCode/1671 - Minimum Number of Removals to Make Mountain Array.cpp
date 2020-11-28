/*******************************************
 ***Problema: Minimum Number of Removals to Make Mountain Array
 ***ID: 1671
 ***Juez: LeetCode
 ***Tipo: Dynamic Programming (LIS + LDS)
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
   
    vector<int> dp_lis(vector<int> &a ){
        int n = a.size();
        vector<int> dp(n);
        for( int i = 0 ; i < n ; ++i ) dp[ i ] = 1;
        for( int i = 0 ; i < n ; ++i ){
            for( int j = i + 1  ; j < n ; ++j ){
                if( a[ i ] < a[ j ] && dp[ j ] < dp[ i ] + 1 ){
                    dp[ j ] = dp[ i ] + 1;
                }
            }
        }
        return dp;
    }
    
    
    int minimumMountainRemovals(vector<int>& nums) {
        vector<int> lis = dp_lis(nums);
        reverse(nums.begin(), nums.end());
        vector<int> lds = dp_lis(nums);
        reverse(lds.begin(), lds.end());
        int res = INT_MAX;
        for( int i = 1 ; i < nums.size() - 1; ++i ){
            int left = i + 1 - lis[i], right = nums.size() - i - lds[i];
            res = min(res, left + right);
        }
        
        return res;
    }
};
