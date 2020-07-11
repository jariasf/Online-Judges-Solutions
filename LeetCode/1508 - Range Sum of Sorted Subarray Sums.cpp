/*******************************************
 ***Problema: Range Sum of Sorted Subarray Sums
 ***ID: 1508
 ***Juez: LeetCode
 ***Tipo: Ad hoc - Brute Force
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int MOD = 1e9+7;
    typedef long long LL;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<LL> v;
        LL sum;
        for( int i = 0 ; i < n ; ++i ){
            sum = 0;
            for( int j = i ; j < n ; ++j ){
                sum = (sum + nums[j]) % MOD;
                v.push_back(sum);
            }
        }
        sort(v.begin(), v.end());
        LL res = 0;
        for( int i = left - 1 ; i < right ; ++i ){
            res = (res + v[i] )% MOD;
        }
        return res;
    }
};
