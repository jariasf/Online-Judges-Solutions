/*******************************************
 ***Problem: Check If All 1's Are at Least Length K Places Away
 ***ID: 1437
 ***Judge: LeetCode
 ***Type: Ad hoc
 ***Author: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n = nums.size(), lastOne = -1;
        for( int i = 0 ; i < n ; ++i ){
            if( nums[i] == 1 ){
                if( lastOne != -1 && i - lastOne - 1 < k ) 
                    return false;
                lastOne = i;
            }
        }
        return true;
    }
};
