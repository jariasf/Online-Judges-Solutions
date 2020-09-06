/*******************************************
 ***Problema: Minimum Deletion Cost to Avoid Repeating Letters
 ***ID: 1578
 ***Juez: LeetCode
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int minCost(string s, vector<int>& cost) {
        int n = s.size();
        int res = 0;
        for( int i = 0 ; i < n ; ++i ){
            int j = i + 1, cnt = 1, sum = cost[i], maxi = cost[i];
            while( j < n && s[j] == s[j - 1] ){
                cnt++;
                sum += cost[j];
                maxi = max( maxi, cost[j]);
                j++;
            }
            res += sum - maxi;
            i = j - 1;
        }
        return res;
    }
};
