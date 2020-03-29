/*******************************************
 ***Problem: Find All Good Strings
 ***ID: 1397
 ***Judge: LeetCode
 ***Type: DP + KMP
 ***Author: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    typedef long long LL;
    int MOD = 1e9+7;
    string s;
    string e;
    int N;
    
    vector<int> b;
    void preprocess(string &s){
        int i = 0, j = -1; 
        int n = s.size();
        b = vector<int>(n + 1, 0);
        b[ 0 ] = -1;
        while( i < n ){
            while( j >= 0 && s[ i ] != s[ j ] ) j = b[ j ];
            i++; j++;
            b[ i ] = j;
        }
    } 
    
    int dp[505][55][2];
    LL solve(int pos, int pos_e, bool flag){
        if( pos_e == e.size() ) 
            return 0;
        
        if( pos == N )
            return 1;
        
        if( dp[pos][pos_e][flag] != -1 ) return dp[pos][pos_e][flag];
        
        int maxDigit = s[pos];
        if(flag) maxDigit = 'z';
        int res = 0;
        for( int i = 'a' ; i <= maxDigit; ++i ){
            bool new_flag = flag | ( ( i < s[pos] )?1:0 );
            //kmp
            int j = pos_e;
            while( j >= 0 && i != e[j] ) j = b[j];
            j++;
            res = ( res + solve(pos + 1, j, new_flag) % MOD ) % MOD;
        }
        return dp[pos][pos_e][flag] = res % MOD;
    }

    int findGoodStrings(int n, string s1, string s2, string evil) {
        N = n;
        e = evil;
        s = s1;
        preprocess(evil);
        memset(dp, -1, sizeof(dp));
        int low = solve(0, 0, 0);
        
        s = s2;
        memset(dp, -1, sizeof(dp));
        int high = solve(0, 0, 0);

        // Count s1 string if valid
        int i = 0, j = 0, ini = 1;
        while(i < s1.size()){
            while(j >= 0 && e[j] != s1[i] ) j=b[j];
            i++; j++;
            if(j == e.size()){
                ini = 0;
                break;
            }
        }
        
        return (high - low + ini + MOD) % MOD;
        
    }    
};
