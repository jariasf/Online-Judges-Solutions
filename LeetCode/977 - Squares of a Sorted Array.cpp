/*******************************************
 ***Problema: Squares of a Sorted Array
 ***ID: 977
 ***Juez: LeetCode
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        for( int i = 0 ; i < A.size(); ++i ) A[i] = A[i] * A[i];
        sort(A.begin(), A.end());
        return A;
    }
};
