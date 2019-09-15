/*******************************************
 ***Problema: K-Concatenation Maximum Sum
 ***ID: 1191
 ***Juez: LeetCode
 ***Tipo: Prefix and Suffix Sums
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    typedef long long LL;
    #define MOD 1000000007
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        int n = arr.size();
        LL best = arr[0];
        LL sum = 0;    
        for( int i = 0 ; i<  n ; ++i ){
            sum += arr[i];
            if( sum < 0) sum = 0;
            else if( sum > best ) best = sum;
        }

        LL max_prefix = 0, max_suffix = 0;
        sum = 0;
        for( int i = 0 ; i < n ; ++i ){
            sum += arr[i];
            max_prefix = max( max_prefix, sum );
        }
        LL all_sum = sum;
        sum = 0;
        for( int i = n - 1 ; i >= 0 ; --i ){
            sum += arr[i];
            max_suffix = max( max_suffix, sum);
        }
        if(k > 1){
            best = max( best , max_prefix + max_suffix);
            best = max( best , max_prefix + max_suffix + (k - 2)* all_sum  );
        }
        return best % MOD;
    }
};
