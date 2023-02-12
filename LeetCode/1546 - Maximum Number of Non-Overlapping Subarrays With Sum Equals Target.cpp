/*******************************************
 ***Problema: Maximum Number of Non-Overlapping Subarrays With Sum Equals Target
 ***ID: 1546
 ***Juez: LeetCode
 ***Tipo: Prefix Sums + Hashing
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    typedef long long LL;
    int maxNonOverlapping(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<LL,int > hash;
        LL sum = 0;
        int res = 0, last_index = -1;
        hash[0] = 0;
        for( int i = 0 ; i < n ; ++i ){
            sum += nums[i];
            if( hash.find(sum - target) != hash.end() ){
                int index = hash[sum - target];
                if( index > last_index ){
                    res++;
                    last_index = i;
                }
            }
            hash[sum] = i + 1;
        }
        return res;
    }
};
