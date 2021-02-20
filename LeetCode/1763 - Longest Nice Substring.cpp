/*******************************************
 ***Problema: Longest Nice Substring
 ***ID: 1763
 ***Juez: LeetCode
 ***Tipo: Brute Force + Hashing
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    string longestNiceSubstring(string s) {
        int n = s.size();
        string res = "";
        int maxi = 0;
        for( int i = 0 ; i < n ; ++i ){
            int up = 0, low = 0;
            string tmp = "";
            for( int j = i ; j < n ; ++j ){
                tmp += s[j];
                if( s[j] >= 'A' && s[j] <= 'Z') up |= 1<<(s[j] - 'A');
                else low |= 1<<(s[j] - 'a');
                if( up == low && maxi < tmp.size() ){
                    maxi = tmp.size();
                    res = tmp;
                }
            }
        }
        return res;
    }
};
