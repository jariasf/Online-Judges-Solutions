/*******************************************
 ***Problema: Find Two Non-overlapping Sub-arrays Each With Target Sum
 ***ID: 1477
 ***Juez: LeetCode
 ***Tipo: Hashing + DP
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    typedef long long LL;
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        LL sum = 0; 
        LL minimum = INT_MAX, res = INT_MAX;
        unordered_map<int, int> hash;
        hash[0] = 0;        
        vector<LL> v(n + 2, INT_MAX );
        for( int i = 1 ; i <= n ; ++i ){
            sum += arr[i - 1];
            if( hash.find(sum - target) != hash.end() ){
                LL len = i - hash[sum - target];
                res = min( res, len + v[ hash[sum - target] ]);
                v[i] = min(v[i - 1], len);
            }else{
                v[i] = v[i - 1];
            }
            hash[sum] = i;
        }
        if( res == INT_MAX ) return -1;
        return res;
    }
};
