/*******************************************
 ***Problema: Minimum Operations to Halve Array Sum
 ***ID: 2207
 ***Juez: LeetCode
 ***Tipo: Greedy – Priority Queue
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int halveArray(vector<int>& nums) {
        int n = nums.size();
        priority_queue<double> Q;
        
        double s=  0;
        for( int val: nums){
            Q.push(val);
            s += val;
        }
        
        double desired = s/2.0;
        
        int res = 0;
        while( !Q.empty() && desired < s ){
            double v = Q.top(); Q.pop();
            s -= v/2.0;
            Q.push(v/2.0);
            res++;
        }
        return res;
        
    }
};
