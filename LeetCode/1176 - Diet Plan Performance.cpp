/*******************************************
 ***Problema: Diet Plan Performance
 ***ID: 1176
 ***Juez: LeetCode
 ***Tipo: Prefix Sums
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    typedef long long LL;
    int dietPlanPerformance(vector<int>& calories, int k, int lower, int upper) {
        int n = calories.size();
        int result = 0;
        vector<LL> sum(n + 5);
        for( int i = 1 ; i <= n ; ++i ){
            sum[i] = sum[i - 1] + calories[i - 1];
        }
        
        for( int i = 1 ; i + k - 1 <= n ; ++i ){
            if( sum[i + k - 1] - sum[i - 1] > upper ) result++;
            else if( sum[i + k - 1] - sum[i - 1] < lower ) result--;
        }
        return result;
    }
};
