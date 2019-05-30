/****************************************************
 ***Problema: Minimum Increment to Make Array Unique
 ***ID: 945
 ***Juez: LeetCode
 ***Tipo: Sroting
 ***Autor: Jhosimar George Arias Figueroa
 ****************************************************/

class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        sort(A.begin(), A.end());
        int n = A.size();
        int result = 0;
        for( int i = 1 ; i < n ; ++i ){
            if( A[i] <= A[i - 1]){
                result += A[i - 1] - A[i] + 1;
                A[i] = A[i - 1] + 1;
            }
        }
        return result;
    }
};
