/*******************************************
 ***Problema: Best Time to Buy and Sell Stock II
 ***ID: Week1.5
 ***Juez: LeetCode
 ***Tipo: Greedy
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sz = prices.size();
        int ans = 0;
        for( int i = 1 ; i < sz ; ++i ){
            if( prices[i] > prices[i - 1]){
                ans += prices[i] - prices[i - 1];
            }
        }
        return ans;
    }
};
