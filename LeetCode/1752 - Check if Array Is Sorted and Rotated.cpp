/*******************************************
 ***Problema: Check if Array Is Sorted and Rotated
 ***ID: 1752
 ***Juez: LeetCode
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size(), cnt = 0;
        for( int i = 0 ; i < n; ++i ){
            if( nums[i] > nums[(i + 1) % n] && ++cnt > 1 )
                return false;
        }
        return true;
    }
};
