/*******************************************
 ***Problema: Minimum Limit of Balls in a Bag
 ***ID: 1760
 ***Juez: LeetCode
 ***Tipo: Binary Search The Answer
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    bool possible(vector<int> &nums, int op, int maxi ){
        for( int i = 0 ; i < nums.size(); ++i ){
            if( nums[i] <= maxi ) continue;
            if( op <= 0 ) return false;
            int div = nums[i]/maxi;
            int rem = nums[i] % maxi;
            int tot = div;
            if( rem > 0 ) tot++;
            op  = op - (tot - 1);
        }
        return op >= 0;
    }
    
    int minimumSize(vector<int>& nums, int maxOperations) {
        int left = 1, right = 1e9 + 5;
        int res = 0;        
        while( left < right){
            int mid = (left + right)/2;
            if( possible(nums, maxOperations, mid)){
                right = mid;
                res = right;
            }else
                left = mid + 1;
        }
        return res;
    }
};
