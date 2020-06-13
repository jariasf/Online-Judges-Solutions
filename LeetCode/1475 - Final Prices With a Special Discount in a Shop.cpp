/*******************************************
 ***Problema: Final Prices With a Special Discount in a Shop
 ***ID: 1475
 ***Juez: LeetCode
 ***Tipo: Brute Force
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        for( int i = 0 ; i < n ; ++i ){
            for( int j = i + 1 ; j < n ; ++j ){
                if( prices[j] <= prices[i] ){
                    prices[i] -= prices[j];
                    break;
                }
            }
        }
        return prices;
    }
};
