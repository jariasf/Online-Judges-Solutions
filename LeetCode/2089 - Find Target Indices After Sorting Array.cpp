/*******************************************
 ***Problema: Find Target Indices After Sorting Array
 ***ID: 2089
 ***Juez: LeetCode
 ***Tipo: Ad hoc - Sorting
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int> res;
        sort(nums.begin(), nums.end());
        for( int i = 0 ; i< nums.size(); ++i ){
            if( nums[i] == target) res.push_back(i);
        }
        return res;
    }
};
