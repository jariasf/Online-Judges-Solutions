/*******************************************
 ***Problema: Flip String to Monotone Increasing
 ***ID: 926
 ***Juez: LeetCode
 ***Tipo: Prefix Sums
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int minFlipsMonoIncr(string S) {
        int n = S.size();
        
        vector<int> zeros(n);
        for( int i = n - 1 ; i >= 0  ; --i ){
            if( S[i] == '0' ){
                if( i == n - 1 ) zeros[i] = 1;
                else zeros[i] = zeros[i + 1] + 1;
            }else{
                if( i + 1 < n )
                    zeros[i] = zeros[i + 1];
            }
        }
        
        int result = zeros[0];
        int sum = 0;
        for( int i = 0 ;i < n ; ++i ){
            if( S[i] == '1' ) sum++;
            if( i + 1 < n )
                result = min( result, sum + zeros[i + 1]);
            else
                result = min( result, sum);
        }
        return result;
    }
};
