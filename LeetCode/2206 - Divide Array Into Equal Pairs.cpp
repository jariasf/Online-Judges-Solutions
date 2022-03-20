/*******************************************
 ***Problema: Divide Array Into Equal Pairs
 ***ID: 2206
 ***Juez: LeetCode
 ***Tipo: Hashing
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int, int> hash;
        
        for( int val : nums ){
            hash[val]++;
        }
        
        for( auto it: hash ){
            if( it.second % 2 != 0 ) return false;
        }
        return true;
    }
};
