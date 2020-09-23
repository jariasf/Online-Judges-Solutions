/*******************************************
 ***Problema: Majority Element II
 ***ID: Week4.1
 ***Juez: LeetCode
 ***Tipo: Boyer-Moore Majority Vote
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

// Time: O(n), Space: O(1)
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cnt1 = 0, cnt2 = 0, num1 = 0, num2 = 1;
        for(int val:nums ){
            if( num1 == val ) cnt1++;
            else if(num2 == val ) cnt2++;
            else if( cnt1 == 0 ){
                num1 = val; cnt1 = 1;
            }else if( cnt2 == 0 ){
                num2 = val; cnt2 = 1;
            }else{
                cnt1--; cnt2--;
            }
        }
        
        cnt1 = cnt2 = 0;
        vector<int> res;
        
        for( int val:nums ){
            if( val == num1 ) cnt1++;
            else if( val == num2 ) cnt2++;
        }
        if( cnt1 > n/3 ) res.push_back(num1);
        if( cnt2 > n/3 ) res.push_back(num2);
        return res;
    }
};
