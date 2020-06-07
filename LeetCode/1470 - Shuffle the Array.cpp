/*******************************************
 ***Problema: Shuffle the Array
 ***ID: 1470
 ***Juez: LeetCode
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int m = n;
        vector<int> res;
        for( int i = 0 ; i < m ; ++i ){
            res.push_back(nums[i]);
            res.push_back(nums[m + i]);
        }
        return res;
    }
};
