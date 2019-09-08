/*******************************************
 ***Problema: Maximum Subarray Sum with One Deletion
 ***ID: 1186
 ***Juez: LeetCode
 ***Tipo: Dynamic Programming - Kadane 1D
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        int sum = 0, maxi = arr[0];
        for( int i = 0 ; i < n ; ++i ){
            sum += arr[i];
            if( sum > maxi )
                maxi = sum;
            
            if( sum < 0 )
                sum = 0;
        }
        
        vector<int> sums(n + 5), sums_inv(n + 5);
        for( int i = 1 ; i <= n ; ++i ){
            sums[i] = sums[i - 1] + arr[i - 1];
        }
        
        
        for( int i = n ; i >= 1 ; --i ){
            sums_inv[i] = sums_inv[i + 1] + arr[i - 1]; 
        }
        
        vector<int> max_left(n + 5, - (1<<30)), max_right(n + 5, - (1<<30));
        for( int i = 1 ; i <= n ; ++i ){
            max_left[i] = max(max_left[i - 1], sums_inv[i]);
        }
        
        for( int i = n ; i >= 1 ; --i ){
            max_right[i] = max( max_right[i + 1], sums[i]);
        }
        
        for( int i = 1 ; i <= n ; ++i ){
            if( i == 1 ){
                maxi = max( maxi, max_right[i + 1] - sums[i]);
            }else if( i == n ){
                maxi = max( maxi, max_left[i - 1] - sums_inv[i]);
            }else
                maxi = max( maxi, max_left[i - 1] - sums_inv[i] + max_right[ i + 1] - sums[i] );
        }
        
        return maxi;
    }
};
