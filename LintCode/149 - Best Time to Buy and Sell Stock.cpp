/*******************************************
 ***Problema: Best Time to Buy and Sell Stock
 ***ID: 149
 ***Juez: LintCode
 ***Tipo: One Pass
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        int min_left = INT_MAX, max_profit = 0;
        for( int price: prices ){
            min_left = min(min_left, price);
            max_profit = max(max_profit, price - min_left);            
        }
        return max_profit;
    }
};
