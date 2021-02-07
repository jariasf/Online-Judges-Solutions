/*******************************************
 ***Problema: Sum of Unique Elements
 ***ID: 1748
 ***Juez: LeetCode
 ***Tipo: Ad hoc - Hashing
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int, int> seen;
        int res = 0;
        for( int val : nums ){
            seen[val]++;
        }
        for(auto it:seen){
            if(it.second == 1) res+= it.first;
        }
        return res;
    }
};
