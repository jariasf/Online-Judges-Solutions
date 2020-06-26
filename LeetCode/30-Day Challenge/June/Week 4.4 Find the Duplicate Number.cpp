/*******************************************
 ***Problema: Find the Duplicate Number
 ***ID: Week4.4
 ***Juez: LeetCode
 ***Tipo: Floyd’s Cycle-Finding Algorithm
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int slow = 0, fast = 0;
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow != fast );
        
        slow = 0;
        while(slow != fast ){
            slow = nums[slow]; fast = nums[fast];
        }
        return slow;
    }
};
