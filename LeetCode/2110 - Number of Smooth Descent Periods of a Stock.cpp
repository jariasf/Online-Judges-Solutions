/*******************************************
 ***Problema: Number of Smooth Descent Periods of a Stock
 ***ID: 2110
 ***Juez: LeetCode
 ***Tipo: Math
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    typedef long long LL;
    LL getDescentPeriods(vector<int>& prices) {
        int n = prices.size();
        LL res = 0;
        for( int i = 0 ; i < n ; ++i ){
            int j = i + 1;
            LL cnt = 1;
            while( j < n && prices[j] + 1 == prices[j - 1]){
                j++;
                cnt++;
            }
            res += cnt * (cnt +1)/2;
            i = j - 1;
        }
        return res;
    }
};
