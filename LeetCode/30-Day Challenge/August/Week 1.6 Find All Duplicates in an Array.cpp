/*******************************************
 ***Problema: Find All Duplicates in an Array
 ***ID: Week1.6
 ***Juez: LeetCode
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        for( int i = 0 ; i < n ; ++i ){
            int index = abs(nums[i]) - 1;
            if( nums[index] < 0 )
                res.push_back(index + 1);
            nums[index] = -nums[index];
        }
        return res;
    }
};
