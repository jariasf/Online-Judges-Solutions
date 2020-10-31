/*******************************************
 ***Problema: Widest Vertical Area Between Two Points Containing No Points
 ***ID: 1637
 ***Juez: LeetCode
 ***Tipo: Sorting
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& p) {
        int n = p.size();
        sort(p.begin(), p.end());
        int maxi = 0;
        for( int i = 0 ; i < n - 1 ; ++i ){
            maxi = max( maxi, p[i + 1][0] - p[i][0]);
        }
        return maxi;
    }
};
