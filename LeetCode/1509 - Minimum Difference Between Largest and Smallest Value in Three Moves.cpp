/*******************************************
 ***Problema: Minimum Difference Between Largest and Smallest Value in Three Moves
 ***ID: 1509
 ***Juez: LeetCode
 ***Tipo: Greedy
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int minDifference(vector<int>& nums) {
        if( nums.size() <= 4 ) return 0;
        sort( nums.begin(), nums.end() );
        int mini = 2e9;
        for( int i = 0 ; i < 4 ; ++i )
            mini = min( mini, nums[nums.size() - 4 + i] - nums[i] );
        return mini;
    }
};
