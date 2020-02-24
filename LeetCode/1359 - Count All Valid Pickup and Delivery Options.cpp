/*******************************************
 ***Problem: Count All Valid Pickup and Delivery Options
 ***ID: 1359
 ***Judge: LeetCode
 ***Type: Math
 ***Author: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int MOD = 1e9+7;
    int countOrders(int n) {
        long long tot = 1;
        for( int i = 1; i <= n; ++i ){
            tot = tot *  (2 * i - 1) * i % MOD;
        }
        return tot;
    }
};
