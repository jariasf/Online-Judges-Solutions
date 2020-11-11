/*******************************************
 ***Problema: Flipping an Image
 ***ID: Week2.3
 ***Juez: LeetCode
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int h = A.size();
        int w = A[0].size();
        for( int i  = 0 ; i < h ; ++i ){
            for( int j = 0 ; j < w/2 ; ++j ){
                swap( A[i][j], A[i][ w - j - 1 ]);
            }
            for( int j = 0 ; j < w ; ++j ){
                if( A[i][j] == 0 ) A[i][j] = 1;
                else A[i][j] = 0;
            }
        }
        return A;
    }
};
