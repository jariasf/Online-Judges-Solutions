/*******************************************
 ***Problema: Ways to Make a Fair Array
 ***ID: 1664
 ***Juez: LeetCode
 ***Tipo: Prefix Sums
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n = nums.size();
        vector<int> odd(n + 1), even(n + 1);
        for( int i = 1 ; i <= n ; ++i ){
            if( i & 1 ){
                even[i] = even[i - 1] + nums[i - 1];            
                odd[i] = odd[i - 1];
            }else{
                odd[i] = odd[i - 1] + nums[i - 1];
                even[i] = even[i - 1];
            }
        }
        int res = 0;
        for( int i = 1 ; i <= n ; ++i ){
            if( even[i - 1] + odd[n] - odd[i] == odd[i - 1] + even[n] - even[i])
                res++;
        }
        
        return res;
    }
};
