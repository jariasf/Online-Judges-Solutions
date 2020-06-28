/*******************************************
 ***Problema: Max Value of Equation
 ***ID: 1499
 ***Juez: LeetCode
 ***Tipo: Deque
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    #define pii pair<int,int>
    #define mp make_pair
    int findMaxValueOfEquation(vector<vector<int>>& p, int k) {
        p.push_back({p[p.size() - 1][0] + k + 1, 0});
        int n = p.size();
        deque<pii> S;
        int i = 0, maxi = -(1<<30), left = 0;
        for( ; i< n ; ++i ){
            while( !S.empty() && S.front().second <= left )
                S.pop_front();
            
            if( p[i][0] - p[left][0] <= k ){
                int sum = p[i][0] + p[i][1];
                while( !S.empty() && S.back().first <= sum )
                    S.pop_back();
                
                S.push_back(mp(sum, i));
            }else{
                int dif = p[left][1] - p[left][0];
                maxi = max( maxi, dif + S.front().first);
                left++;
                i--;
            }
        }
        return maxi;
    }
};
