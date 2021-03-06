/*******************************************
 ***Problema: Missing Number
 ***ID: Week1.3
 ***Juez: LeetCode
 ***Tipo: Bitwise (XOR)
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int all = 0, cur = nums[0];
        for(int i = 1 ; i < nums.size(); ++i ) cur ^= nums[i];
        for(int i = 1 ; i <= nums.size(); ++i ) all ^= i;
        return all ^ cur;
    }
};
