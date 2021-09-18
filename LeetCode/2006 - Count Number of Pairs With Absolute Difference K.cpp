/*******************************************
 ***Problema: Count Number of Pairs With Absolute Difference K
 ***ID: 2006
 ***Juez: LeetCode
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int n = nums.size(), cnt = 0;
        for( int i = 0 ; i < n ; ++i ){
            for( int j = 0 ; j < i ; ++j ){
                if( abs(nums[j] - nums[i]) == k ) cnt++;
            }
        }
        return cnt;
    }
};
