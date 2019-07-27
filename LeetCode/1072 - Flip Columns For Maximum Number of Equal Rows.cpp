/*******************************************
 ***Problema: Flip Columns For Maximum Number of Equal Rows
 ***ID: 1072
 ***Juez: LeetCode
 ***Tipo: Hashing
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        map< vector<int>, int > hash;
        for( int i = 0 ; i < matrix.size(); ++i ){
            hash[ matrix[i] ]++;
            for( int j = 0 ; j < matrix[i].size(); ++j ){
                matrix[i][j] = !matrix[i][j];
            }
            hash[ matrix[i] ]++;
        }

        int result = 0;
        for( auto it: hash ){
            result = max( result, it.second);
        }
        return result;
    }   
};
