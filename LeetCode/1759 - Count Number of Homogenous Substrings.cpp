/*******************************************
 ***Problema: Count Number of Homogenous Substrings
 ***ID: 1759
 ***Juez: LeetCode
 ***Tipo: Math
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int MOD = 1e9+7;
    int countHomogenous(string s) {
        int n = s.size();
        long long res = 0;
        for( int i = 0 ; i < n ; ++i ){
            int j = i + 1;
            long long cnt = 1;
            while(j < n && s[i] == s[j] ){
                cnt++;
                j++;
            }
            res += cnt * (cnt + 1)/2;
            res %= MOD;
            i = j - 1;
        }
        return res;
    }
};
