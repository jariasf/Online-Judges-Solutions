/*******************************************
 ***Problema: First Missing Positive
 ***ID: Week5.2
 ***Juez: LeetCode
 ***Tipo: Hashing
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> hash;
        int mini = 1<<30;
        for(int val: nums ){
            if( val > 0 ){
                mini = min( mini, val);
                hash.insert(val);
            }
        }
        
        for( int i = 1 ; ; ++i ){
            if( hash.find(i) == hash.end() )
                return i;
        }
        return -1;
    }
};
