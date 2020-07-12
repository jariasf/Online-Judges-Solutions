/*******************************************
 ***Problema: Number of Substrings With Only 1s
 ***ID: 1513
 ***Juez: LeetCode
 ***Tipo: Ad hoc + Math
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    typedef long long LL;
    int MOD = 1e9+7;
    int numSub(string s) {
        int n = s.size();
        LL res = 0;
        for( int i = 0 ; i < n ; ++i ){
            if( s[i] == '1' ){
                int j = i + 1;
                while( j < n && s[j] == s[i] ){
                    j++;
                }
                LL l = j - i;
                l = l * (l + 1)/2;
                res = (res + l) % MOD;
                i = j - 1;
            }
        }
        return res % MOD;
    }
};
