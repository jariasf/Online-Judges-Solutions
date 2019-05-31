/*******************************************
 ***Problema: Delete Columns to Make Sorted
 ***ID: 944
 ***Juez: LeetCode
 ***Tipo: Greedy
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int h = A.size();
        int w = A[0].size();
        int result = 0;
        for( int i = 0 ; i < w ; ++i ){
            for( int j = 1 ; j < h ; ++j ){
                if( A[j][i] < A[j - 1][i] ){
                    result++;
                    break;
                }
            }
        }
        return result;
    }
};
