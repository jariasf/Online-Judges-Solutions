/*******************************************
 ***Problem: Lucky Numbers in a Matrix
 ***ID: 1380
 ***Judge: LeetCode
 ***Type: Simulation
 ***Author: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int h = matrix.size(), w = matrix[0].size();
        vector<int> mini(h, INT_MAX), maxi(w, INT_MIN);
        for( int i = 0 ; i < h ; ++i ){
            for( int j = 0 ; j < w ; ++j ){
                mini[i] = min(mini[i], matrix[i][j]);
                maxi[j] = max(maxi[j], matrix[i][j]);
            }
        }
        vector<int> res;
        for( int i = 0 ; i < h ; ++i ){
            for( int j = 0 ; j < w ; ++j ){
                if( matrix[i][j] == mini[i] && matrix[i][j] == maxi[j] ){
                    res.push_back(matrix[i][j]);
                }
            }
        }
        return res;
    }
};
