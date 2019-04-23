/***********************************************************
 ***Problema: Maximum Sum of Two Non-Overlapping Subarrays
 ***ID: 1031
 ***Juez: LeetCode
 ***Tipo: Dynamic Programming, Prefix Sum
 ***Autor: Jhosimar George Arias Figueroa
 **********************************************************/

class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        int n = A.size();
        vector<int> sum(n + 1);
        for( int i = 1 ; i <= n ; ++i ){
            if( i ){
                sum[i] = sum[i - 1] + A[i - 1];
            }else
                sum[i] = A[i];
        }

        int maxi = 0;
        for( int i = L ; i <= n ; ++i ){
            for( int j = M; j <= i - L; ++j ){
                maxi = max( maxi, sum[i] - sum[i - L] + sum[j] - sum[j - M]);
            }

            for( int j = i + M; j <= n ; ++j ){
                maxi = max( maxi, sum[i] - sum[i - L] + sum[j] - sum[j - M]);
            }
        }
        return maxi;
    }
};
