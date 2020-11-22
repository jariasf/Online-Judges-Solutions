/*******************************************
 ***Problema: Numbers At Most N Given Digit Set
 ***ID: Week3.7
 ***Juez: LeetCode
 ***Tipo: Dynamic Programming
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    
    vector<int> d;
    vector<int> digits;
    
    void getDigits(int n){
        digits.clear();
        while(n){
            digits.push_back(n % 10);
            n /= 10;
        }
        reverse(digits.begin(), digits.end());
    }

    #define MAX 15
    int dp[MAX][2][2];
    int solve(int pos, bool flag, bool zero_init){
        
        if( pos == digits.size() )
            return !zero_init;
        
        if( dp[pos][flag][zero_init] != -1 ) return dp[pos][flag][zero_init];
        int limit = 9;
        if( flag ){
            limit = digits[pos];
        }
        int init = 1;
        if( zero_init ) init = 0;
        
        int result = 0;
        for( int i = init ; i < d.size(); ++i ){
            if( d[i] <= limit ){
                result += solve(pos + 1, flag & (d[i] == limit), zero_init & (d[i] == 0) );
            }
        }
        return dp[pos][flag][zero_init] = result;
    }
    
    int atMostNGivenDigitSet(vector<string>& D, int N) {
        d.clear();
        d.push_back(0);
        for( int i = 0 ; i < D.size(); ++i )
            d.push_back( D[i][0] - '0');
        getDigits(N);
        memset(dp, -1, sizeof(dp));
        return solve(0, 1, 1);
    }
};
