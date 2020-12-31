/*******************************************
 ***Problema: Smallest Range II
 ***ID: Week3.7
 ***Juez: LeetCode
 ***Tipo: Dynamic Programming
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int smallestRangeII(vector<int>& A, int K) {
        sort(A.begin(), A.end());
        int n = A.size();
        int res = A[n - 1] - A[0], maxi = A[n - 1], mini = A[0];
        for( int i = 0 ; i < n - 1 ; ++i ){
            maxi = max(maxi, A[i] + 2 * K);
            mini = min(A[i + 1], A[0] + 2 * K);
            res = min(res, maxi - mini);
        }
        return res;
    }
};
