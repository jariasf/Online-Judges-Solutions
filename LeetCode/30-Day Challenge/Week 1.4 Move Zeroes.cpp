/*******************************************
 ***Problema: Move Zeroes
 ***ID: Week1.4
 ***Juez: LeetCode
 ***Tipo: Two Pointers
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int index = -1;
        for( int i = 0 ; i < n ; ++i ){
            if( nums[i] == 0 && index == -1 ){
                index = i;
            }else if( nums[i] != 0 && index >= 0 ){
                swap(nums[i], nums[index]);
                index++;
            }
        }
    }
};
