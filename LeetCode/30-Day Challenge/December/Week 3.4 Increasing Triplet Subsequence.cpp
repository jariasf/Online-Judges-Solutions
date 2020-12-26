/*******************************************
 ***Problema: Increasing Triplet Subsequence
 ***ID: Week3.4
 ***Juez: LeetCode
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    //[5,4,3,2,1,2,2,2,2,2,2,1,1,1,1,4]
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        if( n < 3 ) return false;
        int i = 0;
        while( i + 1 < n && nums[i] >= nums[ i + 1 ] ){
            i++;
        }
        int first = i, second = i + 1;
        i = i + 2;
        while( i < n ){
            if( nums[i] > nums[second] ) return true;
            if( nums[i] < nums[second] && nums[i] > nums[first] ){
                second = i;
            }else if( nums[second] > nums[i]){
                while( i + 1 < n && nums[i] > nums[ i + 1 ] ){
                    i++;
                }
                if( i + 1 < n ){
                    if( nums[i + 1] > nums[second]) 
                        return true;
                    else if( nums[i + 1] < nums[second] ){
                        second = i + 1;
                        if( nums[first] > nums[i] )
                            first = i;
                    }
                }
                i++;
            }
            i++;
        }
        return false;
    }
};
