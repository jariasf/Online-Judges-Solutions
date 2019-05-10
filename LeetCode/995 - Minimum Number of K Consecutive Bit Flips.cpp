/******************************************************
 ***Problema: Minimum Number of K Consecutive Bit Flips
 ***ID: 995
 ***Juez: LeetCode
 ***Tipo: Greedy
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************************/

class Solution {
public:
    int minKBitFlips(vector<int>& A, int K) {
        int n = A.size();
        int result = 0;
        for( int i = 0 ; i <= n - K ; ++i ){
            if( A[i] == 0 ){
                for( int j = 0 ; j < K; ++j ){
                    A[i + j] = !A[i + j];
                }
                result++;
            }
        }
        
        for( int i = 0 ; i < n ; ++i ) if( A[i] == 0 ) return -1;
        return result;
    }
};
