/*******************************************
 ***Problema: Maximum Sum Circular Subarray
 ***ID: Week3.1
 ***Juez: LeetCode
 ***Tipo: Kadane 1D
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:

    int kadane(vector<int> &A, int left, int right ){
        int sum = 0, maxi = INT_MIN;
        for( int i = left; i < right ; ++i ){
            if( sum < 0 ) sum = 0;
            sum += A[i];
            maxi = max( maxi, sum);
        }
        return maxi;
    }

    int maxSubarraySumCircular(vector<int>& A) {
        int n = A.size();
        int maxi = kadane(A, 0, n);
        if( maxi < 0 ) return maxi;
        int tot = 0;
        for( int i = 0 ; i < n ; ++i ){
            tot += A[i];
            A[i] = -A[i];
        }
        return max(maxi, tot + kadane(A, 0, n));
    }
};
