/*******************************************
 ***Problema: Sparse Matrix Multiplication
 ***ID: 654
 ***Juez: LintCode
 ***Tipo: Ad hoc - compress matrices and multiply
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    /**
     * @param A: a sparse matrix
     * @param B: a sparse matrix
     * @return: the result of A * B
     */

    vector<vector<int> > reduce(vector<vector<int> > &A ){
        int n = A.size(), p = A[0].size();
        vector<vector<int> > A_reduced(n);
        for(int i = 0 ; i < n ; ++i ){
            for( int j = 0 ; j < p; ++j ){
                if( A[i][j] != 0 ) 
                    A_reduced[i].push_back(j);
            }
        }
        return A_reduced;
    }

    vector<vector<int>> multiply(vector<vector<int>> &A, vector<vector<int>> &B) {
        int n = A.size(), p = A[0].size(), m = B[0].size();
        vector<vector<int> > A_reduced = reduce(A), B_reduced = reduce(B);
        vector<vector<int> > result(n, vector<int>(m));
        for( int A_row = 0 ; A_row < n ; ++A_row ){
            for( int j = 0 ; j < A_reduced[A_row].size() ; ++j ){
                int A_col = A_reduced[A_row][j]; //B_row = A_col
                for( int k = 0 ; k < B_reduced[A_col].size(); ++k ){
                    int B_col = B_reduced[A_col][k];
                    result[A_row][B_col] += A[A_row][A_col] * B[A_col][B_col];
                }
            }
        }
        return result;
    }
};

