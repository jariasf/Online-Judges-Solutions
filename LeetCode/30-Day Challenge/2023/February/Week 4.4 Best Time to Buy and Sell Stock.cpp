/*******************************************
 ***Problema: Best Time to Buy and Sell Stock
 ***ID: Week 4.4
 ***Juez: LeetCode
 ***Tipo: DP
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0], res = 0;
        for(int price:prices){
            res = max(res, price - mini);
            mini = min(mini, price);
        }
        return res;
    }
};
