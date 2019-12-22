/*******************************************
 ***Problema: Find Numbers with Even Number of Digits
 ***ID: 1295
 ***Juez: LeetCode
 ***Tipo: Simulation
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        for( int i = 0 ; i < n ; ++i ){
            string s = to_string(nums[i]);
            if( s.size() & 1 ) continue;
            cnt++;
        }
        return cnt;
    }
};
