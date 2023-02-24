/*******************************************
 ***Problema: Minimize Deviation in Array
 ***ID: Week 4.3
 ***Juez: LeetCode
 ***Tipo: Priority queue
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int n = nums.size();
        int mini = INT_MAX;
        priority_queue<int> Q;
        for(int i = 0 ; i < n ; ++i){
            while(nums[i] % 2 != 0) nums[i] *= 2;
            mini = min(mini, nums[i]);
            Q.push(nums[i]);
        }

        int res = Q.top() - mini;
        while(!Q.empty() ){
            int val = Q.top();
            res = min(res, val - mini);
            if( val % 2 != 0 ) break;
            val /= 2;
            if( val < mini )
                mini = val;
            Q.pop();
            Q.push(val);
        }
        return res;
    }
};
