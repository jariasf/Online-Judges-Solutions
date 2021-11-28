/*******************************************
 ***Problema: K Radius Subarray Averages
 ***ID: 2090
 ***Juez: LeetCode
 ***Tipo: Sliding window
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    typedef long long LL;
    vector<int> getAverages(vector<int>& nums, int k) {
        if( k == 0 ) return nums;
        int n = nums.size();
        vector<int> res(n, -1);
        int sz = 2 * k + 1;        
        if( sz > n ) return res;
        LL sum = 0;
        for( int i = 0 ; i < sz ; ++i )
            sum += nums[i];

        for( int i = k ; i < n - k ; ++i ){
            res[i] = sum/sz;
            sum -= nums[i - k];
            if( i + k + 1 < n )
                sum += nums[i + k + 1];
        }
        return res;
    }
};
