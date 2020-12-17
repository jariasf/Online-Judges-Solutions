/*******************************************
 ***Problema: Remove Duplicates from Sorted Array II
 ***ID: Week2.4
 ***Juez: LeetCode
 ***Tipo: Two Pointers
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n= nums.size();
        if( n == 0 ) return 0;
        int left = 1;
        bool considered = false;
        for( int i = 0 ; i < n - 1 ; ++i ){
            if( nums[i] == nums[i + 1 ] ){
                if( !considered ){
                    nums[left++] = nums[i + 1];
                    considered = true;
                }
            }else{
                considered = false;
                nums[left++] = nums[i + 1];
            }
        }
        return left;
    }
};
