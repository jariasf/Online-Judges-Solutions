/*******************************************
 ***Problema: Number of Good Pairs
 ***ID: 1512
 ***Juez: LeetCode
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int n = nums.size(), cnt = 0;
        for( int i = 0 ; i < n ; ++i ){
            for( int j = i + 1 ; j < n ; ++j ){
                if( nums[i] == nums[j] ) cnt++;
            }
        }
        return cnt;
    }
};
