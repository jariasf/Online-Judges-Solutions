/*******************************************
 ***Problema: Make Sum Divisible by P
 ***ID: 1590
 ***Juez: LeetCode
 ***Tipo: Hashing + Math
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/


class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        int target = 0;
        for( int i = 0 ; i < n ; ++i )
            target = ( target + nums[i] ) % p ;
        if( target == 0 ) return 0;
        int res = n + 1, sum = 0;
        unordered_map<int, int> hash;
        hash[0] = -1;        
        for( int i = 0 ; i < n ; ++i ){
            sum = (sum + nums[i]) % p;
            int prev = (sum - target + p) % p;
            if( hash.find( prev ) != hash.end() ){
                res = min(res, i - hash[prev]);
            }           
            hash[sum] = i;
        }
        if( res >= n ) return -1;
        return res;
    }
};
