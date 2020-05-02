/*******************************************
 ***Problema: Single Number
 ***ID: Week1.1
 ***Juez: LeetCode
 ***Tipo: Bit Operations
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = nums[0];
        for( int i = 1 ; i < nums.size(); ++i ) result ^= nums[i];
        return result;
    }
};
