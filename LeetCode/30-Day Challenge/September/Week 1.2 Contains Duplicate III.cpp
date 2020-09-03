/*******************************************
 ***Problema: Contains Duplicate III
 ***ID: Week1.2
 ***Juez: LeetCode
 ***Tipo: Set
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long> hash;
        for( int i = 0 ; i < nums.size(); ++i ){
            if( i > k ) hash.erase(nums[i - k - 1]);
            auto it = hash.lower_bound((long)nums[i] - t);
            if( it != hash.end() && *it - nums[i] <= t ) return true;
            hash.insert(nums[i]);
        }
        return false;
    }
};
