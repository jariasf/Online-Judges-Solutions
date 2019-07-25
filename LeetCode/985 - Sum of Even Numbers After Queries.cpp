/*******************************************
 ***Problema: Sum of Even Numbers After Queries
 ***ID: 985
 ***Juez: LeetCode
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        int even_sum = 0;
        vector<int> result( queries.size(), 0);
        
        //Initialize
        for( int i = 0 ; i < A.size(); ++i ){
            if( A[i] % 2 == 0 )
                even_sum += A[i];
        }
        
        //Queries
        for( int i = 0 ; i < queries.size(); ++i ){
            int index = queries[i][1], value = queries[i][0];
            if( A[index] % 2 == 0 ){
                even_sum -= A[index];
            }
            
            A[ index ] += value;
            
            if( A[index] % 2 == 0 ){
                even_sum += A[index];
            }
            
            result[i] = even_sum;
        }
        
        return result;        
    }
};
