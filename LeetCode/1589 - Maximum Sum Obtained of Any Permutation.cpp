/*******************************************
 ***Problema: Maximum Sum Obtained of Any Permutation
 ***ID: 1589
 ***Juez: LeetCode
 ***Tipo: Sweep Line
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int MOD = 1e9+7;   
    typedef long long LL;
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& req) {
        int maxi = 0;
        for( int i = 0 ; i < req.size(); ++i ){
            int s = req[i][0], e = req[i][1];
            maxi = max(maxi, e + 5);
        }
        
        vector<int> freq(maxi);
        for( int i = 0 ; i < req.size(); ++i ){
            int s = req[i][0], e = req[i][1] + 1;
            freq[s]++; freq[e]--;
        }
        
        for( int i = 0 ; i < maxi ; ++i ){
            if( i - 1 >= 0 )
                freq[i] += freq[i - 1];
        }
        
        int res = 0;
        sort(freq.rbegin(), freq.rend());
        sort(nums.rbegin(), nums.rend());
        for( int i = 0 ; i < nums.size() ; ++i ){
            res = res + (LL)nums[i] * freq[i];
            res %= MOD;
        }        
        
        return res % MOD;
    }
};
