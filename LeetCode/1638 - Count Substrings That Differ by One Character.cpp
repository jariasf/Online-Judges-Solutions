/*******************************************
 ***Problema: Count Substrings That Differ by One Character
 ***ID: 1638
 ***Juez: LeetCode
 ***Tipo: Brute Force
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int countSubstrings(string s, string t) {
        int res = 0;
        for( int i = 0 ; i < s.size(); ++i ){
            for( int j = 0 ; j < t.size(); ++j ){
                int l = min(s.size() - i, t.size() - j);
                bool dif = 0;
                for( int k = 0 ; k < l ; ++k ){
                    if( s[i + k] == t[j + k] ){
                        if( dif )
                            res++;    
                    }else if( !dif ){
                        dif = 1;
                        res++;
                    }else
                        break;
                }
            }
        }
        return res;
    }
};
