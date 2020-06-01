/*******************************************
 ***Problema: Maximum Area of a Piece of Cake After Horizontal and Vertical Cuts
 ***ID: 1465
 ***Juez: LeetCode
 ***Tipo: Sorting
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    typedef long long LL;
    int MOD = 1e9+7;
    int maxArea(int h, int w, vector<int>& hor, vector<int>& ver) {
        ver.push_back(0); ver.push_back(w);
        hor.push_back(0); hor.push_back(h);
        sort(hor.begin(), hor.end());
        sort(ver.begin(), ver.end());
        LL max_dif_hor = 0, max_dif_ver = 0;
        for( int i = 1 ; i < hor.size(); ++i )
            max_dif_hor = max( max_dif_hor, (LL)hor[i] - (LL)hor[i - 1]);
        
        for( int i = 1 ; i < ver.size(); ++i )
            max_dif_ver = max( max_dif_ver, (LL)ver[i] - (LL)ver[i - 1]);
        return (max_dif_hor * max_dif_ver) % MOD;
    }
};
