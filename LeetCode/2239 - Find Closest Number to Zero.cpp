/*******************************************
 ***Problema: Find Closest Number to Zero
 ***ID: 2239
 ***Juez: LeetCode
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int n = nums.size(), mini = 1<<30, res = 0;
        for( int val: nums ){
            int v = val;
            if( val < 0 ){
                v = -val;
            }
            if( v < mini ){
                mini = v;
                res = val;
            }else if( v == mini ){
                res = max(res, val);
            }
        }
        return res;
    }
};
