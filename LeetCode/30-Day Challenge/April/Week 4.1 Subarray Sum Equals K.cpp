/*******************************************
 ***Problema: Subarray Sum Equals K
 ***ID: Week4.1
 ***Juez: LeetCode
 ***Tipo: Hashing
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        int n = nums.size();
        int result = 0, sum = 0;
        cnt[0] = 1;
        for( int i = 0 ; i < n ; ++i ){
            sum += nums[i];
            if( cnt.count(sum - k) > 0 ){
                result += cnt[sum - k];
            }
            cnt[sum]++;
        }
        return result;
    }
};
