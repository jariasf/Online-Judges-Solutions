/*******************************************
 ***Problema: Count Square Submatrices with All Ones
 ***ID: 1277
 ***Juez: LeetCode
 ***Tipo: Dynamic Programming
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int h = matrix.size(), w = matrix[0].size();
        for( int i = 1 ; i < h ; ++i ){
            for( int j = 1 ; j < w ; ++j ){
                if( matrix[i][j] > 0 && matrix[i - 1][j - 1] > 0 && matrix[ i - 1 ][j] > 0 && matrix[i][j - 1] > 0 ){
                    matrix[i][j] = 1 + min( matrix[i - 1][j - 1], min(matrix[i - 1][j], matrix[i][j - 1]));
                }
            }
        }
        int res = 0;
        for( int i = 0 ; i < h ; ++i ){
            for( int j = 0 ; j < w ; ++j ){
                res += matrix[i][j];
            }
        }
        return res;
    }
};
