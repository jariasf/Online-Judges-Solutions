/*******************************************
 ***Problema: K-diff Pairs in an Array
 ***ID: Week1.3
 ***Juez: LeetCode
 ***Tipo: Hashing
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int> hash;
        for(int val:nums)
            hash[val]++;

        int res = 0;
        for(auto it:hash){
            if( hash.find(it.first + k) != hash.end() ){
                if( k == 0 )
                    res += (hash[it.first] > 1);
                else
                    res++;
            }
        }

        return res;
    }
};
