/*******************************************
 ***Problema: Max Sum of Rectangle No Larger Than K
 ***ID: 1278
 ***Juez: LintCode
 ***Tipo: Dynamic Programming
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    /**
     * @param matrix: a 2D matrix
     * @param k: an integer
     * @return: the max sum of a rectangle in the matrix such that its sum is no larger than k
     */
    int maxSumVector(vector<int> &array, int k){
        int prefix_sum = 0;
        int max_sum = INT_MIN;
        set<int> hash;
        set<int>::iterator it;
        hash.insert(0);
        for( int i = 0 ; i < array.size(); ++i ){
            prefix_sum += array[i];
            int search = prefix_sum - k;
            it = hash.lower_bound(search);
            if( it != hash.end() ){
                int sum = prefix_sum - *it;
                max_sum = max(max_sum, sum);
            }
            hash.insert(prefix_sum);
        }
        return max_sum;
    }
     
    int maxSumSubmatrix(vector<vector<int>> &matrix, int k) {
        int h = matrix.size();
        int w = matrix[0].size();
        int max_sum = INT_MIN;
        for( int i = 0 ; i < w ; ++i ){
            vector<int> prefix_sum(h);
            for( int j = i ; j < w ; ++j ){
                for( int k = 0 ; k < h ; ++k ){
                    prefix_sum[k] += matrix[k][j];
                }
                int current_sum = maxSumVector(prefix_sum, k);
                if( current_sum == k )
                    return k;
                if( current_sum > max_sum )
                    max_sum = current_sum;
            }
        }
        return max_sum;
    }
};
