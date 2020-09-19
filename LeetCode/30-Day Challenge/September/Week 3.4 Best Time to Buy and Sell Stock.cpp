/*******************************************
 ***Problema: Best Time to Buy and Sell Stock
 ***ID: Week3.4
 ***Juez: LeetCode
 ***Tipo: Ad hoc | DP
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxi = 0, mini = INT_MAX;
        for( int i = 0 ; i < prices.size() ; ++i ){
            if( prices[i] < mini ) mini = prices[i];
            else if( prices[i] > mini )
                maxi = max(maxi, prices[i] - mini);
        }
        return maxi;
    }
};
