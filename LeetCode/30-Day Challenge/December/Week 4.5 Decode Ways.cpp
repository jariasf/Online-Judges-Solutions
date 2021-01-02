/*******************************************
 ***Problema: Decode Ways
 ***ID: Week4.5
 ***Juez: LeetCode
 ***Tipo: Dynamic Programming
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    vector<int> dp;
    int solve(string &s, int pos ){
        int size = s.size();
        if( pos == size ) return 1;
        if( dp[pos] != -1 ) return dp[pos];
        int quantity = 0;
        int value = s[ pos ] - '0';
        if( value > 0 ){
            quantity = solve(s, pos + 1);
            if( pos + 1 < size ){
                value = value * 10 + s[ pos + 1 ] - '0';
                if( value > 0 && value <= 26 )
                    quantity += solve(s, pos + 2 );
            }
        }
        return dp[pos] = quantity;
    }
    

    int numDecodings(string s) {
        if( s.size() == 0 ) return 0;
        dp = vector<int> (s.size(), -1 );
        return solve(s, 0 );
    }
};
