/*******************************************
 ***Problema: Palindrome Partitioning
 ***ID: Week3.1
 ***Juez: LeetCode
 ***Tipo: Sorting
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
