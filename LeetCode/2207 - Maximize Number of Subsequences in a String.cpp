/*******************************************
 ***Problema: Maximize Number of Subsequences in a String
 ***ID: 2207
 ***Juez: LeetCode
 ***Tipo: DP
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    typedef long long LL;

    long long maximumSubsequenceCount(string text, string pattern) {
        LL res = 0, left = 0, right = 0;
        int cnt = 0;
        for(char c: text){
            if( c == pattern[1] ){
                left += cnt + 1;
                right += cnt;
            }
            cnt += ( c == pattern[0]);
        }
        right += cnt;
        res = max(left, right);
        return res;
    }
};
