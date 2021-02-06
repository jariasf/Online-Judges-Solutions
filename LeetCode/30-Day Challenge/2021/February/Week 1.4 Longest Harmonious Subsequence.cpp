/*******************************************
 ***Problema: Longest Harmonious Subsequence
 ***ID: Week1.4
 ***Juez: LeetCode
 ***Tipo: Hashing
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int> hash;
        for(int val: nums) hash[val]++;
        int res = 0;
        for(auto it: hash){
            int val = it.first;
            if( hash.find(val - 1) != hash.end() ){
                res = max(res, it.second + hash[val - 1]);
            }
        }
        return res;
    }
};
