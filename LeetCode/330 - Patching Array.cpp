/*******************************************
 ***Problema: Patching Array
 ***ID: 327
 ***Juez: LeetCode
 ***Tipo: Greedy
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    typedef long long LL;
    int minPatches(vector<int> &nums, int n) {
        LL max_range = 1;
        int nums_index = 0, add_elements = 0;
        while( max_range <= n ){
            if( nums_index < nums.size() && nums[ nums_index ] <= max_range ){
                max_range += nums[ nums_index++ ];
            }else{
                max_range <<= 1LL;
                add_elements++;
            }
        }
        return add_elements;
    }
};
