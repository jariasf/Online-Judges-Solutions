/*******************************************
 ***Problema: Jump Game II
 ***ID: Week 2.1
 ***Juez: LeetCode
 ***Tipo: Greedy
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/


class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size(), steps = 0, next_reach = 0;
        for( int i = 0, reach = 0 ; i < n - 1 && i <= reach  ; ++i ){
            next_reach = max(next_reach, nums[i] + i);  
            if( i == reach ){
                steps++;
                reach = next_reach;
            }
        }
        return steps;
    }
};
