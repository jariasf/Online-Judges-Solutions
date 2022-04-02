/*******************************************
 ***Problema: Number of Ways to Select Buildings
 ***ID: 2222
 ***Juez: LeetCode
 ***Tipo: Prefix count - DP
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    typedef long long LL;
    long long numberOfWays(string s) {
        LL ones = 0, zeros = 0, res = 0, last_ones = 0, last_zeros = 0;
        for(char c:s ){
            if( c == '1' ){
                res += last_ones;
                ones++;
                last_zeros += zeros;
            }
            else{
                res += last_zeros;
                zeros++;
                last_ones += ones;
            }
        }
        
        return res;
    }
};

/*
//DP Solution
long long dp[100001][3][4]; 
class Solution {
public:
    #define NONE 2
    typedef long long LL;
    string s;
    LL solve(int pos, int last, int cnt){
        if( pos == s.size() ){
            if(cnt == 0){
                return 1;
            }else
                return 0;
        }

        if( cnt < 0 ) return 0;
        if( dp[pos][last][cnt] != -1 ) return dp[pos][last][cnt];
        
        LL res = solve(pos + 1, last, cnt);
        if( s[pos] - '0' != last ){
            res += solve(pos + 1, s[pos] - '0', cnt - 1);
        }
        
        return dp[pos][last][cnt] = res;
    }
    
    long long numberOfWays(string _s) {
        s = _s;
        memset(dp, -1, sizeof(dp));
        return solve(0, NONE, 3);
    }
};*/
