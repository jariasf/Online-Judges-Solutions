/*******************************************
 ***Problema: Find the Smallest Divisor Given a Threshold
 ***ID: Week1.6
 ***Juez: LeetCode
 ***Tipo: Binary Search The Answer
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int left = 1, right = 1000005;
        while( left < right){
            int mid = (left + right)/2;
            int sum = 0;
            for(int val:nums) sum += (int)ceil(val/(double)(mid));
            if( sum > threshold ){
                left = mid + 1;
            }else
                right = mid;
        }
        return right;
    }
};
