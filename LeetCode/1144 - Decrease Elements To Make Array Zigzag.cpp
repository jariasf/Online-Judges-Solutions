/*******************************************
 ***Problema: Decrease Elements To Make Array Zigzag
 ***ID: 1144
 ***Juez: LeetCode
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        int n = nums.size();
        if(n == 1 ) return 0;
        
        int res1 = 0, res2 = 0;
        nums.push_back(1<<30);
        for( int i = 1 ; i < n ; i += 2 ){
            res1 += max( nums[i] - min(nums[i - 1], nums[i + 1]) + 1, 0 );
        }
        
        res2 += max( nums[0] - nums[1] + 1, 0);
        for( int i = 2 ; i < n ; i += 2 ){
            res2 += max( nums[i] - min( nums[i - 1] , nums[i + 1] ) + 1, 0 );
        }
        
        return min(res1, res2);
    }
};
