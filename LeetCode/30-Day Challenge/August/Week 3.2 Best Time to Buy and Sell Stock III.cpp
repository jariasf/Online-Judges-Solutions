/*******************************************
 ***Problema: Best Time to Buy and Sell Stock III
 ***ID: Week3.2
 ***Juez: LeetCode
 ***Tipo: Dynamic Programming
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:   
    int buy[2], sell[2];
    int maxProfit(vector<int>& prices) {
        int sz = prices.size();
        buy[0] = buy[1] = INT_MIN;
        sell[0] = sell[1] = 0;
        for( int i = 0 ; i < sz ; ++i ){
            buy[0] = max(buy[0], -prices[i]);
            sell[0] = max( sell[0], buy[0] + prices[i]);
            buy[1] = max( buy[1], sell[0] - prices[i]);
            sell[1] = max( sell[1] , buy[1] + prices[i]);
        }
        return sell[1];
    }
};
