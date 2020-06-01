/*******************************************
 ***Problema: Maximum Product of Two Elements in an Array 
 ***ID: 1464
 ***Juez: LeetCode
 ***Tipo: Sorting
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        sort( nums.begin(), nums.end() );
        return (nums[ n - 1 ] - 1) * (nums[n - 2] - 1);
    }
};
