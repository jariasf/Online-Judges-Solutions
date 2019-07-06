/*******************************************
 ***Problema: Maximum Sum Circular Subarray
 ***ID: 918
 ***Juez: LeetCode
 ***Tipo: Kadane's Algorithm
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int kadane(vector<int> &A){
        int sum = 0;
        int n = A.size();
        int maxi = A[0];
        for( int i = 0 ; i < n ; ++i ){
            sum += A[i];
            if( sum > maxi ){
                maxi = sum;
            }
            if( sum < 0 ){
                sum = 0;
            }
        }
        return maxi;
    }
    
    int maxSubarraySumCircular(vector<int>& A) {      
        int maxi = kadane(A);
        bool all_neg = true;
        for( int i = 0 ; i < A.size(); ++i ){
            if( A[i] > 0 ){
                all_neg = false;
                break;
            }
        }
        
        if( all_neg ) return maxi;
        
        int sum = 0;
        for( int i = 0 ; i < A.size(); ++i ){
            sum += A[i];
            A[i] *= -1;
        }
        
        sum += kadane(A);
        return max( maxi, sum );
    }
};
