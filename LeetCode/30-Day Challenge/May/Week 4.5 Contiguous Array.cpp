/*******************************************
 ***Problema: Contiguous Array
 ***ID: Week4.5
 ***Juez: LeetCode
 ***Tipo: Hashing
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> hash;
        int sum = 0, res = 0;
        hash[0] = 0;
        for( int i = 1 ; i <= n ; ++i ){
            if( nums[i - 1] == 0 ) sum--;
            else sum++;
            if( hash.count(sum) ){
                res = max(res, i - hash[sum]);
            }else
                hash[sum] = i;
        }
        return res;
    }
};
